#pragma once
#include "../../CWSDK/cwsdk.h"
#include "../enums/races.h"
#include "../enums/classes.h"

class RaceSystem {
private:
    int currentRace = -1;

    float hpMult = 1.0f;
    float armorMult = 1.0f;
    float attackPowerMult = 1.0f;
    float spellPowerMult = 1.0f;
    float critMult = 1.0f;
    float hasteMult = 1.0f;
    float regenMult = 1.0f;
    float manaGenMult = 1.0f;
    float swimSpeedMult = 1.0f;
    float climbSpeedMult = 1.0f;
    float staminaCostMult = 1.0f;

    void ApplyBonuses(cube::Creature* player);
    void ApplyStaminaCostPatch(cube::Creature* player);

public:
    void Update(cube::Creature* player);

    void OnHPCalculated(cube::Creature* creature, float* hp);
    void OnArmorCalculated(cube::Creature* creature, float* armor);
    void OnAttackPowerCalculated(cube::Creature* creature, float* power);
    void OnSpellPowerCalculated(cube::Creature* creature, float* power);
    void OnCriticalCalculated(cube::Creature* creature, float* critical);
    void OnHasteCalculated(cube::Creature* creature, float* haste);
    void OnRegenerationCalculated(cube::Creature* creature, float* regen);
    void OnManaGenerationCalculated(cube::Creature* creature, float* manaGen);
    void OnSwimSpeedCalculated(cube::Creature* creature, float* speed);
    void OnClimbSpeedCalculated(cube::Creature* creature, float* speed);
};
