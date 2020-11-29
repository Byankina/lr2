#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Truba
{	
	friend std::ostream& operator << (std::ostream& out, const Truba& t);
	friend std::istream& operator >> (std::istream& in, Truba& new_truba);
	friend std::ofstream& operator << (std::ofstream& fout, const Truba& t);
	friend std::ifstream& operator >> (std::ifstream& fin, Truba& new_truba);	
	int id;
public:
	int set_id();
	double l;
	double d;
	bool remont;
    void Edit_pipe();
	Truba();

	static int MaxID;

};

