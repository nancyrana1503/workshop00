#pragma once

#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
#include "characterTpl.h"
namespace seneca {

    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    class Rogue : public CharacterTpl<T> {
    
        int m_baseDefense;
        int m_baseAttack;
        FirstAbility_t m_firstAbility;
        SecondAbility_t m_secondAbility;
        seneca::Dagger m_weapon;

    public:
		
        // Constructor for Rogue class
        Rogue(const char* name, int healthMax, int baseAttack, int baseDefense)
            : CharacterTpl<T>(name, healthMax) {
            m_baseAttack = baseAttack;
            m_baseDefense = baseDefense;
        }
		
        //get the total attack amount
        int getAttackAmnt() const override {
        
            return m_baseAttack + 2 * m_weapon.m_damage;
        }
		
        // get the total defense amount
        int getDefenseAmnt() const override {
        
            return m_baseDefense;
        }
		
        // clone method to create a copy of the Rogue
        Character* clone() const override {
        
            return new Rogue(*this);
        }
		
        // attack method for the Rogue
        void attack(Character* enemy) override {
        
            std::cout << Character::getName() << " is attacking " << enemy->getName() << "." << std::endl;
            m_firstAbility.useAbility(this);
            m_secondAbility.useAbility(this);
            
            int dmg = getAttackAmnt();
            
            m_firstAbility.transformDamageDealt(dmg);
            m_secondAbility.transformDamageDealt(dmg);
            
            std::cout << "    Rogue deals " << dmg << " melee damage!" << std::endl;
            enemy->takeDamage(dmg);
        }
		
        // takeDamage method to handle damage taken by the Rogue
        void takeDamage(int dmg) override {
        
            std::cout << Character::getName() << " is attacked for " << dmg << " damage." << std::endl;
            std::cout << "    Rogue has a defense of " << m_baseDefense << ". Reducing damage received." << std::endl;
            
            dmg -= m_baseDefense;
            dmg = dmg < 0 ? 0 : dmg;
            
            m_firstAbility.transformDamageReceived(dmg);
            m_secondAbility.transformDamageReceived(dmg);
            
            CharacterTpl<T>::takeDamage(dmg);
        }
    };}
#endif 

