#include "team.h"
#include <iostream>

namespace seneca {

    Team::Team() : m_characters(nullptr), m_memberCount(0), m_name("") {}

    Team::Team(const char* name) : m_characters(nullptr), m_memberCount(0), m_name(name) {}

    Team::Team(const Team& other) { *this = other; }

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
        return *this;
    }

    Team::~Team() {
        clear();
    }

    Team::Team(Team&& other) noexcept {
        *this = std::move(other);
    }

    Team& Team::operator=(Team&& other) noexcept {
        if (this != &other) {
            clear();

            m_name = std::move(other.m_name);
            m_characters = other.m_characters;
            m_memberCount = other.m_memberCount;

            other.m_characters = nullptr;
            other.m_memberCount = 0;
        }
        return *this;
    }

    void Team::clear() {
        if (m_characters) {
            for (int i = 0; i < m_memberCount; ++i) {
                delete m_characters[i];
            }
            delete[] m_characters;
        }
        m_characters = nullptr;
        m_memberCount = 0;
    }

    int Team::locate(const std::string& characterName) const {
        for (int i = 0; i < m_memberCount; ++i) {
            if (m_characters[i]->getName() == characterName) {
                return i;
            }
        }
        return -1;
    }

    void Team::addMember(const Character* newChar) {
        if (!newChar || locate(newChar->getName()) != -1)
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

    Character* Team::operator[](size_t index) const {
        return (index < static_cast<size_t>(m_memberCount)) ? m_characters[index] : nullptr;
    }

    void Team::showMembers() const {
        if (m_name.empty() && m_memberCount == 0) {
            std::cout << "No team." << std::endl;
            return;
        }

        std::cout << "[Team] " << m_name << std::endl;
        for (int i = 0; i < m_memberCount; ++i) {
            std::cout << "    " << (i + 1) << ": " << *m_characters[i] << std::endl;
        }
    }

}
