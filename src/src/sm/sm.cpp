#include <string>
#include <iostream>
#include <stdexcept>

#include "logging.hpp"
#include "sm.hpp"

BPMSignature::BPMSignature(float beat, float bpm) {
    this->beat = beat;
    this->bpm = bpm;
}

SM::ChartDifficulty SM::DTFromName(const std::string chartDifficultyStr) {
    #define SDifficultyTypeStrInit(dt, dtstr) if (chartDifficultyStr == #dtstr) return SM::ChartDifficulty::dt
    #define SDifficultyTypeStr(dt, dtstr) else if (chartDifficultyStr == #dtstr) return SM::ChartDifficulty::dt
    SDifficultyTypeStrInit(NONE, none);
    SDifficultyTypeStr(BEGINNER, Beginner);
    SDifficultyTypeStr(EASY, Easy);
    SDifficultyTypeStr(NORMAL, Medium);
    SDifficultyTypeStr(HARD, Hard);
    SDifficultyTypeStr(INSANE, Challenge);
    SDifficultyTypeStr(EDIT, Edit);
    SDifficultyTypeStr(ERROR, error);
    else {
        Logging::Error("Unrecognized difficulty name: " + chartDifficultyStr);
    }
    #undef SDifficultyTypeStrInit
    #undef SDifficultyTypeStr
    return SM::ChartDifficulty::ERROR;
}

std::string SM::DTGetName(const SM::ChartDifficulty chartDifficulty) {
    #define SDifficultyType(dt, dtstr) case SM::ChartDifficulty::dt: return #dtstr
    switch (chartDifficulty) {
        SDifficultyType(NONE, none);
        SDifficultyType(BEGINNER, Beginner);
        SDifficultyType(EASY, Easy);
        SDifficultyType(NORMAL, Medium);
        SDifficultyType(HARD, Hard);
        SDifficultyType(INSANE, Challenge);
        SDifficultyType(EDIT, Edit);
        SDifficultyType(ERROR, error);
        default:
            Logging::Error("Unrecognized difficulty type: " + std::to_string((uint8_t)chartDifficulty));
            break;
    }
    #undef SDifficultyType
    return SM::DTGetName(SM::ChartDifficulty::ERROR);
}

SM::column_t SM::CTColumnCount(const SM::ChartType chartType) {
    #define SColumnCount(ct, cti) case SM::ChartType::ct: return cti
    #define SColumnCountFT(ct) case SM::ChartType::ct:
    switch (chartType) {
        // god bless regular expressions
        SColumnCount(NONE, 0);
        SColumnCount(DANCE_THREE_PANEL, 3);
        SColumnCountFT(DANCE_SINGLE);
        SColumnCount(MANIAX_SINGLE, 4);
        SColumnCountFT(PUMP_SINGLE);
        SColumnCountFT(PNM_FIVE);
        SColumnCount(EZ2_SINGLE, 5);
        SColumnCountFT(DANCE_SOLO);
        SColumnCountFT(BM_SINGLE5);
        SColumnCount(PUMP_HALF_DOUBLE, 6);
        SColumnCountFT(KB7_SINGLE);
        SColumnCount(EZ2_REAL, 7);
        SColumnCountFT(DANCE_DOUBLE);
        SColumnCountFT(BM_SINGLE7);
        SColumnCountFT(DS3DDX_SINGLE);
        SColumnCount(MANIAX_DOUBLE, 8);
        SColumnCount(PNM_NINE, 9);
        SColumnCountFT(EZ2_DOUBLE);
        SColumnCountFT(PUMP_DOUBLE);
        SColumnCount(BM_DOUBLE5, 10);
        SColumnCount(KB7_DOUBLE, 14);
        SColumnCount(BM_DOUBLE7, 16);
        SColumnCount(ERROR, 255);
        default:
            Logging::Error("Unrecognized chart type: " + std::to_string((uint8_t)chartType));
            break;
    }
    #undef SColumnCount
    #undef SColumnCountFT
    return SM::CTColumnCount(SM::ChartType::ERROR);
}

SM::ChartType SM::CTFromName(const std::string chartTypeStr) {
    #define SChartTypeStrInit(ct, ctstr) if (chartTypeStr == #ctstr) return SM::ChartType::ct
    #define SChartTypeStr(ct, ctstr) else if (chartTypeStr == #ctstr) return SM::ChartType::ct
    // god bless regular expressions
    SChartTypeStrInit(NONE, none);
    SChartTypeStr(DANCE_THREE_PANEL, dance-threepanel);
    SChartTypeStr(DANCE_SINGLE, dance-single);
    SChartTypeStr(MANIAX_SINGLE, maniax-single);
    SChartTypeStr(PUMP_SINGLE, pump-single);
    SChartTypeStr(PNM_FIVE, pnm-five);
    SChartTypeStr(EZ2_SINGLE, ez2-single);
    SChartTypeStr(DANCE_SOLO, dance-solo);
    SChartTypeStr(BM_SINGLE5, bm-single5);
    SChartTypeStr(PUMP_HALF_DOUBLE, pump-halfdouble);
    SChartTypeStr(KB7_SINGLE, kb7-single);
    SChartTypeStr(EZ2_REAL, ez2-real);
    SChartTypeStr(DANCE_DOUBLE, dance-double);
    SChartTypeStr(BM_SINGLE7, bm-single7);
    SChartTypeStr(DS3DDX_SINGLE, ds3ddx-single);
    SChartTypeStr(MANIAX_DOUBLE, maniax-double);
    SChartTypeStr(PNM_NINE, pnm-nine);
    SChartTypeStr(EZ2_DOUBLE, ez-2double);
    SChartTypeStr(PUMP_DOUBLE, pump-double);
    SChartTypeStr(BM_DOUBLE5, bm-double5);
    SChartTypeStr(KB7_DOUBLE, kb7-double);
    SChartTypeStr(BM_DOUBLE7, bm-double7);
    SChartTypeStr(ERROR, error);
    else {
        Logging::Error("Unrecognized chart type name: " + chartTypeStr);
    }
    #undef SChartTypeStrInit
    #undef SChartTypeStr

    return SM::ChartType::ERROR;
}

std::string SM::CTGetName(const SM::ChartType chartType) {
    #define SChartType(ct, ctstr) case SM::ChartType::ct: return #ctstr
    switch (chartType) {
        // god bless regular expressions
        SChartType(NONE, none);
        SChartType(DANCE_THREE_PANEL, dance-threepanel);
        SChartType(DANCE_SINGLE, dance-single);
        SChartType(MANIAX_SINGLE, maniax-single);
        SChartType(PUMP_SINGLE, pump-single);
        SChartType(PNM_FIVE, pnm-five);
        SChartType(EZ2_SINGLE, ez2-single);
        SChartType(DANCE_SOLO, dance-solo);
        SChartType(BM_SINGLE5, bm-single5);
        SChartType(PUMP_HALF_DOUBLE, pump-halfdouble);
        SChartType(KB7_SINGLE, kb7-single);
        SChartType(EZ2_REAL, ez2-real);
        SChartType(DANCE_DOUBLE, dance-double);
        SChartType(BM_SINGLE7, bm-single7);
        SChartType(DS3DDX_SINGLE, ds3ddx-single);
        SChartType(MANIAX_DOUBLE, maniax-double);
        SChartType(PNM_NINE, pnm-nine);
        SChartType(EZ2_DOUBLE, ez-2double);
        SChartType(PUMP_DOUBLE, pump-double);
        SChartType(BM_DOUBLE5, bm-double5);
        SChartType(KB7_DOUBLE, kb7-single);
        SChartType(BM_DOUBLE7, bm-double7);
        SChartType(ERROR, error);
        default:
            Logging::Error("Unrecognized chart type: " + std::to_string((uint8_t)chartType));
            break;
    }
    #undef SChartType
    return SM::CTGetName(SM::ChartType::ERROR);
}

SM::NoteType SM::NTFromChar(const char noteTypeChar) {
    #define SNoteType(ntchr, nt) case nt: return SM::NoteType::ntchr
    switch (noteTypeChar) {
        SNoteType(NONE, '0');
        SNoteType(TAP_NOTE, '1');
        SNoteType(LIFT, 'L');
        SNoteType(HOLD_HEAD, '2');
        SNoteType(ROLL_HEAD, '4');
        SNoteType(HOLD_END, '3');
        SNoteType(MINE, 'M');
        SNoteType(FAKE, 'N');
        SNoteType(ATTACK, 'A');
        SNoteType(AUTO_KEYSOUND, 'K');
        SNoteType(HIDDEN, 'H');
        default:
            return SM::NoteType::ERROR;
    }
    #undef SNoteType
    
}

// https://step-mania.fandom.com/wiki/.sm
char SM::NTGetChar(const SM::NoteType noteType) {
    #define SNoteType(nt, ntchr) case SM::NoteType::nt: return ntchr
    switch (noteType) {
        SNoteType(NONE, '0');
        SNoteType(TAP_NOTE, '1');
        SNoteType(LIFT, 'L');
        SNoteType(HOLD_HEAD, '2');
        SNoteType(ROLL_HEAD, '4');
        SNoteType(HOLD_END, '3');
        SNoteType(MINE, 'M');
        SNoteType(FAKE, 'N');
        SNoteType(ATTACK, 'A');
        SNoteType(AUTO_KEYSOUND, 'K');
        SNoteType(HIDDEN, 'H');
        case SM::NoteType::ERROR:
            Logging::Error("Tried to get character of 'ERROR' note type, should be handled not used.");
            break;
        default:
            Logging::Error("Unrecognized note type");
            break;
    }
    #undef SNoteType
    return SM::NTGetChar(SM::NoteType::ERROR);
}

SMChart::SMChart(std::weak_ptr<SMSong> song) {
    this->fromSong = song;
}

SM::column_t SMChart::columnCount() {
    return SM::CTColumnCount(this->type);
}

enum Parsing {
    BEAT_PARSING,
    BPM_PARSING
};

void SMSong::setKeyValuePair(std::string key, std::string value) {
    // Very low priority todo: change this from an if else if table to a binary search table
    #define SKey(keyName, info, name) else if (key == #keyName) this info->name = value
    #define SKeyTof(keyName, info, name) else if (key == #keyName) this info->name = atof(value.c_str())
    #define SSongKey(keyName, name) SKey(keyName, ->songInfo, name)
    #define SChartKeyTof(keyName, name) SKeyTof(keyName, ->chartInfo, name)
    if (value == "") {
        return;
    }
    SSongKey(TITLE, title);
    SSongKey(SUBTITLE, subtitle);
    SSongKey(ARTIST, artist);
    SSongKey(TITLETRANSLIT, titleTranslit);
    SSongKey(SUBTITLETRANSLIT, subtitleTranslit);
    SSongKey(ARTISTTRANSLIT, artistTranslit);
    SSongKey(GENRE, genre);
    SSongKey(CREDIT, credit);
    SSongKey(MUSIC, music);
    SSongKey(BANNER, banner);
    SSongKey(BACKGROUND, background);
    SSongKey(CDTITLE, cdTitle);
    SSongKey(STOPS, stops);
    SSongKey(BGCHANGES, backgroundChanges);
    SSongKey(FGCHANGES, foregroundChanges);
    else if(key == "SELECTABLE") {
        songInfo->selectable = value == "YES";
    }
    SChartKeyTof(SAMPLESTART, samplestart);
    SChartKeyTof(SAMPLELENGTH, samplelength);
    SChartKeyTof(OFFSET, offset);
    
    else if (key == "BPMS") {
        Parsing parsing = Parsing::BEAT_PARSING;
        size_t start = 0;
        float beat = -1;
        size_t i = 0;
        for (; i < value.size(); ++i) {
            if (parsing == Parsing::BEAT_PARSING) {
                if (value[i] == '=') {
                    beat = std::stof(value.substr(start, i - start));
                    start = i + 1;
                    parsing = Parsing::BPM_PARSING;
                }
            } else if (parsing == Parsing::BPM_PARSING) {
                if (value[i] == ',') {
                    float bpm = std::stof(value.substr(start, i - start));
                    start = i + 1;
                    parsing = Parsing::BEAT_PARSING;

                    this->chartInfo->bpms.push_back(std::shared_ptr<BPMSignature>(new BPMSignature(beat, bpm)));
                }
            }
        }
        if (start != i) {
            float bpm = std::stof(value.substr(start, i - start));
            this->chartInfo->bpms.push_back(std::shared_ptr<BPMSignature>(new BPMSignature(beat, bpm)));
        }
    } else {
        std::cout << key << " UNUSED";
    }

    #undef SKey
    #undef SKeyTof
}
    /*
#STOPS:;
#BGCHANGES:;
#FGCHANGES:;
*/