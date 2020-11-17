#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Truba
{	
	friend std::ostream& operator << (std::ostream& out, const Truba& t);
	friend std::istream& operator >> (std::istream& in, Truba& new_truba);
	friend std::ofstream& operator << (std::ofstream& out, const Truba& t);
	friend std::ifstream& operator >> (std::ifstream& in, Truba& new_truba);
	int id;
public:
	double l;
	double d;
	bool remont;
    void Edit_pipe();
	Truba();
	static int ID;

};

