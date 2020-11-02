#pragma once
#include<iostream>
using namespace std;
template <typename T>
T GetCorrectNumber(T max)
{
	T x;
	while ((cin >> x).fail() || x < 0 || x>max)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Type number (" << 0 << "-" << max << "):";
	}
	return x;
}