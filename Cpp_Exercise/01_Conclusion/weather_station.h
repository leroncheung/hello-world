/**
 * @file weather_station.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _WEATHER_STATION_H_
#define _WEATHER_STATION_H_

#include <unordered_map>
#include <mutex>
#include <string>
#include <functional>
#include "weather_info.h"

using CallbackFunc = std::function<void(WeatherInfo)>;

class WeatherStation final {
public:
    WeatherStation() = default;
    WeatherStation(std::string name);
    WeatherStation(std::string name, WeatherInfo weather_info);
    WeatherStation(const WeatherStation &weather_station) = delete;
    WeatherStation &operator=(const WeatherStation &weather_station) = delete;
    WeatherStation(WeatherStation &&weather_station) = delete;
    WeatherStation &operator=(WeatherStation &&weather_station) = delete;
    ~WeatherStation() = default;
    void registerCbFunc(const std::string observer_name, const CallbackFunc &cb);
    void unregisterCbFunc(const std::string observer_name);
    void updateWeatherInfo(const WeatherInfo weather_info);
    void showWeatherStationInfo() const;

private:
    std::string m_station_name;
    std::mutex m_mutex;
    WeatherInfo m_weather_info;
    std::unordered_map<std::string, CallbackFunc> m_callback_funcs;
};

#endif // _WEATHER_STATION_H_