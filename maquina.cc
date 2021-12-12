#include "maquina.h"
#include "reserva.h"

#include <string>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

Maquina::Maquina(int machine_ID, int machine_Nucleus, int machine_NOcuped)
{
	M_ID_ = machine_ID;
	M_Nucleus_ = machine_Nucleus;
	M_NOcuped_ = machine_NOcuped;
}

bool Maquina::setNucleus(int machine_Nucleus)
{
	if(machine_Nucleus >= 0)
	{
		M_Nucleus_ = machine_Nucleus;
		return true;
	}
	cout<<"Debe introducir un numero positivo"<<endl;
	return false;
}

bool Maquina::setID(int machine_ID)
{
	ifstream f("Maquinas.txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero"<<endl;
		EXIT_FAILURE;
	}

	int election;
	string maquina=to_string(machine_ID);
	string id;
	getline(f, id, ' ');
	while(!f.eof())
	{
		if(id == maquina)
		{
			f.close();
			return true;
		}
		getline(f, id, ' ');
	}
	f.close();
	return false;
}

bool Maquina::findMachine(int machine_ID)
{
	ifstream f(machine_ID+".txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero"<<endl;
		EXIT_FAILURE;
	}

	int election;
	string maquina;
	while(!f.eof())
	{
		if(maquina == to_string(machine_ID))
		{
			f.close();
			return true;
		}
	}
	f.close();
	return false;
}

bool Maquina::selectMachine(int machine_ID, date date, int time, int nucleus)
{
	ifstream f(machine_ID+".txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero"<<endl;
		EXIT_FAILURE;
	}

	int election;
	string maquina;
	while(!f.eof())
	{
		if(maquina == to_string(machine_ID))
		{
			if(nucleus<=(M_Nucleus_ - M_NOcuped_))
			{
				f.close();
				return true;
			}
		}
	}
	f.close();
	return false;
}

list <string> Maquina::listMachine(date date, int time, int nucleus)
{
	ifstream f("Maquinas.txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero"<<endl;
		EXIT_FAILURE;
	}

	string line;
	string nucl;
	string nocup;
	string m_id;

	list <string> n;

	int nucleus;
	int nucleusOcup;

	string delimiter=" ";
	getline(f, line, '\n');
	line.erase(0, line.find(delimiter) + delimiter.length());
	m_id = line.substr(0, line.find(delimiter));
	line.erase(0, line.find(delimiter) + delimiter.length());
	nucl = line.substr(0, line.find(delimiter));
	line.erase(0, line.find(delimiter) + delimiter.length());
	nocup = line.substr(0, line.find(delimiter));

	nucleus=stoi(nucl);
	nucleusOcup=stoi(nocup);

	while(!f.eof())
	{
		if(nucleus<=(nucleus - nucleusOcup))
		{
			n.push_back(m_id);
		}
	}
	f.close();
	return n;
}

bool Maquina::deleteReserva(int machine_ID, int reserva_ID)
{
	ifstream f(machine_ID+".txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero"<<endl;
		EXIT_FAILURE;
	}

	ofstream f1("f1.txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero"<<endl;
		EXIT_FAILURE;
	}

	string reserva;
	getline(f, reserva, ' ');
	while(!f.eof())
	{
		if(M_ID_ == machine_ID && reserva == to_string(reserva_ID))
		{
			getline(f, reserva, '\n');
			f1<<reserva;
		}
	}
	f.close();
	f1.close();

	string fnew = machine_ID+".txt";

	if(remove(fnew.c_str())!=0)
	{
		cout<<"Error al eliminar el fichero"<<endl;
		return false;
	}
	else
	{
		cout<<"El fichero se ha eliminado"<<endl;
	}

	rename("f1.txt", (fnew.c_str()));
}

string Maquina::modificarMachine(int machine_ID)
{
	ifstream f("Maquinas.txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero"<<endl;
		EXIT_FAILURE;
	}

	int election;
	string maquina;
	getline(f, maquina, ' ');
	while(!f.eof())
	{
		if(maquina == to_string(machine_ID))
		{
		system("clear");

		sel:
		cout<<"Seleccione una accion:"<<endl;
		cout<<"1. Eliminar maquina."<<endl;
		cout<<"2. Modificar maquina."<<endl;
		cin>>election;

		if(election == 1)
		{
			return "ELIMINAR";
		}
		else if(election == 2)
		{
			return "MODIFICAR";
		}
		else
		{
			cout<<"Debe seleccionar o 1 o 2"<<endl;
			goto sel;
		}
	}
	f.close();
	return "CREAR";
}
