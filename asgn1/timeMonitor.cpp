// Name: Nancy Rana
// Seneca email: nrana18@myseneca.ca
// Seneca Student ID: 149951238
// Date: 6 June 2025
//timeMonitor.cpp

#include <iostream>
#include <chrono>
#include "timeMonitor.h"
#include "event.h"
using namespace std;
namespace seneca {
    void TimeMonitor::startEvent(const char* name) {
        m_name = name;
        m_startTime = chrono::steady_clock::now();
    }

    Event TimeMonitor::stopEvent() {
        m_endTime = chrono::steady_clock::now();
        chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(m_endTime - m_startTime);
        return Event(m_name.c_str(), duration);
    } };