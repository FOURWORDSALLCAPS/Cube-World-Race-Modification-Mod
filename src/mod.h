#pragma once
#include <string>
#include "systems/race_system.h"
#include "systems/race_expansion_system.h"

class Mod : public GenericMod {
private:
    RaceSystem* raceSystem;
    RaceExpansionSystem* raceExpansionSystem;

public:
    Mod();
    ~Mod();

    virtual void Initialize() override;
    virtual void OnGameTick(cube::Game* game) override;
    virtual void OnCreatureHPCalculated(cube::Creature* creature, float* hp) override;
    virtual void OnCreatureManaGenerationCalculated(cube::Creature* creature, float* manaGeneration) override;
    virtual void OnCreatureAttackPowerCalculated(cube::Creature* creature, float* power) override;
    virtual void OnCreatureCriticalCalculated(cube::Creature* creature, float* critical) override;
    virtual void OnCreatureHasteCalculated(cube::Creature* creature, float* haste) override;
    virtual void OnCreatureArmorCalculated(cube::Creature* creature, float* armor) override;
    virtual void OnCreatureSpellPowerCalculated(cube::Creature* creature, float* power) override;
    virtual void OnCreatureRegenerationCalculated(cube::Creature* creature, float* regen) override;
};
