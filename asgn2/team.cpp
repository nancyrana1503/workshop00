#include "team.h"
#include <iostream>

namespace seneca {

	/// Default constructor initializes an empty team
    Team::Team() : m_characters(nullptr), m_memberCount(0), m_name("") {}

	/// Constructor initializes a team with a given name
    Team::Team(const char* name) : m_characters(nullptr), m_memberCount(0), m_name(name) {}

	/// Copy constructor creates a deep copy of another team
    Team::Team(const Team& other) {
        *this = other;
    }
	/// Copy assignment operator creates a deep copy of another team
    Team& Team::operator=(const Team& other) {

        if (this != &other) {
            
            clear();

            m_name = other.m_name;
            m_memberCount = other.m_memberCount;
            m_characters = new Character * [m_memberCount];

            for (int i = 0; i < m_memberCount; ++i) {
        
                m_characters[i] = other.m_characters[i]->clone();
            }
        }
        return *this;    }

    Team::~Team() {
        
        clear();
    }

    Team::Team(Team&& other) noexcept {
     
        *this = std::move(other);
    }

	/// Move assignment operator transfers ownership of resources from another team
    Team& Team::operator=(Team&& other) noexcept {
        
        if (this != &other) {
        
            clear();

            m_name = std::move(other.m_name);
            m_characters = other.m_characters;
            m_memberCount = other.m_memberCount;

            other.m_characters = nullptr;
            other.m_memberCount = 0;
        }
        return *this;    }

	/// Helper function to clear the team members and free memory
    void Team::clear() {
        
        for (int i = 0; i < m_memberCount; ++i) {
            
            delete m_characters[i];
        }
        delete[] m_characters;
        
        m_characters = nullptr;
        m_memberCount = 0;
    }

    int Team::locate(const std::string& characterName) const {
        
        for (int i = 0; i < m_memberCount; ++i) {
        
            if (m_characters[i]->getName() == characterName) {
            
                return i;
            }
        }
        return -1;    }

    void Team::addMember(const Character* newChar) {
        
        if (locate(newChar->getName()) != -1)
        
            return;

        Character** temp = new Character * [m_memberCount + 1];
        
        for (int i = 0; i < m_memberCount; ++i) {
           temp[i] = m_characters[i];
        }

        temp[m_memberCount] = newChar->clone();
        delete[] m_characters;
        
        m_characters = temp;
        ++m_memberCount;
    }

    void Team::removeMember(const std::string& name) {
        
        int index = locate(name);
        
        if (index == -1) return;

        delete m_characters[index];
        
        for (int i = index; i < m_memberCount - 1; ++i) {
            m_characters[i] = m_characters[i + 1];
        }
        --m_memberCount;
    }

}