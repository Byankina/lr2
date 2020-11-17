//#include "Truba.h"
//#include"Utils.h"
//
//using namespace std;
//istream& operator >> (istream& in, Truba& new_truba)
//{
//	cout << "diametr=" << endl;
//	new_truba.d = GetCorrectNumber(2000.0);
//	cout << "dlina=" << endl;
//	new_truba.l = GetCorrectNumber(1000.0);
//	new_truba.remont = false;
//	return in;
//}
//
//ofstream& operator<<(ofstream& fout, const Truba& p)
//{
//	fout /*<< p.id*/<< endl << p.d << endl << p.l << endl << p.remont << endl;
//	return fout;
//}
//
//std::ifstream& operator>>(std::ifstream& fin, Truba& t)
//{
//	fin /*>> t.id*/ >> t.d >> t.l >> t.remont;
//	return fin;
//}
//
//ostream& operator << (ostream& out, const Truba& t)
//{
//	out << "TRUBA" 
//	<< "     id: " << t.id
//	<< "     Diameter= " << t.d 
//	<< "     Dlina= " << t.l 
//	<< (t.remont ? "     V remonte" : "     Ne v remonte") << endl;
//	return out;
//}
//
//void Truba::Edit_pipe()
//{
//	remont = 1;
//}
//
//int Truba::ID = 0;
//
//Truba::Truba()
//{
//	id = ID++;
//}
//
//
#include "Truba.h"
#include"Utils.h"

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

ofstream& operator<<(ofstream& fout, const Truba& p)
{
	fout << p.id << endl << p.d << endl << p.l << endl << p.remont << endl;
	return fout;
}

std::ifstream& operator>>(std::ifstream& fin, Truba& t)
{
	fin >> t.id >> t.d >> t.l >> t.remont;
	return fin;
}

ostream& operator << (ostream& out, const Truba& t)
{
	out << "TRUBA"
		<< "     id: " << t.id
		<< "     Diameter= " << t.d
		<< "     Dlina= " << t.l
		<< (t.remont ? "     V remonte" : "     Ne v remonte") << endl;
	return out;
}

void Truba::Edit_pipe()
{
	remont = 1;
}

int Truba::ID = 0;

Truba::Truba()
{
	id = ID++;
}