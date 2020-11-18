#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Truba.h"
#include "Utils.h"
#include"KS.h"

using namespace std;

void change_status(Truba& t) {   
	t.Edit_pipe();
}

void change_kol(KS& name) {         
	cout << "Kol-vo cehov inwork= " << endl;
	name.kol_ceh_inwork = GetCorrectNumber(name.kol_ceh);
}

vector <Truba> Edit(vector<Truba>& pipe,double d)
{
	
	vector <int> res;
	int i = 0;
	for (auto& t : pipe)
	{
		if (t.d > d)
		{
			//res.push_back(i);
			t.Edit_pipe();
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
vector<int> FindPipeByFilter( const vector<Truba>& pipe, Filter<T> f, T param)
{
	vector <int> res;
	int i = 0;
	for (auto& t : pipe)
	{
		if (f(t, param))
			res.push_back(i);
		i++;
	}
	return res;
}

template<typename T>
vector<int> FindKSByFilter(const vector<KS>& kss, FilterKS<T> f, T param)
{
	vector <int> resks;
	int i = 0;
	for (auto& t : kss)
	{
		if (f(t, param))
			resks.push_back(i);
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

void del(vector <Truba>& pipe)
{
	cout <<endl<< "ID Pipe to delite: " << endl;
		int i = GetCorrectNumber(1000);
		int y = 0;
		int n=0;
		for (auto& t : pipe)
		{

			if (t.id == i)
			{
				pipe.erase(pipe.begin() + y);
				n = n + 1;
			}
			y = y + 1;
		}

			if (n==0)
				cout << "Truba with this ID is not found";
}

void delks(vector <KS>& kss)
{
	cout << endl << "ID KS to delite: " << endl;
	int i = GetCorrectNumber(1000);
	int n = 0;
	int y = 0;
	for (auto& k : kss)
	{
		if (k.id == i)
		{
			kss.erase(kss.begin() + i);
			n = n + 1;
		}
		y = y + 1;
	}

	if (n == 0)
		cout << "KS with this ID is not found";

}

Truba& SelectPipe(vector <Truba>& p)
{
	cout << "Enter index(from 0): ";
	unsigned int index = GetCorrectNumber(p.size() - 1);
	return p[index];
}

KS& SelectKS(vector <KS>& k)
{
	cout << "Enter index(from 0): ";
	unsigned int index = GetCorrectNumber(k.size() - 1);
	return k[index];
}

int main()
{
	vector <Truba> pipe;
	vector <KS>kss;
	vector <int> res;
	int i;
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
			Truba t;
			cin >> t;
			pipe.push_back(t);
			break;
		}
		case 2:
		{
			KS k;
			cin >> k;
			kss.push_back(k);
			break;
		}
		case 3:
		{
			for (auto& t : pipe)
				cout << t;
			break;
		}
		case 4:
		{
		for (auto& k : kss)
			cout << k;

			break;
		}
		case 5:
		{
			change_status(SelectPipe(pipe));
				break;
		}
		case 6:
			change_kol(SelectKS(kss));
			break;
		case 7:
		{	Truba p;
			ofstream fout;
			fout.open("Pipe.txt", ios::out);
			if (fout.is_open()) {
				fout << pipe.size() << endl;
				for (Truba p : pipe)
					fout << p;
				fout.close();
			}
			break;
		}
		case 8:
		{	KS k;
			ofstream fout;
			fout.open("KS.txt", ios::out);
			if (fout.is_open()) {
				fout << kss.size() << endl;
				for (KS k : kss)
					fout << k;
				fout.close();
			}
			break;
		}
		case 9:
		{	Truba p;
			ifstream fin;
			vector<Truba>pipe2;
			fin.open("Pipe.txt", ios::in);
			if (fin.is_open()) {
				int count;
				fin >> count;
				//Truba::MaxID = count;
					while (count--)
					{
						fin >> p;
						pipe2.push_back(p);
						Truba::MaxID = p.id+1;
					}
					pipe = pipe2;

				fin.close();
			}
			break;
		}
		case 10:
		{	KS k;
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
					KS::MaxIDD = k.id +1;
				}
				fin.close();
				kss = kss2;
			}
			break;
		}
		case 11:
		{ del(pipe);
		break;
		}
		case 12:
		{delks(kss);
		break;}
		case 13:
		{
			cout << "Filter diametr > ";
			cin >> param;
			for (int i : FindPipeByFilter<double>( pipe, CheckByDiametr, param))
				cout << pipe[i];
			break;
		}
		case 14:
		{
		for (int i : FindPipeByFilter(pipe, CheckByRemont,false))
			cout << pipe[i];
		break;
		}
		case 15:
		{
			cout << "Filter Name:  ";
			cin >> name;
			for (int i : FindKSByFilter<string>(kss, CheckByName, name))
				cout << kss[i];
			break;}
		case 16:
		{		
			cout << "Filter % not in work > ";
			param = GetCorrectNumber(100.0);
			//cin >> param;
			for (int i : FindKSByFilter<double>(kss, CheckByProcent, param))
				cout << kss[i];
		break;
		}
		case 17:
		{	double d;
		cout << "Edit pipe d>";
		d= GetCorrectNumber(2000.0);
		for (int i : FindPipeByFilter<double>(pipe, CheckByDiametr, d))
		{
			Edit(pipe,d);
		}
			break;
		}
		case 0:
			return 0;
			break;
		}

		cout << endl;



	}

}




