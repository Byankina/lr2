#include "KS.h"
#include "Utils.h"
using namespace std;

istream& operator >> (istream& in, KS& new_ks)
{
	//cout << "id=" << endl;
	//new_ks.id = GetCorrectNumber(1000);
	cout << "Name: " << endl;
	cin.ignore(10000, '\n');
	getline(cin, new_ks.Name);
	cout << "kol ceh=" << endl;
	new_ks.kol_ceh = GetCorrectNumber(100);
	cout << "kol ceh inwork=" << endl;
	new_ks.kol_ceh_inwork = GetCorrectNumber(new_ks.kol_ceh);
	cout << "effect=" << endl;
	new_ks.effect = GetCorrectNumber(10.0);
	return in;
}

ostream& operator << (ostream& out, const KS& k)
{
	out << "KS" 
	<< "    ID: " << k.id 
	<< "    Name: " << k.Name 
	<< "    in work " << k.kol_ceh_inwork << "/" << k.kol_ceh
	<< "    Effect= " << k.effect << endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& fout, const KS& c)
{
	fout << c.id << endl << c.Name << endl << c.kol_ceh << endl << c.kol_ceh_inwork << endl << c.effect;
	return fout;
}

std::ifstream& operator>>(std::ifstream& fin, KS& k)
{
	fin >> k.id >> k.Name >> k.kol_ceh >> k.kol_ceh_inwork >> k.effect;
	return fin;
}

int KS::MaxIDD = 0;

KS::KS()
{
	id = MaxIDD++;
}
