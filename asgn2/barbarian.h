#pragma once



#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H

#include "character.h"
#include "characterTpl.h"

namespace seneca {
    template <typename T, typename Ability_t, typename Weapon_t>
    class Barbarian : public CharacterTpl<T> {
        int m_baseDefense{};
        int m_baseAttack{};
        Ability_t m_ability{};
        Weapon_t m_weapon[2]{};

    public:
        //constructor
        Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon,
            Weapon_t secondaryWeapon) : CharacterTpl<T>(name, healthMax) {
            m_baseAttack = baseAttack;
            m_baseDefense = baseDefense;
            m_weapon[0] = primaryWeapon;
            m_weapon[1] = secondaryWeapon;
        }
        //get the tootal attack amount
        int getAttackAmnt() const override {
            return m_baseAttack + (static_cast<double>(m_weapon[0]) / 2)
                + (static_cast<double>(m_weapon[1]) / 2);
        }
        // get the total defense amount
        int getDefenseAmnt() const override {
            return m_baseDefense;
        }
        // get the current health
        Character* clone() const override {
            return new Barbarian(*this);
        }
        //attack method
        void attack(Character* enemy) override {
            std::cout << Character::getName() << " is attacking " << enemy->getName() << "." << std::endl;
            m_ability.useAbility(this);
            int damage = getAttackAmnt();
            m_ability.transformDamageDealt(damage);

            std::cout << "    Barbarian deals " << damage << " melee damage!" << std::endl;
            enemy->takeDamage(damage);
        }

        void takeDamage(int damage) override {
            std::cout << Character::getName() << " is attacked for " << damage << " damage." << std::endl;
            std::cout << "    Barbarian has a defense of " << m_baseDefense << ". Reducing damage received." << std::endl;
            damage -= m_baseDefense;
            damage = damage < 0 ? 0 : damage;
            m_ability.transformDamageReceived(damage);
            CharacterTpl<T>::takeDamage(damage);
        }
    };
}
#endif 

