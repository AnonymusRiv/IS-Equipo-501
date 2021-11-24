//Body of class Reserva

#include "reserva.h"
#include "maquina.h"
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

void crearReserva(int user_ID, date res_Date, int machine_ID,int res_Nucleus, int res_Time){
    fstream file("reservas.txt",fstream::app);
    if(!file){ //Si no existe el fichero se devuelve un error
        cout << "ERROR al abrir el fichero\n";
        exit(EXIT_FAILURE);
    }

    char lastResID,newResID;
    if(setNucleus(res_Nucleus)<(getNucleus()-getNucleusOcuped())){
        while(!file.eof()){
            file >> lastResID;
        }
        newResID=lastResID++;
        file << newResID << " " << user_ID << " " << res_Date.day << "/" << res_Date.month << "/" << res_Date.year << " " << machine_ID << " "<< res_Nucleus << " " << res_Nucleus << endl;
        cout << "Reserva creada correctamente." << endl;
    }
    else{
        cout << "ERROR, el número de núcleos insertado no está disponible en la máquina deseada." << endl;
        findMachine(res_Nucleus);
    }
}

void modificarRecursos(){
    system("clear");
    cout << "¿Qué recursos desea modificar?" << endl;
    cout << "1. Cambio de máquina" << endl;
    cout << "2. Petición de núcleos" << endl;
    cout << "3. Petición de prórroga" << endl;
    cout << "Su elección: ";
    int select;
    cin >> select;

    switch (select){
    case 1:
        cout << "¿Qué máquina desea?\nMáquina nº: ";
        int machine;
        cin >> machine;
    break;
    case 2:
        cout << "¿Cuántos núcleos desea?\nNº de núcleos: ";
        int nucleus;
        cin >> nucleus;
    break;
    case 3:
        cout << "¿Cuánto tiempo desea de prórroga?\nNº de días: ";
        int time;
        cin >> time;
    break;
    default:
        cout << "Elección no válida" << endl;
    break;
    }
}

bool modificarReserva(int res_ID){
    ifstream file("reservas.txt");
    if(!file){ //Si no existe el fichero se devuelve un error
        cout << "ERROR al abrir el fichero\n";
        exit(EXIT_FAILURE);
    }
    char resID;
    while(!file.eof()){
            file >> resID;
            if(res_ID==resID){
                modificarRecursos();
            }
    }
    if(file==EOF){
        cout << "ERROR. No existe el ID de reserva insertado en la base de datos" << endl;
        exit(0);
    }
}