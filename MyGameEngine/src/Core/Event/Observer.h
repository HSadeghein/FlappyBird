#pragma once 
template <typename T>
struct Observer
{
	public:
		virtual void field_change(T& source, const char* field_name);
};