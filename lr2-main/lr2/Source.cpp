#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include "Truba.h"
#include "Utils.h"
#include"KS.h"

using namespace std;

map <int, Truba> Edit(map<int, Truba>& pipe,double d)
{
	
	map <int, Truba> ::iterator nom;
	int i = 0;
	for (auto& t : pipe)
	{
		if (nom->second.d > d)
		{
			nom->second.Edit_pipe();
		}
		i++;
	}
	return pipe;
}


template<typename T>
using Filter = bool(*)(const Truba& t, T param);
template<typename T>
using FilterKS = bool(*)(const KS& t, T param);

bool CheckByDiametr(const Truba& t, double param)
{
	return t.d > param;
}
bool CheckByRemont(const Truba& t,bool param)
{
	return t.remont == param;
}
bool CheckByName(const KS& k, string param)
{
	return k.Name == param;
}
bool CheckByProcent(const KS& k, double param)
{
	double q;
	q =100*(k.kol_ceh - k.kol_ceh_inwork) / k.kol_ceh ;
	return (q) > param;
}
template<typename T>
map<int, Truba> FindPipeByFilter( const map<int,Truba>& pipe, Filter<T> f, T param)
{
	map  <int,Truba> res;
	int i = 0;
	for (auto& t : pipe)
	{
		if (f(t, param))
			res[i];
		i++;
	}
	return res;
}

template<typename T>
map<int,KS> FindKSByFilter(const map<int,KS>& kss, FilterKS<T> f, T param)
{
	map <int,KS> resks;
	int i = 0;
	for (auto& t : kss)
	{
		if (f(t, param))
			resks[i];
		i++;
	}

	return resks;
}

void PrintMenu() {
	cout << endl;
	cout << "1. Add pipe" << endl
	<< "2. Add KS" << endl
	<< "3. Show the pipe" << endl
	<< "4. Show the KS" << endl
	<< "5. Change the pipe(remont/ne remont)" << endl
	<< "6. Change the KS" << endl
	<< "7. Save the pipe" << endl
	<< "8. Save the KS" << endl
	<< "9. Load from file the pipe" << endl
	<< "10. Load from file the KS" << endl
	<< "11. Delete pipe" << endl
	<< "12. Delete KS" << endl
	<< "13. Find pipe by diametr" << endl
	<< "14. Find pipe in work" << endl
	<< "15. Find KS by name" << endl
	<< "16. Find KS by % kol ceh not in work" << endl
	<< "17. Edit pipe" << endl
	<< "0. Exit" << endl;
}

void del(map <int,Truba>& pipe)
{
	map <int, Truba> ::iterator nom;
	cout <<endl<< "ID Pipe to delite: " << endl;
		int id = GetCorrectNumber(1000);
		nom = pipe.find(id);
		if (nom == pipe.end())
			cout << "Truba with this ID is not found";
		else
			del(pipe,id);
}

void delks(map <int, KS>& kss)
{
	map <int, KS> ::iterator nom;
	cout << endl << "ID KS to delite: " << endl;
	int id = GetCorrectNumber(1000);
	nom = kss.find(id);
	if (nom == kss.end())
		cout << "KS with this ID is not found";
	else
		del(kss,id);
}

int main()
{
	map<int, Truba> pipe;
	map<int, KS>kss;
	int i;
	int id;
	double param;
	string name;
	while (1) {
		cout << "Select action:" << endl;
		PrintMenu();
		i = GetCorrectNumber(17);
		switch (i)
		{
		case 1:
		{
			pipe.insert(pair<int, Truba>(Truba::MaxID+1,Truba()));
			break;
		}
		case 2:
		{	
			kss.insert(pair<int, KS>(KS::MaxIDD + 1, KS()));
			break;
		}
		case 3:
		{	
			for (auto it = pipe.begin(); it != pipe.end(); ++it)
			{
				cout << "TRUBA ID:" << (*it).first << endl<< (*it).second << endl;
	
			}
			break;
		}
		case 4:
		{
			for (auto it = kss.begin(); it != kss.end(); ++it)
			{
				cout <<"KS ID: "<< (*it).first << "  " << (*it).second << endl;
			}
			break;
		}
		case 5:
		{map <int, Truba> ::iterator nom;
		cout << "ID Pipe to change: ";
		int id = GetCorrectNumber(1000);
		nom = pipe.find(id);
		if (nom == pipe.end())
			cout << "Truba with this ID is not found";
		else
			nom->second.Edit_pipe();
			break;
		}
		case 6:
		{
			map <int, KS> ::iterator nom;
			cout << "ID Pipe to change: ";
			int id = GetCorrectNumber(1000);
			nom = kss.find(id);
			if (nom == kss.end())
				cout << "KS with this ID is not found";
			else
				nom->second.Edit_KS();
			break;
		}
		case 7:
		{	
			/*SaveToFile(pipe, "Pipe");*/
			ofstream fout;
			fout.open("Pipe.txt", ios::out);
			if (fout.is_open()) {
				for (auto it = pipe.begin(); it != pipe.end(); ++it)
				{
					fout << (*it).first <<endl<< (*it).second << endl;
				}
				fout.close();
			}
			break;
		}
		case 8:
		{
			ofstream fout;
			fout.open("KS.txt", ios::out);
			if (fout.is_open()) {
				for (auto it = kss.begin(); it != kss.end(); ++it)
				{
					fout << (*it).first << (*it).second << endl;
				}
				fout.close();
			}
			break;
		}
		case 9:
		//{	Truba p;
		//	ifstream fin;
		//	vector<Truba>pipe2;
		//	fin.open("Pipe.txt", ios::in);
		//	if (fin.is_open()) {
		//		int count;
		//		fin >> count;
		//		Truba::MaxID = count;
		//			while (count--)
		//			{
		//				fin >> p;
		//				pipe2.push_back(p);
		//				Truba::MaxID = p.set_id()+1;
		//				//pipe.insert(pair<int, Truba>(Truba::MaxID + 1, Truba()));
		//			}
		//			pipe = pipe2;

		//		fin.close();
		//}
		//break;
		//}
		case 10:
		/*{	KS k;
		vector<KS> kss2;
			ifstream fin;
			fin.open("KS.txt", ios::in);
			if (fin.is_open()) {
				int count;
				fin >> count;
				
				while (count--)
				{
					fin >> k;
					kss2.push_back(k);
					KS::MaxIDD = k.set_id() +1;
				}
				fin.close();
				kss = kss2;
			}
			break;
		}*/
		case 11:
		{ del(pipe);
		break;
		}
		case 12:
		{delks(kss);
		break;}
		//case 13:
		//{
		//	cout << "Filter diametr > ";
		//	cin >> param;
		//	for (int i : FindPipeByFilter<double>( pipe, CheckByDiametr, param))
		//		cout << pipe[i];
		//	break;
		//}
		//case 14:
		//{
		//for (int i : FindPipeByFilter(pipe, CheckByRemont,false))
		//	cout << pipe[i];
		//break;
		//}
		//case 15:
		//{
		//	cout << "Filter Name:  ";
		//	cin >> name;
		//	for (int i : FindKSByFilter<string>(kss, CheckByName, name))
		//		cout << kss[i];
		//	break;}
		//case 16:
		//{		
		//	cout << "Filter % not in work > ";
		//	param = GetCorrectNumber(100.0);
		//	//cin >> param;
		//	for (int i : FindKSByFilter<double>(kss, CheckByProcent, param))
		//		cout << kss[i];
		//break;
		//}
		//case 17:
		//{	double d;
		//cout << "Edit pipe d>";
		//d= GetCorrectNumber(2000.0);
		//for (int i : FindPipeByFilter<double>(pipe, CheckByDiametr, d))
		//{
		//	Edit(pipe,d);
		//}
		//	break;
		//}
		case 0:
			return 0;
			break;
		}
		cout << endl;
	}

}