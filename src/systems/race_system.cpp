#include "race_system.h"
#include "../memory_helper.h"

void RaceSystem::Update(cube::Creature* player) {
    if (player->entity_data.race != currentRace) {
        currentRace = player->entity_data.race;
        ApplyStaminaCostPatch(player);
    }
    ApplyAppearance(player);
}

void RaceSystem::ApplyAppearance(cube::Creature* player) {
    Race race = (Race)currentRace;

    switch (race) {
        case Race::ORK:
            if (player->entity_data.appearance.graphics_scale != 1.5f) {
                player->entity_data.appearance.graphics_scale = 1.5f;
                player->entity_data.appearance.hitbox_scale = 1.5f;
                player->entity_data.appearance.physics_scale = 3.3f;
            }
            break;

        case Race::GOBLIN:
            if (player->entity_data.appearance.graphics_scale != 0.7f) {
                player->entity_data.appearance.graphics_scale = 0.7f;
                player->entity_data.appearance.hitbox_scale = 0.7f;
                player->entity_data.appearance.physics_scale = 1.555f;
            }
            break;

        default:
            break;
    }
}

bool IsPlayer(cube::Creature* creature) {
    return creature->entity_data.classType >= 1 &&
        creature->entity_data.classType <= 4 &&
        creature->entity_data.hostility_type == 0;
}

float RaceSystem::GetHpMult(unsigned int race, unsigned char classType) {
    switch ((Race)race) {
    case Race::ELF:     return (classType == 3) ? 1.0f : 0.85f;
    case Race::HUMAN:   return 1.1f;
    case Race::GOBLIN:  return 0.5f;
    case Race::LIZARDMAN: return 1.0f;
    case Race::DWARF:   return 1.0f;
    case Race::ORK:     return 1.3f;
    case Race::FROGMAN: return 1.0f;
    case Race::UNDEAD:  return 0.75f;
    default:            return 1.0f;
    }
}

float RaceSystem::GetArmorMult(unsigned int race) {
    switch ((Race)race) {
    case Race::GOBLIN:  return 0.8f;
    case Race::DWARF:   return 1.3f;
    case Race::FROGMAN: return 0.85f;
    case Race::UNDEAD:  return 0.75f;
    default:            return 1.0f;
    }
}

float RaceSystem::GetAttackPowerMult(unsigned int race) {
    switch ((Race)race) {
    case Race::GOBLIN:  return 0.8f;
    case Race::ORK:     return 1.4f;
    case Race::UNDEAD:  return 1.2f;
    default:            return 1.0f;
    }
}

float RaceSystem::GetSpellPowerMult(unsigned int race) {
    switch ((Race)race) {
    case Race::ELF:     return 1.3f;
    case Race::FROGMAN: return 1.3f;
    default:            return 1.0f;
    }
}

float RaceSystem::GetCritMult(unsigned int race) {
    switch ((Race)race) {
    case Race::LIZARDMAN: return 1.2f;
    case Race::UNDEAD:    return 1.2f;
    default:              return 1.0f;
    }
}

float RaceSystem::GetHasteMult(unsigned int race) {
    switch ((Race)race) {
    case Race::GOBLIN:  return 1.3f;
    case Race::DWARF:   return 0.8f;
    case Race::ORK:     return 0.8f;
    case Race::UNDEAD:  return 1.2f;
    default:            return 1.0f;
    }
}

float RaceSystem::GetRegenMult(unsigned int race) {
    switch ((Race)race) {
    case Race::HUMAN:   return 1.2f;
    case Race::ORK:     return 0.7f;
    default:            return 1.0f;
    }
}

float RaceSystem::GetManaGenMult(unsigned int race) {
    switch ((Race)race) {
    case Race::ELF:     return 1.5f;
    default:            return 1.0f;
    }
}

float RaceSystem::GetSwimSpeedMult(unsigned int race) {
    switch ((Race)race) {
    case Race::LIZARDMAN: return 2.0f;
    case Race::FROGMAN:   return 2.5f;
    default:              return 1.0f;
    }
}

float RaceSystem::GetClimbSpeedMult(unsigned int race) {
    switch ((Race)race) {
    case Race::GOBLIN:  return 1.5f;
    default:            return 1.0f;
    }
}

float RaceSystem::GetClimbStaminaCostMult(unsigned int race) {
    switch ((Race)race) {
    case Race::ORK:     return 0.5f;
    default:            return 1.0f;
    }
}

float RaceSystem::GetRollStaminaCostMult(unsigned int race) {
    switch ((Race)race) {
    case Race::ORK:     return 0.5f;
    default:            return 1.0f;
    }
}

float RaceSystem::GetDiveStaminaCostMult(unsigned int race) {
    switch ((Race)race) {
    case Race::ORK:     return 0.5f;
    default:            return 1.0f;
    }
}

void RaceSystem::OnHPCalculated(cube::Creature* creature, float* hp) {
    if (IsPlayer(creature)) {
        *hp *= GetHpMult(creature->entity_data.race, creature->entity_data.classType);
    }
}

void RaceSystem::OnArmorCalculated(cube::Creature* creature, float* armor) {
    if (IsPlayer(creature)) {
        *armor *= GetArmorMult(creature->entity_data.race);
    }
}

void RaceSystem::OnAttackPowerCalculated(cube::Creature* creature, float* power) {
    if (IsPlayer(creature)) {
        *power *= GetAttackPowerMult(creature->entity_data.race);
    }
}

void RaceSystem::OnSpellPowerCalculated(cube::Creature* creature, float* power) {
    if (IsPlayer(creature)) {
        if (creature->entity_data.classType == 3 || creature->entity_data.race == 13) {
            *power *= GetSpellPowerMult(creature->entity_data.race);
        }
    }
}

void RaceSystem::OnCriticalCalculated(cube::Creature* creature, float* critical) {
    if (IsPlayer(creature)) {
        *critical *= GetCritMult(creature->entity_data.race);
    }
}

void RaceSystem::OnHasteCalculated(cube::Creature* creature, float* haste) {
    if (IsPlayer(creature)) {
        *haste *= GetHasteMult(creature->entity_data.race);
    }
}

void RaceSystem::OnRegenerationCalculated(cube::Creature* creature, float* regen) {
    if (IsPlayer(creature)) {
        *regen *= GetRegenMult(creature->entity_data.race);
    }
}

void RaceSystem::OnManaGenerationCalculated(cube::Creature* creature, float* manaGen) {
    if (IsPlayer(creature)) {
        *manaGen *= GetManaGenMult(creature->entity_data.race);
    }
}

void RaceSystem::ApplyStaminaCostPatch(cube::Creature* player) {
    uint64_t base = MemoryHelper::GetCubeBase();

    float* costAddr = (float*)(base + 0x472208);
    float newClimbCost = 0.00025f * GetClimbStaminaCostMult(player->entity_data.race);
    MemoryHelper::PatchMemory(costAddr, newClimbCost);

    float* rollCostAddr = (float*)(base + 0x4AC95C);
    float newRollCost = 0.25f * GetRollStaminaCostMult(player->entity_data.race);
    MemoryHelper::PatchMemory(rollCostAddr, newRollCost);

    float* diveCostAddr = (float*)(base + 0x472220);
    float newDiveCost = 0.001f * GetDiveStaminaCostMult(player->entity_data.race);
    MemoryHelper::PatchMemory(diveCostAddr, newDiveCost);
}
