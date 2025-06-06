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
