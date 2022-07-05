/**
 * @file weather_info.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "weather_info.h"

WeatherInfo::WeatherInfo(std::string location, int16_t temprature, int16_t humidness) : m_location(location), m_temprature(temprature), m_humidness(humidness) {
}

WeatherInfo::WeatherInfo(const WeatherInfo& weather_info) {
    m_location = weather_info.m_location;
    m_temprature = weather_info.m_temprature;
    m_humidness = weather_info.m_humidness;
}

WeatherInfo& WeatherInfo::operator=(const WeatherInfo& weather_info) {
    if (this == &weather_info) {
        return *this;
    }
    m_location = weather_info.m_location;
    m_temprature = weather_info.m_temprature;
    m_humidness = weather_info.m_humidness;
    return *this;
}

WeatherInfo::WeatherInfo(WeatherInfo&& weather_info) {
    m_location = weather_info.m_location;
    m_temprature = weather_info.m_temprature;
    m_humidness = weather_info.m_humidness;
}

WeatherInfo& WeatherInfo::operator=(WeatherInfo&& weather_info) {
    if (this == &weather_info) {
        return *this;
    }
    m_location = weather_info.m_location;
    m_temprature = weather_info.m_temprature;
    m_humidness = weather_info.m_humidness;
    return *this;
}

std::ostream& operator << (std::ostream& ostr, const WeatherInfo& weather_info) {
    ostr << "Location: " << weather_info.m_location << std::endl;
    ostr << "        Temprature: " << weather_info.m_temprature << " °C" << std::endl;
    ostr << "        Humidness: " << weather_info.m_humidness << " %rh" << std::endl;
    return ostr;
}

std::string WeatherInfo::getLocation() const {
    return m_location;
}