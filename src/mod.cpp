#include "mod.h"
#include "memory_helper.h"

void Mod::Initialize() {
    raceSystem = new RaceSystem();
    raceSystem->Initialize();

    raceExpansionSystem = new RaceExpansionSystem();
    raceExpansionSystem->Initialize();
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
