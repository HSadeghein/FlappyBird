#pragma once
#include"Observer.h"
#include <vector>
template<typename T>
struct Observable
{
	inline void notify(T& source, const char* field_name)
	{
		for (auto obs : observers)
		{
			obs->field_change(source, field_name);
		}
	}
	inline void subscribe(Observer<T>* f)
	{
		observers.push_back(f);
	}
	void unsubscribe();
private:

	std::vector<Observer<T>*> observers;
};
