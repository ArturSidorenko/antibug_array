#pragma once

#include<iostream>
#include<string>
#include<exception>

class antibug_array {
	double * _data;
	int _n;

public:
	antibug_array(int n) :
		_n(n) {
		_data = new double[n];
	};
	~antibug_array() { delete[] _data; };

	antibug_array(const antibug_array & other) :
		_n(other._n) {
		_data = new double[_n];
		for (int t = 0; t < _n; t++) _data[t] = other._data[t];
	};
	
	const antibug_array & operator=(const antibug_array &other) {
		if (_data != nullptr) delete[] _data;
		_n = other._n;
		_data = new double[_n];
		for (int t = 0; t < _n; t++) _data[t] = other._data[t];
	};

	double & operator[](int t) {
		if ((t >= _n)||(t < 0)) throw std::out_of_range("Your index is out of range.");
		return *(_data + t);
	}

};
