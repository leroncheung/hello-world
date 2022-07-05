/**
 * @file weather_station.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "weather_station.h"

WeatherStation::WeatherStation(std::string name) : m_station_name(name) {
}

WeatherStation::WeatherStation(std::string name, WeatherInfo weather_info) : m_station_name(name), m_weather_info(weather_info) {
}

void WeatherStation::registerCbFunc(const std::string observer_name, const CallbackFunc& cb) {
    std::lock_guard<std::mutex> guard(m_mutex);
    m_callback_funcs[observer_name] = cb;
}

void WeatherStation::unregisterCbFunc(const std::string observer_name) {
    std::lock_guard<std::mutex> guard(m_mutex);
    m_callback_funcs.erase(observer_name);
}

void WeatherStation::updateWeatherInfo(const WeatherInfo weather_info) {
    std::lock_guard<std::mutex> guard(m_mutex);
    m_weather_info = weather_info;
    for_each(std::cbegin(m_callback_funcs), std::cend(m_callback_funcs), [&weather_info](auto elem)
             { elem.second(weather_info); });
}

void WeatherStation::showWeatherStationInfo() const {
    std::cout << "Station Name: " << m_station_name << std::endl;
    std::cout << m_weather_info << std::endl << std::endl;
}