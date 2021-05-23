#include <memory>
#include <string>
#include <fstream>

#include <iostream>

#include "logging.hpp"
#include "helpers.hpp"
#include "smreader.hpp"

enum ChartParsing {
    CHART_TYPE_PARSING = 0,
    CHART_STEP_ARTIST_PARSING = 1,
    CHART_DIFFICULTY_PARSING = 2,
    CHART_RATING_PARSING = 3,
    CHART_RADAR_VALUES_PARSING = 4,
};

// any #s greater than 200 means they dont need the text associated with readStart
enum Parsing {
    #ifndef NDEBUGGING
    // debug, to end song parsing early
    FAST_END = 0,
    #endif
    MEASURE_PARSING = 201,
    // gets the chart value between '${whitespace}' and ':'
    CHART_VALUE_END_WAITING = 1,
    // gets the chart value start position after whitespace
    CHART_VALUE_START_WAITING = 202,
    // gets the value between a ':' and a ';'
    VALUE_PARSING = 2,
    // gets the key between a '#' and a ':'
    KEY_PARSING = 3,
    // waits for '#' to indicate a key is next
    FIND_KEY_INDICATOR = 203
};

std::shared_ptr<SMSong> SMReader::Read(const std::string path) {
    // Holds the song being returned
    std::shared_ptr<SMSong> song = std::shared_ptr<SMSong>(new SMSong);
    // Holds the chart currently being parsed
    std::shared_ptr<SMChart> currentChart;
    // Holds the song filestream
    std::ifstream songFile(path, std::ios::in);
    // Holds the position of the last significant position read
    std::streamoff readStart = 0;
    // Holds the value of any information that would be skipped over due to comments
    std::string skippedValue = "";
    // Holds the key associated with the value currently being read
    std::string key = "";
    // Holds the current read mode of the chart parsing sections
    ChartParsing chartParsing = ChartParsing::CHART_TYPE_PARSING;
    // Holds the current chart's column count
    SM::column_t currentChartColumnCount = 0;
    // Holds the current number of beats parsed in the measure
    SM::subdivision_t beatsParsed = 0;
    // Holds the current being parsed measure
    std::shared_ptr<Measure> currentMeasure;
    // Holds whether or not the resulting note row has only been none type notes
    bool onlyNoneNotes = true;
    // Holds the currently being parsed noterow
    std::shared_ptr<NoteRow> currentNoteRow;
    // Holds the current column in a beat being parsed
    SM::column_t columnParsing = 0;
    // Holds the current read mode of the reader
    Parsing parsing = Parsing::FIND_KEY_INDICATOR;
    // Holds the current filestream positioned character
    char c;
    while (songFile.get(c)) {
        // if prev returns anything other than std::char_traits<char>::eof() then it is the old position before passing comments
        // if it is std::char_traits<char>::eof() then passComments had no effect
        std::streamoff prev = Util::File::passComments(songFile, c);
        // parsing >= 200 means value of readStart is disregarded, so avoid populating a string
        if (prev != std::char_traits<char>::eof() && parsing < 200) {
            // if comments were passed, then add the data from before the skip to skippedValue to be able to gather the lost info
            std::streamoff cur = songFile.tellg();
            skippedValue += Util::File::readSubstr(songFile, readStart, prev - readStart - 1L);
            // then move back to the position after the comment and set readStart rigiht ahead of it as well
            songFile.seekg(cur);
            readStart = cur;
        }
        
        Parsing enteringParsing = parsing;
        switch (parsing) {
            case Parsing::MEASURE_PARSING:
                switch (beatsParsed) {
                    case 0:
                        currentMeasure = std::shared_ptr<Measure>(new Measure);
                        beatsParsed = 1;
                    default:
                        switch (columnParsing) {
                            case 0:
                                switch (c) {
                                    case ';':
                                        song->charts.push_back(currentChart);
                                        parsing = Parsing::CHART_VALUE_START_WAITING;
                                    case ',':
                                        currentMeasure->subdivision = beatsParsed - 1;
                                        currentChart->measures.push_back(currentMeasure);
                                        currentMeasure = std::shared_ptr<Measure>(new Measure);
                                        beatsParsed = 1;
                                        break;
                                }
                                currentNoteRow = std::shared_ptr<NoteRow>(new NoteRow);
                                currentNoteRow->place = beatsParsed - 1;
                                currentNoteRow->notes.reserve(currentChartColumnCount);
                                columnParsing = 1;
                                
                            default:
                                if (columnParsing == currentChartColumnCount + 1) {
                                    if (c == '\n') {
                                        columnParsing = 0;
                                        if (!onlyNoneNotes) {
                                            currentMeasure->noteRows.push_back(currentNoteRow);
                                            onlyNoneNotes = true;
                                        }
                                        ++beatsParsed;
                                    }
                                } else {
                                    auto noteType = SM::NTFromChar(c);
                                    if (noteType != SM::NoteType::ERROR) {
                                        if (noteType != SM::NoteType::NONE) {
                                            onlyNoneNotes = false;
                                        }
                                        currentNoteRow->notes.push_back(noteType);
                                        ++columnParsing;
                                    }
                                }
                                break;
                        }
                        break;
                }
                break;
            case Parsing::CHART_VALUE_END_WAITING:
                if (c == '\r' || c == '\n' || c == ':') {
                    // if one of the chart value end indications is found (either a carriage return, linefeed, or colon)
                    // then set chart value to any skipped over value from comments concatted with the length from the latest
                    // section of non-commented text from the chart value begin
                    std::string chartValueStr = skippedValue + Util::File::readSubstr(songFile, readStart, songFile.tellg() - readStart - 1L);
                    switch (chartParsing) {
                        case ChartParsing::CHART_TYPE_PARSING:
                            // make a new chart that is currently being read, and set its chartType to the associated enum of
                            // the string that was just read
                            currentChart = std::shared_ptr<SMChart>(new SMChart(song));
                            currentChart->type = SM::CTFromName(chartValueStr);
                            break;
                        case ChartParsing::CHART_STEP_ARTIST_PARSING:
                            // set the current charts step artist to the held value
                            currentChart->stepArtist = chartValueStr;
                            break;
                        case ChartParsing::CHART_DIFFICULTY_PARSING:
                            // set the current charts difficulty to the associated enum of the held value
                            currentChart->difficulty = SM::DTFromName(chartValueStr);
                            break;
                        case ChartParsing::CHART_RATING_PARSING:
                            // Set the current charts rating to the held value
                            currentChart->rating = std::stoi(chartValueStr);
                            break;
                        case ChartParsing::CHART_RADAR_VALUES_PARSING:
                            // Set the 5 radar values to whatever they are held as
                            // still dont know what they even do
                            size_t start = 0;
                            size_t i = 0;
                            size_t radarValueCount = 0;
                            for (; i < chartValueStr.size(); ++i) {
                                if (chartValueStr[i] == ',') {
                                    currentChart->radarValues[radarValueCount++] = std::stof(chartValueStr.substr(start, i - start));
                                    start = i + 1;
                                    if (radarValueCount == 5) {
                                        break;
                                    }
                                }
                            }
                            if (radarValueCount < 5 && start != i) {
                                currentChart->radarValues[radarValueCount] = std::stof(chartValueStr.substr(start, i - start));
                                ++radarValueCount;
                            }
                            break;
                    }

                    // if the chart parsing isn't on the last step, then increment the step and parse the next chart value
                    if (chartParsing != ChartParsing::CHART_RADAR_VALUES_PARSING) {
                        // gross, but functional and easy to understand
                        chartParsing = static_cast<ChartParsing>(static_cast<int>(chartParsing) + 1);
                        parsing = Parsing::CHART_VALUE_START_WAITING;
                    } else {
                        // if the chart parsing is on the last step, then reset it and move on to note parsing
                        chartParsing = ChartParsing::CHART_TYPE_PARSING;
                        parsing = Parsing::MEASURE_PARSING;
                        // now that measures are being parsed it is finally necessary to request the current chart's type
                        currentChartColumnCount = currentChart->columnCount();
                    }
                }
                break;
            case Parsing::CHART_VALUE_START_WAITING:
                if (!Util::Char::isWhitespace(c)) {
                    // once non-whitespace is found after a chart's beginning, set readStart to the position before that character
                    // so that it can be read again in full after the end is found
                    // set to search for the end of chart value
                    parsing = Parsing::CHART_VALUE_END_WAITING;
                    readStart = songFile.tellg() - 1L;
                    if (c == ':') {
                        // seek back one character so that chart_value_end_waiting can re-read the colon as being the end as it is
                        songFile.seekg(readStart);
                    }
                }
                break;
            case Parsing::VALUE_PARSING:
                if (c == '\r' || c == '\n' || c == ';') {
                    // if one of the value end indications is found (either a carriage return, linefeed, or semicolon)
                    // then set value to any skipped over value from comments concatted with the length from the latest
                    // section of non-commented text from the key
                    std::string value = skippedValue + Util::File::readSubstr(songFile, readStart, songFile.tellg() - readStart - 1L);
                    // attempt to insert the key and value into the song
                    song->setKeyValuePair(key, value);
                    // set to search for a new key indicator
                    parsing = Parsing::FIND_KEY_INDICATOR;
                }
                break;
            case Parsing::KEY_PARSING:
                if (c == ':') {
                    // if the key end indicator is found then set key to any skipped over value from comments
                    //concatted with the length from the latest section of non-commented text from the key indicator
                    key = skippedValue + Util::File::readSubstr(songFile, readStart, songFile.tellg() - readStart - 1L);
                    // if the key is NOTES then a chart needs to be begun to be parsed
                    if (key == "NOTES") {
                        parsing = Parsing::CHART_VALUE_START_WAITING;
                    // if the key is anything else then it's a standard key value pair, so set readStart to current position
                    // for use in grabbing full value after the end is found, and switch to waiting for the value end indication
                    } else {
                        parsing = Parsing::VALUE_PARSING;
                        readStart = songFile.tellg();
                    }
                }
                break;
            case Parsing::FIND_KEY_INDICATOR:
                // if finding the key indicator treat anything that isn't the key indicator ('#') as whitespace,
                // less prone to erroring on stupider files
                if (c == '#') {
                    // upon finding the key indicator, switch to waiting for the key end indicator, set readStart to current position
                    // for use in grabbing the full key after the end is found
                    parsing = Parsing::KEY_PARSING;
                    readStart = songFile.tellg();
                }
                break;
            #ifndef NDEBUGGING
            case Parsing::FAST_END:
                // debug method for short-circuit ending execution of parsing
                return song;
            #endif
            default:
                Logging::Error("SMReader parsing set to strange value");
                break;
        }
        if (enteringParsing != parsing) {
            skippedValue = "";
        }
    }
    songFile.close();
    return song;
}