#include "Truba.h"
#include"Utils.h"
#include<fstream>

using namespace std;
istream& operator >> (istream& in, Truba& new_truba)
{
	cout << "diametr=" << endl;
	new_truba.d = GetCorrectNumber(2000.0);
	cout << "dlina=" << endl;
	new_truba.l = GetCorrectNumber(1000.0);
	new_truba.remont = false;
	return in;
}

std::ofstream& operator<<(std::ofstream& fout, const Truba& p)
{
	fout /*<< p.id<< endl */<< p.d << endl << p.l << endl << p.remont << endl;
	return fout;
}

std::ifstream& operator>>(std::ifstream& fin, Truba& t)
{
	fin >> t.id >> t.d >> t.l >> t.remont;
	return fin;
}

ostream& operator << (ostream& out, const Truba& t)
{
	//out << "TRUBA" 
	//<< "     id: " << t.id 
	out << "  Diameter= ";
	out << t.d << endl;
	out << "     Dlina= ";
	out << t.l<<endl;
	out<< (t.remont ? "   V remonte  " : "   Ne v remonte  ");
	out << t.remont;
	return out;
}

void Truba::Edit_pipe()
{
	this->remont = !remont;
}

int Truba::MaxID = 0;

Truba::Truba()
{
	this->id = MaxID++;
	cout << "diametr=" << endl;
	this->d= GetCorrectNumber(2000.0);
	cout << "dlina=" << endl;
	this->l = GetCorrectNumber(1000.0);
	this->remont = false;
}


int Truba::set_id()
{
	int id_znach = id;
	return id_znach;
}


