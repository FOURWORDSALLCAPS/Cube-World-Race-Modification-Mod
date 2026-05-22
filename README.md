# Cube-World-Race-Modification-Mod

A mod for Cube World that adds racial traits to characters.
Each race receives unique bonuses and penalties to their stats.

## Installing

1. Install [Cube World Mod Launcher](https://github.com/ChrisMiuchiz/Cube-World-Mod-Launcher)
2. Download `RaceModificationMod.dll` from [releases](https://github.com/FOURWORDSALLCAPS/Cube-World-Race-Modification-Mod/releases)
3. Place `.dll` in `Mods` folder
4. Launch the game

## Racial Traits

| Race | Bonuses | Penalties |
|------|---------|-----------|
| **Human** | +10% Max HP, +20% Stamina Regeneration | — |
| **Elf (Mage)** | +30% Spell Power, +50% Mana Generation | — |
| **Elf (Other)** | +30% Mana on Hit | -15% Max HP |
| **Dwarf** | +30% Armor, +50% Lamp Radius | -20% Attack Speed |
| **Ork** | +40% Attack Power, +30% Max HP, +30% Size | -30% Stamina Regen, -20% Attack Speed |
| **Goblin** | +30% Attack Speed, +50% Climbing Speed, -30% Size | -20% Attack Power, -20% Armor |
| **Lizardman** | +100% Swimming Speed, +20% Critical Chance | — |
| **Undead** | +20% Attack Speed, +20% Attack Power, +20% Critical Chance | -25% Max HP, -25% Armor |
| **Frogman** | +150% Swimming Speed, +30% Spell Power | -15% Armor |

## How It Works

- Bonuses and penalties are applied as percentage multipliers to base stats.
- Changes take effect immediately upon entering the game with a character.
- Stats affected: Max HP, Armor, Attack Power, Spell Power, Critical Chance, Attack Speed, Stamina Regeneration, Mana Generation, Size, Swimming Speed, Climbing Speed, Lamp Radius.
- Elf bonuses depend on class: Mage receives Spell Power and Mana Generation bonuses; other classes receive Mana on Hit but suffer HP penalty.
- All stat modifications are applied via the game's own calculation callbacks, ensuring compatibility with equipment, potions, and other stat-affecting mechanics.
