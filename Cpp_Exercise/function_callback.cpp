// ÆøÏóÕ¾
#include <iostream>
#include <functional>
#include <map>
#include <mutex>
#include <memory>

typedef std::function<void(int)> CallbackFun;
 
class WeatherStation
{
public:
	WeatherStation() : _id(0) {}
	~WeatherStation() {}
 
	uint64_t registerCbFun(const CallbackFun& cb) {
		std::lock_guard<std::mutex> guard(_mutex);
		_callbackFuns[_id++] = cb;
		return _id;
	}
 
	void unregisterCbFun(uint64_t id) {
		std::lock_guard<std::mutex> guard(_mutex);
		_callbackFuns.erase(id);
	}
 
	void updateObservers(int a) {
		std::lock_guard<std::mutex> guard(_mutex);
		for (std::map<uint64_t, CallbackFun>::iterator ite = _callbackFuns.begin(); ite != _callbackFuns.end(); ite++) {
			ite->second(a);
		}
	}
 
private:
	uint64_t _id;
	std::map<uint64_t, CallbackFun> _callbackFuns;
	std::mutex _mutex;
};


class Observatory
{
public:
	Observatory() {}
	~Observatory() {}
 
	void updateWeatherInfo(int num) {
		std::cout << "Observatory: " << num <<std::endl;
	}
};
 
int main()
{
	WeatherStation station;
	std::shared_ptr<Observatory> observatoryPtr(new Observatory());
	CallbackFun func = std::bind(&Observatory::updateWeatherInfo, observatoryPtr, std::placeholders::_1);
	station.registerCbFun(func);
//	station.registerCbFun(observatoryPtr);
	station.updateObservers(1);
	station.updateObservers(2);
	return 0;
}
