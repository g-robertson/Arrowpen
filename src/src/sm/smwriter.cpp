#include <memory>
#include <string>
#include <fstream> 

#include <iostream>

#include <iomanip>

#include "smwriter.hpp"

bool SMWriter::Write(std::shared_ptr<SMSong> song, std::string path) {
    std::ofstream ofs(path);
    // sets all decimal places to 3, mimics arrowvortex style output
    ofs << std::setprecision(3) << std::fixed;
    #define OfsKey(keyName, info, name) ofs << "#" #keyName ":" << (song info->name) << ";" << std::endl
    #define OfsSongKey(keyName, name) OfsKey(keyName, ->songInfo, name)
    #define OfsChartKey(keyName, name) OfsKey(keyName, ->chartInfo, name)
    OfsSongKey(TITLE, title);
    OfsSongKey(SUBTITLE, subtitle);
    OfsSongKey(ARTIST, artist);
    OfsSongKey(TITLETRANSLIT, titleTranslit);
    OfsSongKey(SUBTITLETRANSLIT, subtitleTranslit);
    OfsSongKey(ARTISTTRANSLIT, artistTranslit);
    OfsSongKey(GENRE, genre);
    OfsSongKey(CREDIT, credit);
    OfsSongKey(MUSIC, music);
    OfsSongKey(BANNER, banner);
    OfsSongKey(BACKGROUND, background);
    OfsSongKey(CDTITLE, cdTitle);
    OfsChartKey(SAMPLESTART, samplestart);
    OfsChartKey(SAMPLELENGTH, samplelength);
    OfsSongKey(SELECTABLE, selectable ? "YES" : "NO");
    OfsChartKey(OFFSET, offset);

    ofs << "#BPMS:";
    auto bpms = song->chartInfo->bpms;
    for (size_t i = 0; i < bpms.size(); ++i) {
        ofs << bpms[i]->beat << "=" << bpms[i]->bpm;
    }
    ofs << ";" << std::endl;

    OfsSongKey(STOPS, stops);
    OfsSongKey(BGCHANGES, backgroundChanges);
    OfsSongKey(FGCHANGES, foregroundChanges);

    for (size_t i = 0; i < song->charts.size(); ++i) {
        ofs << "#NOTES:" << std::endl;
        auto chart = song->charts[i];

        ofs << "     " << SM::CTGetName(chart->type) << ":" << std::endl;
        ofs << "     " << chart->stepArtist << ":" << std::endl;
        ofs << "     " << SM::DTGetName(chart->difficulty) << ":" << std::endl;
        ofs << "     " << chart->rating << ":" << std::endl;
        ofs << "     " << chart->radarValues[0];
        for (size_t i = 1; i < 5; ++i) {
            ofs << "," << chart->radarValues[i];
        }
        ofs << ":" << std::endl;

        auto measures = chart->measures;
        auto columnCount = chart->columnCount();

        std::string emptyNoteRowStr = "";
        for (SM::column_t i = 0; i < columnCount; ++i) {
            emptyNoteRowStr += SM::NTGetChar(SM::NoteType::NONE);
        }

        for (size_t i = 0; i < measures.size(); ++i) {
            
            auto noteRows = measures[i]->noteRows;
            SM::subdivision_t place = 0;
            for (SM::subdivision_t j = 0; j < noteRows.size(); ++j) {
                auto noteRow = noteRows[j];
                while (place != noteRow->place) {
                    ofs << emptyNoteRowStr << std::endl;
                    ++place;
                }

                for (SM::column_t k = 0; k < columnCount; ++k) {
                    ofs << SM::NTGetChar(noteRow->notes[k]);
                }
                ++place;
                ofs << std::endl;
            }

            while (place < measures[i]->subdivision) {
                ofs << emptyNoteRowStr << std::endl;
                ++place;
            }

            if (i + 1 != measures.size()) {
                ofs << ",";
            } else {
                ofs << ";";
            }
            ofs << std::endl;
        }
    }

    ofs.flush();
    ofs.close();
    
    #undef OfsKey
    #undef OfsSongKey
    #undef OfsChartKey
    return true;
}