// Name: Nancy Rana
// Seneca email: nrana18@myseneca.ca
// Seneca Student ID: 149951238
// Date: 6 June 2025
// settings.h

#pragma once
#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

#include <string>
namespace seneca {
    class Settings {
    public:
        bool m_show_all;
        bool m_verbose;
       
        std::string m_time_units = "nanoseconds"; //values possible
    };

    extern Settings g_settings;
}
#endif 
