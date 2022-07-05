/**
 * @file weather_info.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _WEATHER_INFO_H_
#define _WEATHER_INFO_H_

#include <iostream>
#include <string>

class WeatherInfo {
friend std::ostream &operator<<(std::ostream &ostr, const WeatherInfo &weather_info);

public:
    WeatherInfo() = default;
    WeatherInfo(std::string location, int16_t temprature, int16_t humidness);
    WeatherInfo(const WeatherInfo &weather_info);
    WeatherInfo& operator=(const WeatherInfo &weather_info);
    WeatherInfo(WeatherInfo &&weather_info);
    WeatherInfo& operator=(WeatherInfo &&weather_info);
    virtual ~WeatherInfo() = default;

    std::string getLocation() const;

protected:
    std::string m_location;
    int16_t m_temprature = 0;    // -256 ~ 255, C++11类内初始值
    int16_t m_humidness = 0;     // -256 ~ 255
};

std::ostream &operator<<(std::ostream &ostr, const WeatherInfo &weather_info);

#endif // _WEATHER_INFO_H_