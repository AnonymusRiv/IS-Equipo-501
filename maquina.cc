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
		exit(EXIT_FAILURE);
	}


	string maquina=to_string(machine_ID);
	string id;
	getline(f, id, '\n');
	while(!f.eof())
	{
		if(id == maquina)
		{
			f.close();
			return true;
		}
		getline(f, id, '\n');
	}
	f.close();
	return false;
}

bool Maquina::findMachine(int machine_ID)
{
	ifstream f("ID_Maquinas.txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero"<<endl;
		return false;
	}

	string machineID=to_string(machine_ID);
    string maquina;
    getline(f,maquina,'\n');
    while(!f.eof()){
        if(maquina==machineID){
            M_ID_=machine_ID;
            return true;
        }
        getline(f,maquina,'\n');
    }
	f.close();
    cout << "ERROR. No existe en el sistema el identificador de la máquina indicada"<<endl;
	return false;
}

bool Maquina::selectMachine(int machine_ID, date date, int time, int nucleus)
{
	ifstream f("Maquinas.txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero"<<endl;
		return false;
	}
	string nucleusT;
	string nucleusO;

	Maquina m = Maquina(1, 1);

	getline(f,nucleusT,'\n');
	getline(f,nucleusT,'\n');
	string nt=nucleusT;
	int nT=stoi(nt);
	getline(f,nucleusO,'\n');
	string no=nucleusO;
	int nO=stoi(no);
	while(!f.eof()){
		if(nucleus<(nT-nO)){
			return true;
		}
		getline(f,nucleusT,'\n');
		getline(f,nucleusT,'\n');
		nt=nucleusT;
		nT=stoi(nt);
		getline(f,nucleusO,'\n');
		no=nucleusO;
		nO=stoi(no);
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
		exit(EXIT_FAILURE);
	}

	string id;
	string nucleusT;
	string nucleusO;

	list <string> maquinas;

	getline(f,id,'\n');
	getline(f,nucleusT,'\n');
	int nt=stoi(nucleusT);
	getline(f,nucleusO,'\n');
	int no=stoi(nucleusO);

	while(!f.eof()){
		if(nucleus<nt-no){
			string nFree=to_string(nt-no);
			maquinas.push_back(id);
			maquinas.push_back(nFree);
			cout << "ID de la máquina: " << id << endl;
			cout << "Núcleos disponibles: " << nFree << endl;
		}
		getline(f,id,'\n');
		getline(f,nucleusT,'\n');
		int nt=stoi(nucleusT);
		getline(f,nucleusO,'\n');
		int no=stoi(nucleusO);
	}
	return maquinas;
}

bool Maquina::deleteReserva(int machine_ID, int reserva_ID)
{
	string machine=to_string(machine_ID);
    ifstream file(machine+".txt");
    if(!file){
        cout << "ERROR al abrir el fichero\n";
        exit(EXIT_FAILURE);
    }

    ofstream fileAux("fileAux.txt");
    if(!fileAux){
        cout << "ERROR al abrir el fichero\n";
        exit(EXIT_FAILURE);
    }

    string reserva;

    string rID=to_string(reserva_ID);
    getline(file,reserva,'\n');
    int pos=reserva.find(" ");
    string reservaID=reserva.substr(0,pos);
    while(!file.eof()){
        if(reservaID!=rID){
            fileAux << reserva << endl;
        }
        getline(file,reserva,'\n');
        pos=reserva.find(" ");
        reservaID=reserva.substr(0,pos);
    }
    file.close();
    fileAux.close();

    string filename=machine+".txt";

    if(remove(filename.c_str())!=0){
        cout << "ERROR al eliminar el fichero\n";
        return false;
	}
    else{
        cout << "Fichero eliminado\n";
    }
    rename("fileAux.txt",(filename.c_str()));
    return true;
}

string Maquina::modificarMachine(int machine_ID)
{
	ifstream f("Maquinas.txt");
	if(!f)
	{
		cout<<"Error al abrir el fichero"<<endl;
		exit(EXIT_FAILURE);
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
	}
	f.close();
    exit(EXIT_FAILURE);
}
