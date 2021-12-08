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

bool setNucleus(int machine_Nucleus)
{
	if(machine_Nucleus >= 0)
	{
		M_Nucleus_ = machine_Nucleus;
		return true;
	}
	cout<<"Debe introducir un numero positivo\n"<<endl;
	return false;
	
}

bool setID(int machine_ID)
{
	ifstream f("machine.txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero\n"<<endl;
		EXIT_FAILURE;
	}

	int election;
	string maquina=to_string(machine_ID);
	string id;
	getiline(f, id, ' ');
	while(!f.eof())
	{
		if(id == maquina)
		{
			f.close();
			return true;
		}
		getiline(f, id, ' ');
	}
	f.close();
	return false;
}

bool findMachine(int machine_ID)
{
	ifstream f(machine_ID+".txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero\n"<<endl;
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

bool selectMachine(int machine_ID, date date, int time, int nucleus)
{
	ifstream f(machine_ID+".txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero\n"<<endl;
		EXIT_FAILURE;
	}

	int election;
	string maquina;
	while(!f.eof())
	{
		if(maquina == to_string(machine_ID))
		{
			R_Date_ = date;
			M_Nucleus_ = nucleus;
			R_Time_ = time;
			f.close();
			return true;
		}
	}
	f.close();
	return false;
}

list <string> listMachine(date date, int time, int nucleus)
{
	if(M_Nucleus_ <= nucleus)
	{
		return Reserva;
	}
}

bool deleteReserva(int machine_ID, int reserva_ID)
{
	ifstream f(machine_ID+".txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero\n"<<endl;
		EXIT_FAILURE;
	}

	string reserva;
	getline(f, reserva, ' ');
	while(!f.eof())
	{
		if(M_ID_ == machine_ID && reserva == to_string(reserva_ID))
		{

		}
	}
	f.close();
}

string modificarMachine(int machine_ID)
{
	ifstream f(machine_ID+".txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero\n"<<endl;
		EXIT_FAILURE;
	}

	int election;
	string maquina;
	while(!f.eof())
	{
		if(maquina == to_string(machine_ID))
		{
		system("clear");

		sel:
		cout<<"1. Eliminar maquina.\n"<<endl;
		cout<<"2. Modificar maquina.\n"<<endl;
		cout<<"Seleccione una accion:\n"<<endl;
		cin>>election;

		if(election == 1)
		{
			return "Eliminar";
		}
		else if(election == 1)
		{
			return "Modificar";
		}
		else
		{
			cout<<"Debe seleccionar o 1 o 2"<<endl;
			goto sel;
		}
	}
	f.close;
}
