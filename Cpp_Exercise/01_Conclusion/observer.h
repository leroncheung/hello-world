/**
 * @file observer.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <unordered_map>
#include <string>
#include "weather_info.h"

class Observer {
public:
    Observer() = default;
    Observer(std::string observer_name);
    Observer(const Observer &observer) = delete;
    Observer& operator=(const Observer &observer) = delete;
    Observer(Observer &&observer) = delete;
    Observer& operator=(Observer &&observer) = delete;
    virtual ~Observer() = default;
    void updateWeatherInfo(WeatherInfo weather_info);
    void deleteWeatherInfo(std::string location);
    void showWeatherInfos() const;
    void queryWeather(const std::string location) const;
    std::string getObserverName() const;

protected:
    std::string m_observer_name;
    std::unordered_map<std::string, WeatherInfo> m_weather_infos;
};

#endif // _OBSERVER_H_