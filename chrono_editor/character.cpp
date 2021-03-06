/***************************************************************************
 * Copyright (C) 2010 Lemay, Mathieu                                       *
 *                                                                         *
 * This program is free software; you can redistribute it and/or modify    *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation; either version 2 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * This program is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License along *
 * with this program; if not, write to the Free Software Foundation, Inc., *
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.             *
 *                                                                         *
 * You can contact the original author at acidrain1@gmail.com              *
 ***************************************************************************/

#include "character.h"

Character::Character(character_t *character) {
    _char = character;
}

u8 Character::getId() {
    return _char->id;
}

void Character::setId(u8 id) {
    _char->id = id;
}

u8 Character::getCharId() {
    return _char->charId;
}

void Character::setCharId(u8 charId) {
    _char->charId = charId;
}

u16 Character::getCurrentHP() {
    return _char->currentHP;
}

void Character::setCurrentHP(u16 currentHP) {
    _char->currentHP = currentHP > 999 ? 999 : currentHP;
}

u16 Character::getMaxHP() {
    return _char->maxHP;
}

void Character::setMaxHP(u16 maxHP) {
    _char->maxHP = maxHP > 999 ? 999 : maxHP;
}

u16 Character::getCurrentMP() {
    return _char->currentMP;
}

void Character::setCurrentMP(u16 currentMP) {
    _char->currentMP = currentMP > 999 ? 999 : currentMP;
}

u16 Character::getMaxMP() {
    return _char->maxMP;
}

void Character::setMaxMP(u16 maxMP) {
    _char->maxMP = maxMP > 99 ? 99 : maxMP;
}

u8 Character::getBasePower() {
    return _char->basePower;
}

u8 Character::getBaseStamina() {
    return _char->baseStamina;
}

u8 Character::getBaseSpeed() {
    return _char->baseSpeed;
}

u8 Character::getBaseMagic() {
    return _char->baseMagic;
}

u8 Character::getBaseHit() {
    return _char->baseHit;
}

u8 Character::getBaseEvade() {
    return _char->baseEvade;
}

u8 Character::getBaseMagicDef() {
    return _char->baseMagicDef;
}

u8 Character::getLevel() {
    return _char->level;
}

u32 Character::getExp() {
    return _char->exp & 0x00ffffff;
}

u8 Character::getHelmet() {
    return _char->helmet;
}

u8 Character::getArmor() {
    return _char->armor;
}

u8 Character::getWeapon() {
    return _char->weapon;
}

u8 Character::getRelic() {
    return _char->relic;
}

u16 Character::getXpForLevelUp() {
    return _char->xpForLevelUp;
}

u16 Character::getSpForNextTech() {
    return _char->spForNextTech;
}

void Character::setBasePower(u8 basePower) {
    if (basePower > 99)
        basePower = 99;

    _char->basePower = basePower;
}

void Character::setBaseStamina(u8 baseStamina) {
    if (baseStamina > 99)
        baseStamina = 99;

    _char->baseStamina = baseStamina;
}

void Character::setBaseSpeed(u8 baseSpeed) {
    if (baseSpeed > 16)
        baseSpeed = 16;

    _char->baseSpeed = baseSpeed;
}

void Character::setBaseMagic(u8 baseMagic) {
    if (baseMagic > 99)
        baseMagic = 99;

    _char->baseMagic = baseMagic;
}

void Character::setBaseHit(u8 baseHit) {
    if (baseHit > 99)
        baseHit = 99;

    _char->baseHit = baseHit;
}

void Character::setBaseEvade(u8 baseEvade) {
    if (baseEvade > 99)
        baseEvade = 99;

    _char->baseEvade = baseEvade;
}

void Character::setBaseMagicDef(u8 baseMagicDef) {
    if (baseMagicDef > 99)
        baseMagicDef = 99;

    _char->baseMagicDef = baseMagicDef;
}

void Character::setLevel(u8 level) {
    if (level > 99)
        level = 99;

    _char->level = level;
}

void Character::setExp(u32 exp) {
    if (exp > 9999999)
        exp = 9999999;

    //  Keep the high byte, exp is only 24bit
    _char->exp = (_char->exp & 0xff000000) | exp;
}

void Character::setHelmet(u8 helmet) {
    if (helmet < 0x7c)
        helmet = 0x7c;
    else if (helmet > 0x93)
        helmet = 0x93;

    _char->helmet = helmet;
}

void Character::setArmor(u8 armor) {
    if (armor < 0x5b)
        armor = 0x5b;
    else if (armor > 0x7a)
        armor = 0x7a;

    _char->armor = armor;
}

void Character::setWeapon(u8 weapon) {
    if (checkIfWeaponOK(weapon))
        _char->weapon = weapon;
}

void Character::setRelic(u8 relic) {
    if (relic < 0x95)
        relic = 0x95;
    else if (relic > 0xbb)
        relic = 0xbb;

    _char->relic = relic;
}

void Character::setXpForLevelUp(u16 xp) {
    _char->xpForLevelUp = xp;
}

void Character::setSpForNextTech(u16 sp) {
    _char->spForNextTech = sp;
}

bool Character::checkIfWeaponOK(u8 wpn) {
    switch (_char->id) {
        case CRONO:
            if ((wpn >= 0x01 && wpn <= 0x10) || wpn == 0x4f || (wpn >= 0x53 && wpn <= 0x55))
                return true;
            else
                return false;
        case MARLE:
            if (wpn >= 0x11 && wpn <= 0x1a)
                return true;
            else
                return false;
        case LUCCA:
            if (wpn >= 0x1f && wpn <= 0x29)
                return true;
            else
                return false;
        case ROBO:
            if (wpn >= 0x2e && wpn <= 0x39)
                return true;
            else
                return false;
        case FROG:
            if ((wpn >= 0x3b && wpn <= 0x43) || (wpn >= 0x50 && wpn <= 0x52))
                return true;
            else
                return false;
        case AYLA:
            if (wpn >= 0x44 && wpn <= 0x48)
                return true;
            else
                return false;
        case MAGUS:
            if (wpn >= 0x4b && wpn <= 0x4e)
                return true;
            else
                return false;
        default:
            return false;
    }
}
