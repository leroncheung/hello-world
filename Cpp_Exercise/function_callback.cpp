/**
 * @file function_callback.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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


// to be supplemented
//// 1. move them to diffrent .cpp files
//// 2. for_each, cbegin(), cend()
//// 3. lambda
//// 4. inline
//// 5. copy and move constructor, also copy and move operator
// 6. istream, ostream override
// 7. explicit
//// 8. smart pointer(diffrent usage)
//// 9. observer mode
// 10. override
//// 11. virtual
//// 12. const
//// 13. using/typedef
// 14. static?, final?
//// 15. concurrency: mutex, lock_guard, unique_lock
// 16. derived and abstract class, protected
// 17. static_cast, reinterpret_cast, const_cast, dynamic_cast
// 18. template
// 19. auto
//// 20. naming following specifications