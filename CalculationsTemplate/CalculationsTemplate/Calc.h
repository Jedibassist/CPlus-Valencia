#pragma once
#include <iostream>

template<class T>
class Calc
{
public:
	Calc<T>();
	~Calc<T>();

	T Calc<T>::Add(T a, T b);
	T Calc<T>::Subtract(T a, T b);
	T Calc<T>::Multiply(T a, T b);
	T Calc<T>::Divide(T a, T b);
};

template<class T>
Calc<T>::Calc()
{
}

template<class T>
Calc<T>::~Calc()
{
}

template<class T>
T Calc<T>::Add(T a, T b){
	return a + b;
}

template<class T>
T Calc<T>::Subtract(T a, T b){
	return a - b;
}

template<class T>
T Calc<T>::Multiply(T a, T b){
	return a * b;
}

template<class T>
T Calc<T>::Divide(T a, T b){
	return a / b;
}
