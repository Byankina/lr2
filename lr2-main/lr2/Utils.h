#pragma once
#include<iostream>
#include<map>
using namespace std;
//проверка
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
//удаление
template <typename T>
void del(map <int, T>& t,int id)
{
		t.erase(id);
}
//сохранение в файл
template <typename T>
void SaveToFile(const map <int, T>& t,string filename)
{
	ofstream fout;
	fout.open(filename + ".txt", ios::out);
	if (fout.is_open())
	{
		for (auto it = t.begin(); it != t.end(); ++it)
		{
			fout << it.second;
		}
		cout << "Data saved \n" << endl;
	}
	fout.close();
}