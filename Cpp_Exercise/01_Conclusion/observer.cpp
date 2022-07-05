/**
 * @file observer.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "observer.h"

Observer::Observer(std::string observer_name) : m_observer_name(observer_name) {
}

// 待回调函数，被动调用。由订阅者统一调用。
void Observer::updateWeatherInfo(WeatherInfo weather_info) {
    m_weather_infos[weather_info.getLocation()] = weather_info;
}

void Observer::showWeatherInfos() const {
    std::cout << "Name: " << m_observer_name << std::endl;
    for_each(std::cbegin(m_weather_infos), std::cend(m_weather_infos), [](auto elem)
             { std::cout << elem.second; });
    std::cout << std::endl;
}

std::string Observer::getObserverName() const {
    return m_observer_name;
}

void Observer::deleteWeatherInfo(std::string location) {
    m_weather_infos.erase(location);
}