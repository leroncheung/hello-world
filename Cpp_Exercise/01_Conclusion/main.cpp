#include <memory>
#include "weather_station.h"
#include "observer.h"

int main() {
    WeatherInfo wuhan_weather_info("WuHan", 28, 34);
    WeatherStation wuhan_weather_station("WuHan Station", wuhan_weather_info);
    WeatherInfo shanghai_weather_info("ShangHai", 27, 45);
    WeatherStation shanghai_weather_station("ShangHai Station", shanghai_weather_info);
    std::shared_ptr<Observer> observer_1 = std::make_shared<Observer>("ZhangSan");
    CallbackFunc func1 = std::bind(&Observer::updateWeatherInfo, observer_1, std::placeholders::_1);
    std::shared_ptr<Observer> observer_2 = std::make_shared<Observer>("LiSi");
    CallbackFunc func2 = std::bind(&Observer::updateWeatherInfo, observer_2, std::placeholders::_1);

    wuhan_weather_station.registerCbFunc(observer_1->getObserverName(), func1);
    wuhan_weather_station.registerCbFunc(observer_2->getObserverName(), func2);
    shanghai_weather_station.registerCbFunc(observer_2->getObserverName(), func2);

    wuhan_weather_station.updateWeatherInfo(wuhan_weather_info);
    shanghai_weather_station.updateWeatherInfo(shanghai_weather_info);

    observer_1->showWeatherInfos();
    observer_2->showWeatherInfos();

    wuhan_weather_station.unregisterCbFunc(observer_2->getObserverName());
    observer_2->deleteWeatherInfo(wuhan_weather_info.getLocation());

    wuhan_weather_info = WeatherInfo("WuHan", 26, 55);
    wuhan_weather_station.updateWeatherInfo(wuhan_weather_info);
    observer_1->showWeatherInfos();
    observer_2->showWeatherInfos();

    return 0;
}