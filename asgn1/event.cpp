// Name: Nancy Rana
// Seneca email: nrana18@myseneca.ca
// Seneca Student ID: 149951238
// Date: 6 June 2025
// event.cpp
 
#include <iostream>
#include <chrono>
#include <string>
#include "event.h"
#include <iomanip>
#include "settings.h"
using namespace std;
namespace seneca {
    
    // default constructor to initialize the event with empty name and duration 0
    Event::Event() : m_event_name(""), m_duration(chrono::nanoseconds(0)) {}
    //constructot to initialize the event with a name and duration
    Event::Event(const char* name, const chrono::nanoseconds& duration) : m_event_name(name), m_duration(duration) {}

    //display event details
    ostream& operator<<(ostream& os, const Event& event) {
        static unsigned counter = 0;
        counter++;
        os << right << setw(2) << counter << ": "  //print with proper alignment
            << right << setw(40) << event.m_event_name
            << " -> ";

        //print duration
        if (g_settings.m_time_units == "seconds") {            
            os << right << setw(2) << chrono::duration_cast<chrono::seconds>(event.m_duration).count();
        }
        else if (g_settings.m_time_units == "milliseconds") {
            os << right << setw(5) << chrono::duration_cast<chrono::milliseconds>(event.m_duration).count();
        }
        else if (g_settings.m_time_units == "microseconds") {
            os << right << setw(8) << chrono::duration_cast<chrono::microseconds>(event.m_duration).count();
        }
        else {
            os << right << setw(11) << chrono::duration_cast<chrono::nanoseconds>(event.m_duration).count();
        }
        os << " " << g_settings.m_time_units;
        return os;
    }};