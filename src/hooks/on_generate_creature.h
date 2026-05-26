#pragma once
#include "cwsdk.h"
#include "../hooks.h"
#include "../systems/race_expansion_system.h"
#include "../enums/races.h"

extern "C" int OnGenerateCreatureHook(int menuIndex, char gender) {
    if (menuIndex > 8) return -1;

    if (g_RaceExpansionSystem) {
        int customRace = g_RaceExpansionSystem->GetCustomRace(menuIndex, gender);
        if (customRace != -1) {
            return customRace;
        }
    }

    switch (menuIndex) {
    case 0: return (gender & 1) + (int)Race::HUMAN;
    case 1: return (gender & 1) + (int)Race::ELF;
    case 2: return (gender & 1) + (int)Race::DWARF;
    case 3: return (gender & 1) + (int)Race::ORK;
    case 4: return (gender & 1) + (int)Race::GOBLIN;
    case 5: return (gender & 1) + (int)Race::LIZARDMAN;
    case 6: return (gender & 1) + (int)Race::UNDEAD;
    case 7: return (gender & 1) + (int)Race::FROGMAN;
    default: return -1;
    }
}

GETTER_VAR(void*, ASMOnGenerateCreature_jmpback);
__attribute__((naked)) void ASMOnGenerateCreature() {
    asm(".intel_syntax \n"
        PUSH_ALL
        "mov ecx, [r8] \n"
        "movzx edx, byte ptr [r8+4] \n"
        PREPARE_STACK
        "call OnGenerateCreatureHook \n"
        RESTORE_STACK
        "mov [r12], eax \n"
        POP_ALL
        DEREF_JMP(ASMOnGenerateCreature_jmpback)
        ".att_syntax \n"
    );
}
