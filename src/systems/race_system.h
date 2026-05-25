#pragma once
#include "../../CWSDK/cwsdk.h"
#include "../enums/races.h"
#include "../enums/classes.h"

class RaceSystem {
private:
    int currentRace = -1;

    void ApplyAppearance(cube::Creature* player);
    void ApplyStaminaCostPatch(cube::Creature* player);

    float GetHpMult(unsigned int race, unsigned char classType);
    float GetArmorMult(unsigned int race);
    float GetAttackPowerMult(unsigned int race);
    float GetSpellPowerMult(unsigned int race);
    float GetCritMult(unsigned int race);
    float GetHasteMult(unsigned int race);
    float GetRegenMult(unsigned int race);
    float GetManaGenMult(unsigned int race);
    float GetSwimSpeedMult(unsigned int race);
    float GetClimbSpeedMult(unsigned int race);
    float GetClimbStaminaCostMult(unsigned int race);
    float GetRollStaminaCostMult(unsigned int race);
    float GetDiveStaminaCostMult(unsigned int race);

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
};
