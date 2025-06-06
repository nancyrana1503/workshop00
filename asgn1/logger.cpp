// Name: Nancy Rana
// Seneca email: nrana18@myseneca.ca
// Seneca Student ID: 149951238
// Date: 6 June 2025
// logger.cpp

#include <iostream>
#include <string>
#include "logger.h"
using namespace std;
namespace seneca {

    //default constructor to initialize the loger with capacity for 10 events
    Logger::Logger() {
        m_events = new Event[10];
        m_capacity = 10;
        m_size = 0;
    }

    //destructor
    Logger::~Logger() {
        delete[] m_events;
    }

    //transfers owership of resources from another logger
    Logger::Logger(Logger&& other) noexcept : m_events(other.m_events), m_capacity(other.m_capacity), m_size(other.m_size) {
        other.m_events = nullptr;
        other.m_capacity = 0;
        other.m_size = 0;
    }

    //handels move asssignment and avoids deep copy
    Logger& Logger::operator=(Logger&& other) noexcept {        
        if (this != &other) {
            delete[] m_events;
            m_events = other.m_events;
            m_capacity = other.m_capacity;
            m_size = other.m_size;
            other.m_events = nullptr;
            other.m_capacity = 0;
            other.m_size = 0;
        }   return *this;
    }

    //add new event to the logger
    void Logger::addEvent(const Event& event) {        
        if (m_size == m_capacity) {
            int new_capacity = m_capacity * 2;
            Event* new_events = new Event[new_capacity];

            for (int i = 0; i < m_size; ++i) {
                new_events[i] = m_events[i];
            }
            delete[] m_events;
            m_events = new_events;
            m_capacity = new_capacity;
        }
        m_events[m_size++] = event;
    }

    ostream& operator<<(ostream& os, const Logger& logger) {        
        for (int i = 0; i < logger.m_size; ++i) {
            os << logger.m_events[i] << endl;
        } return os;
    } }
