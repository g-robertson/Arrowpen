#pragma once

#include <memory>
#include <vector>
#include <string>

namespace SM {
    typedef uint8_t column_t;
    typedef uint8_t subdivision_t;
    typedef uint16_t rating_t;

    enum class ChartDifficulty {
        NONE, // not defined
        BEGINNER, // "Beginner"
        EASY, // "Easy"
        NORMAL, // "Medium"
        HARD, // "Hard"
        INSANE, // "Challenge"
        EDIT, // "Edit"
        ERROR // "error"
    };

    SM::ChartDifficulty DTFromName(const std::string chartDifficultyStr);
    std::string DTGetName(const SM::ChartDifficulty chartDifficulty);

    // commented only because it is also commented in etterna's codebase
    // KB7_SMALL, // "kb7-small", 7k
    // For now only support dance-singles
    // references https://github.com/etternagame/etterna/blob/0a7bd768cffd6f39a3d84d76964097e43011ce33/src/Etterna/Singletons/GameManager.cpp#L45
    enum class ChartType {
        NONE, // "none", 0k
        DANCE_THREE_PANEL, // "dance-threepanel", 3k
        DANCE_SINGLE, // "dance-single", 4k
        MANIAX_SINGLE, // "maniax-single", 4k
        PUMP_SINGLE, // "pump-single", 5k
        PNM_FIVE, // "pnm-five", 5k
        EZ2_SINGLE, // "ez2-single", 5k
        DANCE_SOLO, // "dance-solo", 6k
        BM_SINGLE5, // "bm-single5", 6k
        PUMP_HALF_DOUBLE, // "pump-halfdouble", 6k
        KB7_SINGLE, // "kb7-single", 7k
        EZ2_REAL, // "ez2-real", 7k
        DANCE_DOUBLE, // "dance-double", 8k
        BM_SINGLE7, // "bm-single7", 8k
        DS3DDX_SINGLE, // "ds3ddx-single", 8k
        MANIAX_DOUBLE, // "maniax-double", 8k
        PNM_NINE, // "pnm-nine", 9k
        EZ2_DOUBLE, // "ez-2double", 10k
        PUMP_DOUBLE, // "pump-double", 10k
        BM_DOUBLE5, // "bm-double5", 12k
        KB7_DOUBLE, // "kb7-double", 14k
        BM_DOUBLE7, // "bm-double7", 16k
        ERROR // "error", 255k
    };

    SM::column_t CTColumnCount(const SM::ChartType chartType);
    SM::ChartType CTFromName(const std::string chartTypeStr);
    std::string CTGetName(const SM::ChartType chartType);

    // references https://step-mania.fandom.com/wiki/.sm
    enum class NoteType {
        NONE, // '0' (undocumented)
        
        TAP_NOTE, // '1'
        LIFT, // 'L'

        HOLD_HEAD, // '2'
        ROLL_HEAD, // '4'
        HOLD_END, //'3'

        MINE, // 'M'

        // I don't know what these do or they have no usage but they are documented in 
        // https://step-mania.fandom.com/wiki/.sm
        FAKE, // 'N'
        ATTACK, // 'A'
        AUTO_KEYSOUND, // 'K'
        HIDDEN, // 'H'
        ERROR // '\xFF'
    };
    SM::NoteType NTFromChar(const char noteTypeChar);
    char NTGetChar(const SM::NoteType noteType);
};


// Felt too primitive to leave with the more chart-song-specific things
struct BPMSignature {
    float beat;
    float bpm;

    BPMSignature(float beat, float bpm);
};

// These should all be defined below, in order of complexity. Least complex struct -> most complex struct

// Holds a noterow's placement in a subdivision, as well as each columns notes from leftmost to rightmost
struct NoteRow;
// Holds the measures subdivision, as well as all noterows
struct Measure;
// Holds all info that is shared on a per-chart basis, as well as the song's measures
struct SMChart;
// Holds all info relevant to a specific chart within a song entry
struct SMChartGlobalInfo;
// Holds all info relevant to a song entry
struct SMSongGlobalInfo;
// Holds all info that is shared on a per-song basis, as well as the song's charts
struct SMSong;




struct NoteRow {
    SM::subdivision_t place;
    std::vector<SM::NoteType> notes;
};

struct Measure {
    SM::subdivision_t subdivision;
    std::vector<std::shared_ptr<NoteRow>> noteRows;
};

class SMChart {
    public:
        SMChart(std::weak_ptr<SMSong> song);
        std::weak_ptr<SMSong> fromSong;
        std::vector<std::shared_ptr<Measure>> measures;
        SM::ChartType type = SM::ChartType::NONE;
        std::string stepArtist;
        SM::ChartDifficulty difficulty = SM::ChartDifficulty::NONE;
        SM::rating_t rating;
        float radarValues[5];
        SM::column_t columnCount();
};

// https://bemani.fandom.com/wiki/.sm_file for reference on these
struct SMChartGlobalInfo {
    float offset;
    float samplestart;
    float samplelength;
    std::vector<std::shared_ptr<BPMSignature>> bpms;
};

// https://bemani.fandom.com/wiki/.sm_file for reference on these
struct SMSongGlobalInfo {
    std::string title;
    std::string subtitle;
    std::string artist;
    std::string titleTranslit;
    std::string subtitleTranslit;
    std::string artistTranslit;
    std::string genre;
    std::string credit;
    std::string banner;
    std::string background;
    std::string lyrics;
    std::string cdTitle;
    std::string music;
    bool selectable;


    // unknown infos
    std::string stops = "";
    std::string backgroundChanges = "";
    std::string foregroundChanges = "";
};

class SMSong {
    public:
        std::shared_ptr<SMSongGlobalInfo> songInfo = std::shared_ptr<SMSongGlobalInfo>(new SMSongGlobalInfo);
        std::shared_ptr<SMChartGlobalInfo> chartInfo = std::shared_ptr<SMChartGlobalInfo>(new SMChartGlobalInfo);
        std::vector<std::shared_ptr<SMChart>> charts;

        void setKeyValuePair(std::string key, std::string value);
};