#include <iostream>

template <class T>
class SmartPtr {
public:
	SmartPtr(T *);
	SmartPtr(const SmartPtr&);
	~SmartPtr();
	SmartPtr& operator =(const SmartPtr&);
	T &operator *();
	T *operator ->();
	size_t use_count();
	
private:
	T *ptr;
	size_t *count;
};

template <class T>
SmartPtr<T>::SmartPtr(T *p) {
	this->ptr = p;
	this->count = new size_t(0);
	if (p != nullptr) {
		*this->count = 1;
	}
}

template <class T>
SmartPtr<T>::SmartPtr(const SmartPtr& smartPtr) {
	if (this != &smartPtr) {
		this->ptr = smartPtr.ptr;
		this->count = smartPtr.count;
		(*this->count)++;
	}
}

template <class T>
SmartPtr<T>::~SmartPtr() {
	(*this->count)--;
	if (*this->count == 0) {
		delete this->ptr;
		delete this->count;
		std::cout << "~SmartPtr()\n";
	}
}

template <class T>
SmartPtr<T>& SmartPtr<T>::operator =(const SmartPtr<T> &smartPtr) {
	if (this->ptr == smartPtr.ptr) {
		return *this;
	}
	if (this->ptr != nullptr) {
		(*this->count)--;
		if (*this->count == 0) {
			delete this->ptr;
			delete this->count;
			std::cout << "delete\n";
		}
	}
	this->ptr = smartPtr.ptr;
	this->count = smartPtr.count;
	(*this->count)++;
	return *this;
}

template <class T>
T & SmartPtr<T>::operator *() {
	assert(this->ptr != nullptr);
	return *(this->ptr);
}

template <class T>
T *SmartPtr<T>::operator ->() {
	assert(this->ptr != nullptr);
	return this->ptr;
}

template <class T>
size_t SmartPtr<T>::use_count() {
	return *this->count;
}

class Base {
public:
	int m_a;
};

int main() {
	Base *base = new Base();
	SmartPtr<Base> sp(base);
	std::cout << "sp.count = " << sp.use_count() << std::endl;
	SmartPtr<Base> sp2 = sp;
	std::cout << "sp.count = " << sp2.use_count() << std::endl;
	Base *base2 = new Base();
	SmartPtr<Base> sp3(base2);
	sp3 = sp;
	std::cout << "sp.count = " << sp.use_count() << std::endl;
	std::cout << "sp3.count = " << sp3.use_count() << std::endl;
	
	return 0;
}
