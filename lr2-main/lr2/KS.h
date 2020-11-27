#pragma once
#include <iostream>
#include<string>
#include <fstream>
class KS
{	friend std::istream& operator >> (std::istream& in, KS& new_ks);
	friend std::ostream& operator << (std::ostream& out, const KS& k);
	friend std::ofstream& operator << (std::ofstream& out, const KS& k);
	friend std::ifstream& operator >> (std::ifstream& in, KS& k);
	int id;
public:
	int set_id();
	static int MaxIDD;
	std::string Name;
	int kol_ceh;
	int kol_ceh_inwork;
	double effect;
	KS();
};

