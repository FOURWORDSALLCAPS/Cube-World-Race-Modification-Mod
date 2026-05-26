#pragma once
#include "../../CWSDK/cwsdk.h"
#include "../cube/SaveData.h"
#include <vector>

struct CustomRaceEntry {
    int menuIndex;
    int actualRaceID;
    bool hasGender;
    const char* displayName;
};

class RaceExpansionSystem {
private:
    std::vector<CustomRaceEntry> customRaces;
    bool hookInstalled = false;

public:
    RaceExpansionSystem();
    ~RaceExpansionSystem();

    void Initialize();
    void AddCustomRace(int menuIndex, int actualRaceID, bool hasGender, const char* name);
    int GetCustomRace(int menuIndex, char gender);
    const char* GetRaceName(int raceID);
};

extern RaceExpansionSystem* g_RaceExpansionSystem;
