#pragma once

#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H

#include <string>
#include "character.h"

namespace seneca {

    class Team {
        std::string m_name{};
        int m_memberCount{};
        Character** m_characters{};

        void clear();  // Helper to clean up dynamic memory

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

} // namespace seneca

#endif // SENECA_TEAM_H
