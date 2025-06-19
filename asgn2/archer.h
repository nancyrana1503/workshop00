#pragma once

#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H

#include "characterTpl.h"
#include "health.h"

namespace seneca {
    template <typename Weapon_t>
    class Archer : public CharacterTpl<seneca::SuperHealth> {
        double m_baseDefense{};
        double m_baseAttack{};
        Weapon_t m_weapon;

    public:
        //constructor
        Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon)
            : CharacterTpl<seneca::SuperHealth>(name, healthMax) {
            m_baseAttack = baseAttack;
            m_baseDefense = baseDefense;
            m_weapon = weapon;
        }
		//get the total attack amount
        int getAttackAmnt() const override {
            return 1.3 * m_baseAttack;
        }
		// get the total defense amount
        int getDefenseAmnt() const override {
            return 1.2 * m_baseDefense;
        }
		// clone method to create a copy of the Archer
        Character* clone() const override {
            return new Archer(*this);
        }
		// attack method
        void attack(Character* enemy) override {
            std::cout << getName() << " is attacking " << enemy->getName() << "." << std::endl;
            int dmg = getAttackAmnt();
            std::cout << "    Archer deals " << dmg << " ranged damage!" << std::endl;
            enemy->takeDamage(dmg);
        }
		// takeDamage method to handle damage taken by the Archer
        void takeDamage(int damage) override {
            std::cout << getName() << " is attacked for " << damage << " damage." << std::endl;
            std::cout << "    Archer has a defense of " << m_baseDefense << ". Reducing damage received." << std::endl;
            damage -= m_baseDefense;
            damage = damage < 0 ? 0 : damage;
            CharacterTpl<seneca::SuperHealth>::takeDamage(damage);
        }
    };
}
#endif

