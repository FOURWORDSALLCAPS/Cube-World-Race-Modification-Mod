#include "race_system.h"
#include "../memory_helper.h"

void RaceSystem::Update(cube::Creature* player) {
    if (player->entity_data.race != currentRace) {
        currentRace = player->entity_data.race;
        ApplyBonuses(player);
    }
}

void RaceSystem::ApplyBonuses(cube::Creature* player) {
    hpMult = 1.0f;
    armorMult = 1.0f;
    attackPowerMult = 1.0f;
    spellPowerMult = 1.0f;
    critMult = 1.0f;
    hasteMult = 1.0f;
    regenMult = 1.0f;
    manaGenMult = 1.0f;
    swimSpeedMult = 1.0f;
    climbSpeedMult = 1.0f;
    staminaCostMult = 1.0f;

    Race race = (Race)currentRace;

    switch (race) {
    case Race::HUMAN:
        hpMult = 1.1f;
        regenMult = 1.2f;
        break;

    case Race::ELF: {
        Class cls = (Class)player->entity_data.classType;
        if (cls == Class::MAGE) {
            spellPowerMult = 1.3f;
            manaGenMult = 1.5f;
        }
        else {
            hpMult = 0.85f;
            manaGenMult = 1.3f;
        }
        break;
    }

    case Race::DWARF:
        armorMult = 1.3f;
        hasteMult = 0.8f;
        break;

    case Race::ORK:
        attackPowerMult = 1.4f;
        hpMult = 1.3f;
        regenMult = 0.7f;
        hasteMult = 0.8f;
        staminaCostMult = 0.5f;
        player->entity_data.appearance.graphics_scale = 1.3f;
        player->entity_data.appearance.hitbox_scale = 1.3f;
        player->entity_data.appearance.physics_scale = 1.3f;
        break;

    case Race::GOBLIN:
        hasteMult = 1.3f;
        climbSpeedMult = 1.5f;
        attackPowerMult = 0.8f;
        armorMult = 0.8f;
        player->entity_data.appearance.graphics_scale = 0.7f;
        player->entity_data.appearance.hitbox_scale = 0.7f;
        player->entity_data.appearance.physics_scale = 0.7f;
        break;

    case Race::LIZARDMAN:
        swimSpeedMult = 2.0f;
        critMult = 1.2f;
        break;

    case Race::UNDEAD:
        hasteMult = 1.2f;
        attackPowerMult = 1.2f;
        critMult = 1.2f;
        hpMult = 0.75f;
        armorMult = 0.75f;
        break;

    case Race::FROGMAN:
        swimSpeedMult = 2.5f;
        spellPowerMult = 1.3f;
        armorMult = 0.85f;
        break;
    }

    ApplyStaminaCostPatch(player);
}

void RaceSystem::OnHPCalculated(cube::Creature* creature, float* hp) {
    *hp *= hpMult;
}

void RaceSystem::OnArmorCalculated(cube::Creature* creature, float* armor) {
    *armor *= armorMult;
}

void RaceSystem::OnAttackPowerCalculated(cube::Creature* creature, float* power) {
    *power *= attackPowerMult;
}

void RaceSystem::OnSpellPowerCalculated(cube::Creature* creature, float* power) {
    *power *= spellPowerMult;
}

void RaceSystem::OnCriticalCalculated(cube::Creature* creature, float* critical) {
    *critical *= critMult;
}

void RaceSystem::OnHasteCalculated(cube::Creature* creature, float* haste) {
    *haste *= hasteMult;
}

void RaceSystem::OnRegenerationCalculated(cube::Creature* creature, float* regen) {
    *regen *= regenMult;
}

void RaceSystem::OnManaGenerationCalculated(cube::Creature* creature, float* manaGen) {
    *manaGen *= manaGenMult;
}

void RaceSystem::OnSwimSpeedCalculated(cube::Creature* creature, float* speed) {
    *speed *= swimSpeedMult;
}

void RaceSystem::OnClimbSpeedCalculated(cube::Creature* creature, float* speed) {
    *speed *= climbSpeedMult;
}

void RaceSystem::ApplyStaminaCostPatch(cube::Creature* player) {
    uint64_t base = MemoryHelper::GetCubeBase();
    float* costAddr = (float*)(base + 0x472208);
    float newCost = 0.00025f * staminaCostMult;
    MemoryHelper::PatchMemory(costAddr, newCost);
}
