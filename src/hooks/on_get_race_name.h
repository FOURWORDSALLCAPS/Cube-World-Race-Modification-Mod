#pragma once
#include "cwsdk.h"
#include "../hooks.h"
#include "../systems/race_expansion_system.h"
#include <string>
#include "../enums/races.h"

extern "C" void OnGetCreatureRaceName(void* stringBuilder, cube::Creature * creature) {
    if (!creature || !g_RaceExpansionSystem) return;

    const char* name = g_RaceExpansionSystem->GetRaceName(creature->entity_data.race);
    if (name) {
        ((void (*)(void*, const char*))CWOffset(0x6D8E0))(stringBuilder, name);
    }
}

extern "C" void OnGetMenuRaceName(void* stringBuilder, int menuIndex) {
    if (!g_RaceExpansionSystem) return;

    int raceID;
    switch (menuIndex) {
    case 0: raceID = (int)Race::HUMAN; break;
    case 1: raceID = (int)Race::ELF; break;
    case 2: raceID = (int)Race::DWARF; break;
    case 3: raceID = (int)Race::ORK; break;
    case 4: raceID = (int)Race::GOBLIN; break;
    case 5: raceID = (int)Race::LIZARDMAN; break;
    case 6: raceID = (int)Race::UNDEAD; break;
    case 7: raceID = (int)Race::FROGMAN; break;
    case 8: raceID = (int)Race::VAMPIRE; break;
    default: raceID = menuIndex; break;
    }

    const char* name = g_RaceExpansionSystem->GetRaceName(raceID);
    if (name) {
        std::wstring wname(name, name + strlen(name));
        ((void (*)(void*, const wchar_t*))CWOffset(0x486B0))(stringBuilder, wname.c_str());
    }
}

GETTER_VAR(void*, ASMOnGetCreatureRaceName_jmpback);
__attribute__((naked)) void ASMOnGetCreatureRaceName() {
    asm(".intel_syntax \n"
        "lea rcx, [rsp + 0x50] \n"
        "mov rdx, rax \n"
        PREPARE_STACK
        "call OnGetCreatureRaceName \n"
        RESTORE_STACK
        DEREF_JMP(ASMOnGetCreatureRaceName_jmpback)
        ".att_syntax \n"
    );
}

GETTER_VAR(void*, ASMOnGetMenuRaceName_jmpback);
__attribute__((naked)) void ASMOnGetMenuRaceName() {
    asm(".intel_syntax \n"
        "lea rcx, [rsp + 0x50] \n"
        "mov rdx, rax \n"
        PREPARE_STACK
        "call OnGetMenuRaceName \n"
        RESTORE_STACK
        DEREF_JMP(ASMOnGetMenuRaceName_jmpback)
        ".att_syntax \n"
    );
}

void InitializeRaceNameHooks() {
    WriteFarJMP(CWOffset(0x26F548), (void*)&ASMOnGetCreatureRaceName);
    ASMOnGetCreatureRaceName_jmpback = CWOffset(0x26F5A4);

    WriteFarJMP(CWOffset(0x271144), (void*)&ASMOnGetMenuRaceName);
    ASMOnGetMenuRaceName_jmpback = CWOffset(0x2711A5);
}
