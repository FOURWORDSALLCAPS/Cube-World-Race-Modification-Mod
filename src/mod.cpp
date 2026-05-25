#include "mod.h"
#include "memory_helper.h"

void Mod::Initialize() {
    uint64_t base = MemoryHelper::GetCubeBase();

    unsigned char rollBytes[] = { 0xF3, 0x44, 0x0F, 0x10, 0x2D, 0x31, 0x2D, 0x19, 0x00 };
    void* rollAddr = (void*)(base + 0x2DF4CE);
    MemoryHelper::PatchMemory(rollAddr, rollBytes, sizeof(rollBytes));

    unsigned char diveBytes[] = { 0xF3, 0x44, 0x0F, 0x10, 0x1D, 0x01, 0x2C, 0x19, 0x00 };
    void* diveAddr = (void*)(base + 0x2DF616);
    MemoryHelper::PatchMemory(diveAddr, diveBytes, sizeof(diveBytes));

}

Mod::Mod() {
    raceSystem = new RaceSystem();
}

Mod::~Mod() {
    delete raceSystem;
}

void Mod::OnGameTick(cube::Game* game) {
    if (!game) return;
    cube::Creature* player = game->GetPlayer();
    if (!player) return;
    raceSystem->Update(player);
}

void Mod::OnCreatureHPCalculated(cube::Creature* creature, float* hp) {
    raceSystem->OnHPCalculated(creature, hp);
}

void Mod::OnCreatureManaGenerationCalculated(cube::Creature* creature, float* manaGeneration) {
    raceSystem->OnManaGenerationCalculated(creature, manaGeneration);
}

void Mod::OnCreatureAttackPowerCalculated(cube::Creature* creature, float* power) {
    raceSystem->OnAttackPowerCalculated(creature, power);
}

void Mod::OnCreatureCriticalCalculated(cube::Creature* creature, float* critical) {
    raceSystem->OnCriticalCalculated(creature, critical);
}

void Mod::OnCreatureHasteCalculated(cube::Creature* creature, float* haste) {
    raceSystem->OnHasteCalculated(creature, haste);
}

void Mod::OnCreatureArmorCalculated(cube::Creature* creature, float* armor) {
    raceSystem->OnArmorCalculated(creature, armor);
}

void Mod::OnCreatureSpellPowerCalculated(cube::Creature* creature, float* power) {
    raceSystem->OnSpellPowerCalculated(creature, power);
}

void Mod::OnCreatureRegenerationCalculated(cube::Creature* creature, float* regen) {
    raceSystem->OnRegenerationCalculated(creature, regen);
}
