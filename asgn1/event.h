// Name: Nancy Rana
// Seneca email: nrana18@myseneca.ca
// Seneca Student ID: 149951238
// Date: 6 June 2025
// event.h

#pragma once
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
#include <iostream>
#include <chrono>
#include <string>
namespace seneca
{
    class Event {
        std::string m_event_name;
        std::chrono::nanoseconds m_duration;

    public:
        Event();
        Event(const char* name, const std::chrono::nanoseconds& duration);

        friend std::ostream& operator<<(std::ostream& os, const Event& event);
    };
}
#endif 
