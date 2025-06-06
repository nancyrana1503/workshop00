// Name: Nancy Rana
// Seneca email: nrana18@myseneca.ca
// Seneca Student ID: 149951238
// Date: 6 June 2025
// timeMonitor.h
 
#pragma once
#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include <chrono>
#include <string>
#include "event.h"
namespace seneca {

    class TimeMonitor {
        std::chrono::steady_clock::time_point m_startTime;
        std::chrono::steady_clock::time_point m_endTime;
        std::string m_name;

    public:
        void startEvent(const char* name);
        Event stopEvent();
    };
}
#endif 