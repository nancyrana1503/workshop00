#pragma once

// Name: Nancy Rana
// Seneca email: nrana18@myseneca.ca
// Seneca Student ID: 149951238
// Date: 12 June 2025
// characterTpl.h

#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H
#include "character.h"
#include "health.h"
#include "abilities.h"
#include "weapons.h"
namespace seneca {

    template <typename T>
    class CharacterTpl : public Character {

	T m_health{};
        int m_healthMax{};

    public:
		//constructor with name and max health
        CharacterTpl(const char* chName, int maxHealth) : Character(chName) {
            m_healthMax = maxHealth;
            m_health = maxHealth;
        }
		//copy constructor
        CharacterTpl(const CharacterTpl& src) : Character(src.getName().c_str()) {
            m_health = src.m_health;
            m_healthMax = src.m_healthMax;
        }
        //damage handler
        void takeDamage(int dmg) override {
            m_health -= dmg;
            if (m_health <= 0) {
                m_health = 0;
                std::cout << "    " << getName() << " has been defeated!" << std::endl;
            }
            else {
                std::cout << "    " << getName() << " took " << dmg << " damage, " << m_health << " health remaining." 
			  << std::endl;
            }
        }
        //current health accessor
        int getHealth() const override {
            return static_cast<int>(m_health);
        }

		//maximum health accessor
        int getHealthMax() const override {
            return m_healthMax;
        }

		//sets the current health to the value received as parameter
        void setHealth(int health) override {
            m_health = health;
        }

		//sets the maximum health and resets current health 
        void setHealthMax(int health) override {
            m_healthMax = health;
            m_health = health;
        }
    };
} #endif 

