#include "reserva.h"
#include "maquina.h"
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Reserva::Reserva(int user_ID, date res_date, int res_Machine, int res_Nucleus, int res_Time, int res_ID){
    R_ID_=res_ID;
    R_User_=user_ID;
    R_Date_.day=res_date.day;
    R_Date_.month=res_date.month;
    R_Date_.year=res_date.year;
    R_Machine_=res_Machine;
    R_Nucleus_=res_Nucleus;
    R_Time_=res_Time;
}

bool Reserva::setDate(date date){
    auto t1=(date.day+"/"+date.month+"/"+date.year);
    auto t = time(nullptr);
    auto tm = *localtime(&t);
    ostringstream oss;
    oss << put_time(&tm, "%d/%m/%Y");
    auto str = oss.str();

    if(t1<str){
        cout << "ERROR. Fecha no válida" << endl;
        return false;
    }
    return true;
}

bool Reserva::setTime(int time){
    if(time<1){
        cout << "ERROR. El número de días insertado ha de ser mayor a 1\n";
        return false;
    }
    else{
        R_Time_=time;
        return true;
    }
}

bool Reserva::setMachine(int machine_ID){
    if(machine_ID<1){
        cout<<"\nERROR ID invalido\n";
        return false;
    }

    ifstream file("ID_Maquinas.txt");
    if(!file){
        cout << "ERROR al abrir el fichero\n";
        return false;
    }

    string machineID=to_string(machine_ID);
    string id;
    getline(file,id,'\n');
    while(!file.eof()){
        if(id==machineID){
            R_Machine_=machine_ID;
            return true;
        }
        getline(file,id,'\n');
    }
    file.close();
    cout << "ERROR. No existe en el sistema el identificador de la máquina indicada\n";
    return false;
}

bool Reserva::setNucleus(int nucleus){
    if(nucleus<1){
        cout << "ERROR. El número de núcleos indicados ha de ser mayor a 1\n";
        return false;
    }
    R_Nucleus_=nucleus;
    return true;
}

bool Reserva::esUsuarioNormal(int user_ID){
    ifstream file("Usuarios_Normales.txt");
    if(!file){
        cout << "ERROR al abrir el fichero\n";
        exit(EXIT_FAILURE);
    }

    string userID=to_string(user_ID);
    string id;
    getline(file,id,'\n');
    int uid=id.find(" ");
    string uID=id.substr(0,uid);
    while(!file.eof()){
        if(uID==userID){
            return true;
        }
        getline(file,id,'\n');
        uid=id.find(" ");
        uID=id.substr(0,uid);
    }
    file.close();
    return false;
}

bool Reserva::esUsuarioAdmin(int user_ID){
    ifstream file("Usuarios_Administradores.txt");
    if(!file){
        cout << "ERROR al abrir el fichero\n";
        exit(EXIT_FAILURE);
    }
    string userID=to_string(user_ID);
    string id;
    getline(file,id,'\n');
    int uid=id.find(" ");
    string uID=id.substr(0,uid);
    while(!file.eof()){
        if(uID==userID){
            return true;
        }
        getline(file,id,'\n');
        uid=id.find(" ");
        uID=id.substr(0,uid);
    }
    file.close();
    return false;
}

list <string> Reserva::fileToList(int user_ID){
    string user=to_string(user_ID);
    ifstream file(user+".txt");
        if(!file){
            cout << "ERROR al abrir el fichero\n";
            exit(EXIT_FAILURE);
        }

    list <string> reservas;
    reservas.clear();
    string res;
    getline(file,res,'\n');
    while(!file.eof()){
        reservas.push_back(res);
        getline(file,res,'\n');
    }
    file.close();
    return reservas;
}

list <string> Reserva::unifyList(string user, list <string> aux){
    ifstream file(user+".txt");
    if(!file){
    cout << "ERROR al abrir el fichero\n";
    exit(EXIT_FAILURE);
    }

    string datos;
    getline(file,datos,'\n');

    while(!file.eof()){
        aux.push_back(datos);
        getline(file,datos,'\n');
    }
    return aux;
}

list <string> Reserva::listReservas(int user_ID){
    if(esUsuarioNormal(user_ID)==true){
        string user=to_string(user_ID);
        ifstream file(user+".txt");
        if(!file){
            cout << "ERROR al abrir el fichero\n";
            exit(EXIT_FAILURE);
        }

        return(fileToList(user_ID));
    }

    else if(esUsuarioAdmin(user_ID)==true){
        ifstream file("usuarios_administradores.txt");
        if(!file){
            cout << "ERROR al abrir el fichero\n";
            exit(EXIT_FAILURE);
        }

        string user;
        getline(file,user,' ');
        list <string> aux;
        aux.clear();

        while(!file.eof()){
            ifstream fileUser(user+".txt");
            if(!fileUser){
            cout << "ERROR al abrir el fichero\n";
            exit(EXIT_FAILURE);
            }
            unifyList(user,aux);
            getline(file,user,'\n');
        }
        file.close();
        return aux;
    }
    else{
        cout << "ERROR. No existen reservas asociadas al identificador insertado\n";
        exit(EXIT_FAILURE);
    }
}

string Reserva::modificarReserva(int user_ID, int reserva_ID){
    string user=to_string(user_ID);
    ifstream file(user+".txt");
    if(!file){
        cout << "ERROR al abrir el fichero\n";
        exit(EXIT_FAILURE);
    }
    int select;
    string reserva;
    getline(file,reserva,' ');
    while(!file.eof()){
        if(reserva==to_string(reserva_ID)){
            system("clear");
            selection:
            cout << "Seleccione la acción que desea realizar con la reserva:\n";
            cout << "1. ELIMINAR reserva\n";
            cout << "2. MODIFICAR reserva\n";
            cin >> select;
            if(select==1){
                return "ELIMINAR";
            }
            else if(select==2){
                return "MODIFICAR";
            }
            else{
                cout << "Seleccione una opción válida\n";
                goto selection;
            }
        }
    }
    file.close();
    exit(EXIT_FAILURE);
}

bool Reserva::deleteReserva(int user_ID, int reserva_ID){
    string user=to_string(user_ID);
    ifstream file(user+".txt");
    if(!file){
        cout << "ERROR al abrir el fichero\n";
        return false;
    }

    ofstream fileAux("fileAux.txt");
    if(!fileAux){
        cout << "ERROR al abrir el fichero\n";
        return false;
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

    string filename=user+".txt";

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

bool Reserva::crearReserva(int user_ID, date res_date, int res_Machine, int res_Nucleus, int res_Time){
    string user=to_string(user_ID);
    ifstream file(user+".txt");
    if(!file){
        cout << "ERROR al abrir el fichero\n";
        return false;
    }

    int contador=0;
    string datos;
    getline(file,datos,'\n');
    while(!file.eof()){
        contador++;
        getline(file,datos,'\n');
    }

    int res_ID=contador+1;

    file.close();

    fstream file1((user+".txt"),fstream::app);
	if(!file1){
		cout<<"Error al abrir el fichero"<<endl;
		return false;
	}
    file1 << res_ID << " " << res_date.day+"/"+res_date.month+"/"+res_date.year<< " " << res_Machine << " " << res_Nucleus << " " << res_Time << endl;
    file1.close();

    string maquina=to_string(res_Machine);
	fstream file2((maquina+".txt"),fstream::app);
	if(!file2){
		cout<<"Error al abrir el fichero"<<endl;
		return false;
	}
	file2 << res_ID << " " << res_date.day+"/"+res_date.month+"/"+res_date.year << " " << res_Time << " " << res_Nucleus << endl;
	file2.close();

    return true;
}
