#pragma once
// Name: Nancy Rana
// Seneca email: nrana18@myseneca.ca
// Seneca Student ID: 149951238
// Date: 12 June 2025
// team.h


#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H

#include <string>
#include "character.h"

namespace seneca {

    class Team {
        std::string m_name{};
        int m_memberCount{};
        Character** m_characters{};
        void clear(); 
        int locate(const std::string& name) const;  // Replaces findMember

    public:
        Team();
        Team(const char* name);

        Team(const Team& other);
        Team& operator=(const Team& other);
        Team(Team&& other) noexcept;
        Team& operator=(Team&& other) noexcept;
        ~Team();

        void addMember(const Character* character);
        void removeMember(const std::string& name);

        Character* operator[](size_t index) const;
        void showMembers() const;
    };
}

#endif 
