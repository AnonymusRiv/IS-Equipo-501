#include "reserva.h"
#include "maquina.h"
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

Reserva::Reserva(int res_ID, int user_ID, date res_date, int res_Machine, int res_Nucleus, int res_Time){
    R_ID_=res_ID;
    R_User_=user_ID;
    R_Date_.day=res_date.day;
    R_Date_.month=res_date.month;
    R_Date_.year=res_date.year;
    R_Machine=res_Machine;
    R_Nucleus=res_Nucleus;
    R_Time=res_Time;
}

bool setDate(date date){
    auto t1=(date.day+date.month+date.year);
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d%m%Y");
    auto str = oss.str();

    if(t1<str){
        cout << "ERROR. Fecha no válida" << endl;
        return false;
    }
    return true;
}

bool setTime(int time){
    if(time<0){
        cout << "ERROR. El número de días insertado ha de ser mayor a 1\n";
        return false;
    }
    else{
        return true;
    }
}

bool setMachine(int machine_ID){
    ifstream file("machine.txt");
    if(!file){
        cout << "ERROR al abrir el fichero\n";
        EXIT_FAILURE;
    }

    string machineID=to_string(machine_ID);
    string id;
    getline(file,id,' ');
    while(!file.eof()){
        if(id==machineID){
            return true;
        }
        getline(file,id,' ');
    }
    file.close();
    cout << "ERROR. No existe en el sistema el identificador de la máquina indicada\n";
    return false;
}

bool setNucleus(int nucleus){
    if(nucleus<0){
        cout << "ERROR. El número de núcleos indicados ha de ser mayor a 1\n";
        return false;
    }
    return true;
}

bool esUsuarioNormal(int user_ID){
    ifstream file("usuariosNormales.txt");
    if(!file){
        cout << "ERROR al abrir el fichero\n";
        EXIT_FAILURE;
    }
    
    string userID=to_string(user_ID);
    string id;
    getline(file,id,' ');
    while(!file.eof()){
        if(id==userID){
            return true;
        }
        getline(file,id,' ');
    }
    file.close();
    return false;
}

bool esUsuarioAdmin(int user_ID){
    ifstream file("usuariosAdministradores.txt");
    if(!file){
        cout << "ERROR al abrir el fichero\n";
        EXIT_FAILURE;
    }
    
    string userID=to_string(user_ID);
    string id;
    getline(file,id,' ');
    while(!file.eof()){
        if(id==userID){
            return true;
        }
        getline(file,id,' ');
    }
    file.close();
    return false;
}

list <string> fileToList(int user_ID){
    ifstream file(user_ID+".txt");
        if(!file){
            cout << "ERROR al abrir el fichero\n";
            EXIT_FAILURE;
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

list <string> listReservas(int user_ID){
    if(esUsuarioNormal(user_ID)==true){
        ifstream file(user_ID+".txt");
        if(!file){
            cout << "ERROR al abrir el fichero\n";
            EXIT_FAILURE;
        }

        return(fileToList(user_ID));
    }

    else if(esUsuarioAdmin(user_ID)==true){
        ifstream file("usuariosAdministradores.txt");
        if(!file){
            cout << "ERROR al abrir el fichero\n";
            EXIT_FAILURE;
        }
        string user;
        getline(file,user,' ');
        list <string> aux;
        while(!file.eof()){
            aux.push_back(fileToList(stoi(user)));
            getline(file,user,'\n');
        }
        file.close();
        return aux;
    }
    else{
        cout << "ERROR. No existen reservas asociadas al identificador insertado\n";
        EXIT_FAILURE;
    }
}

string modificarReserva(int user_ID, int reserva_ID){
    ifstream file(user_ID+".txt");
    if(!file){
        cout << "ERROR al abrir el fichero\n";
        EXIT_FAILURE;
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
                return "CANCELAR";
            }
            else(select==2){
                return "MODIFICAR";
            }
            else{
                cout << "Seleccione una opción válida\n";
                goto selection;
            }
        }
    }
    file.close();
}

bool deleteReserva(int user_ID, int reserva_ID){
    ifstream file(user_ID+".txt");
    if(!file){
        cout << "ERROR al abrir el fichero\n";
        EXIT_FAILURE;
    }

    string reserva;
    getline(file,reserva,' ');
    while(!file.eof()){
        if(reserva==to_string(reserva_ID)){
            //TODO Eliminar una línea del fichero de reservas
        }
    }
    file.close();
}