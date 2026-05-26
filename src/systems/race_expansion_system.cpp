#include "race_expansion_system.h"
#include "../memory_helper.h"
#include "../hooks/on_generate_creature.h"
#include "../hooks/on_get_race_name.h"
#include "../enums/races.h"

RaceExpansionSystem* g_RaceExpansionSystem = nullptr;

RaceExpansionSystem::RaceExpansionSystem() {
    g_RaceExpansionSystem = this;
    AddCustomRace(8, (int)Race::VAMPIRE, false, "Vampire");
}

RaceExpansionSystem::~RaceExpansionSystem() {
    g_RaceExpansionSystem = nullptr;
}

void RaceExpansionSystem::AddCustomRace(int menuIndex, int actualRaceID, bool hasGender, const char* name) {
    customRaces.push_back({ menuIndex, actualRaceID, hasGender, name });
}

int RaceExpansionSystem::GetCustomRace(int menuIndex, char gender) {
    for (const auto& race : customRaces) {
        if (menuIndex == race.menuIndex) {
            if (race.hasGender) {
                return race.actualRaceID + (gender & 1);
            }
            return race.actualRaceID;
        }
    }
    return -1;
}

const char* RaceExpansionSystem::GetRaceName(int raceID) {
    for (const auto& race : customRaces) {
        int maleID = race.actualRaceID;
        int femaleID = race.hasGender ? race.actualRaceID + 1 : maleID;
        if (raceID == maleID || raceID == femaleID) {
            return race.displayName;
        }
    }

    switch (raceID) {
    case (int)Race::ELF: case (int)Race::ELF + 1: return "Elf";
    case (int)Race::HUMAN: case (int)Race::HUMAN + 1: return "Human";
    case (int)Race::GOBLIN: case (int)Race::GOBLIN + 1: return "Goblin";
    case (int)Race::LIZARDMAN: case (int)Race::LIZARDMAN + 1: return "Lizardman";
    case (int)Race::DWARF: case (int)Race::DWARF + 1: return "Dwarf";
    case (int)Race::ORK: case (int)Race::ORK + 1: return "Ork";
    case (int)Race::FROGMAN: case (int)Race::FROGMAN + 1: return "Frogman";
    case (int)Race::UNDEAD: case (int)Race::UNDEAD + 1: return "Undead";
    default: return nullptr;
    }
}

void RaceExpansionSystem::Initialize() {
    if (hookInstalled) return;

    WriteByte(CWOffset(0x272648 + 0x02), 8);
    WriteByte(CWOffset(0x2725F1 + 0x01), 8);

    WriteFarJMP(CWOffset(0x53FDB), (void*)&ASMOnGenerateCreature);
    ASMOnGenerateCreature_jmpback = CWOffset(0x54057);

    InitializeRaceNameHooks();

    hookInstalled = true;
}
