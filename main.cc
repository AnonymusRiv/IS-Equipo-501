#include <iostream>
#include <string>
#include <list>
#include "maquina.h"
#include "reserva.h"
#include "Sistema.h"
#include "Usuario_Administrador.h"
#include "Usuario_Normal.h"

using namespace std;

int main(){
    date dates;
    string nombre;
    string password;
    string mail;
    Sistema s;
    Reserva r = Reserva(1, dates, 1, 1, 1);
    Maquina m = Maquina(1, 1);
    Usuario_administrador_de_usuarios UAU = Usuario_administrador_de_usuarios(1, password, nombre, mail);
    Usuario_administrador_de_maquinas UAM = Usuario_administrador_de_maquinas(1, password, nombre, mail);

    date fecha;
    int time;
    int m_id;
    int r_id;
    int user_id;
    int nucleus;
    list <string> maquinas;
    list <string> reservas;

    int ID;
    string cadena;
    string Password;
    string respuesta;
    int opcion=0;
    system("clear");
    cout<<"\t\t\tBIENVENIDO AL SISTEMA DE GESTION DE NUCLEOS"<<endl;
    cout<<"\nPor favor introduzca su identificador para acceder al sistema: ";
    cin>>cadena;
    ID=stoi(cadena);
    cout<<"Introduzca su contraseña: ";
    cin>>Password;
    cout<<"---------------------------------------"<<endl;
    s.login(ID, Password);

    do{
        cout<<"\n----------------------INSTRUCCIONES QUE PUEDE REALIZAR EN EL SISTEMA-------------------------------"<<endl;
        cout<<"\t\t\t\t1. Crear reserva"<<endl;
        cout<<"\t\t\t\t2. Modificar reserva"<<endl;
        cout<<"\t\t\t\t3. Modificar usuario"<<endl;
        cout<<"\t\t\t\t4. Modificar maquina"<<endl;
        cout<<"\t\t\t\t5. Salir del sistema"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                system("clear");
                cout<<"Introduzca la fecha de comienzo de la reserva:"<<endl;
                cout<<"Día: ";
                cin>>fecha.day;
                cout<<"Mes: ";
                cin>>fecha.month;
                cout<<"Año: ";
                cin>>fecha.year;
                cout<<endl;
                if(r.setDate(fecha)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }
                cout<<"Fecha asignada correctamente"<<endl;

                cout<<"\nIntroduzca el número de días de la reserva: ";
                cin>>time;
                cout<<endl;
                if(r.setTime(time)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }
                cout<<"Tiempo asignado correctamente"<<endl;

                cout<<"\nIntroduzca el ID de la maquina a reservar: ";
                cin>>m_id;
                if(r.setMachine(m_id)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }

                if(m.findMachine(m_id)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }
                cout<<"\nMáquina encontrada"<<endl;

                cout<<"\nIntroduzca el número de núcleos que desea reservar: ";
                cin>>nucleus;
                if(r.setNucleus(nucleus)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }

                if(m.selectMachine(m_id, fecha, time, nucleus)==false){
                    cout<<"Máquina no disponible, no tiene los núcleos solicitados."<<endl;
                    maquinas=m.listMachine(fecha, time, nucleus);
                    cout<<"Introduzca el id de la maquina que apareceran a continuacion para reservar esos nucleos"<<endl;
                    list <string>:: iterator it = maquinas.begin();
                    while(it != maquinas.end()){
                        cout<<"\t"<<*it++<<endl;
                    }
                    cin>>m_id;
                    if(m.selectMachine(m_id, fecha, time, nucleus)==false){
                        cout<<"ERROR"<<endl;
                        exit(EXIT_FAILURE);
                    }
                }
                if(r.crearReserva(ID, fecha ,m_id ,nucleus ,time)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }
                cout<<"Reserva realizada correctamente."<<endl;
                system("clear");
            break;

            case 2:
                {
                reservas=r.listReservas(ID);
                list <string>:: iterator it = reservas.begin();
                while(it != reservas.end()){
                    cout<<"\t"<<*it++<<endl;
                }
                }
                cout<<"\nIntroduzca el ID del usuario, el ID de la reserva y el ID de la maquina a modificar.\nSiendo el ID de la reserva el primer número y el ID de la maquina el posterior a la fecha"<<endl;
                cout<<"ID usuario: ";
                cin>>user_id;
                cout<<"ID reserva: ";
                cin>>r_id;
                cout<<"ID maquina: ";
                cin>>m_id;
                cout<<endl;
                respuesta=r.modificarReserva(user_id, r_id);
                if(respuesta=="ELIMINAR"){
                    if(r.deleteReserva(user_id, r_id)==false){
                        cout<<"Saliendo del sistema..."<<endl;
                        exit(EXIT_FAILURE);
                    }
                    if(m.deleteReserva(m_id, r_id)==false){
                        cout<<"Saliendo del sistema..."<<endl;
                        exit(EXIT_FAILURE);
                    }
                    cout<<"Reserva eliminada correctamente"<<endl;
                }
                else{
                cout<<"Introduzca la fecha de comienzo de la reserva:"<<endl;
                cout<<"Día: ";
                cin>>fecha.day;
                cout<<"Mes: ";
                cin>>fecha.month;
                cout<<"Año: ";
                cin>>fecha.year;
                cout<<endl;
                if(r.setDate(fecha)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }
                cout<<"Fecha asignada correctamente"<<endl;

                cout<<"\nIntroduzca el número de días de la reserva: ";
                cin>>time;
                cout<<endl;
                if(r.setTime(time)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }
                cout<<"Tiempo asignado correctamente"<<endl;

                cout<<"\nIntroduzca el ID de la maquina a reservar: ";
                cin>>m_id;
                if(r.setMachine(m_id)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }

                if(m.findMachine(m_id)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }
                cout<<"\nMáquina encontrada"<<endl;

                cout<<"\nIntroduzca el número de núcleos que desea reservar: ";
                cin>>nucleus;
                if(r.setNucleus(nucleus)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }

                if(m.selectMachine(m_id, fecha, time, nucleus)==false){
                    cout<<"Máquina no disponible, no tiene los núcleos solicitados."<<endl;
                    maquinas=m.listMachine(fecha, time, nucleus);
                    cout<<"Introduzca el id de la maquina que apareceran a continuacion para reservar esos nucleos"<<endl;
                    list <string>:: iterator it = maquinas.begin();
                    while(it != maquinas.end()){
                        cout<<"\t"<<*it++<<endl;
                    }
                    cin>>m_id;
                    if(m.selectMachine(m_id, fecha, time, nucleus)==false){
                        cout<<"ERROR"<<endl;
                        exit(EXIT_FAILURE);
                    }
                }
                if(r.crearReserva(ID, fecha ,m_id ,nucleus ,time)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }
                r.deleteReserva(user_id,r_id);
                m.deleteReserva(m_id,r_id);
                r.crearReserva(user_id,fecha,m_id,nucleus,time);
                cout<<"Reserva modificada correctamente."<<endl;
                }
            break;

            case 3:
                Usuario_administrador_de_usuarios user();
                cout<<"Introduzca el ID de la persona a modificar: ";
                cin>>user_id;
                respuesta=UAU.modificarUsuario(user_id);
                if(respuesta=="ELIMINAR"){
                    if(UAU.deleteUser(user_id)==false){
                        cout<<"Saliendo del sistema..."<<endl;
                        exit(EXIT_FAILURE);
                    }
                    cout << "Usuario eliminado correctamente" << endl;
                }
                else{
                    cout << "Introduzca el ID del usuario: ";
                    cin>>user_id;
                    cout<<"Introduzca la contraseña por defecto del usuario: ";
                    cin >>Password;
                    cout<<"Introduzca el nombre: ";
                    cin>>nombre;
                    cout<<"Introduzca el correo del usuario: ";
                    cin>>mail;
                    cout << "Introduzca el número de nucleos de los que dispondra dicho usuario";
                    cin>>nucleus;
                    cout<<"Introduzca el número de días de los que dispondrá dicho usuario";
                    cin>>time;
                    UAU.deleteUser(user_id);
                    UAU.crearUser(user_id,Password,nombre, mail, nucleus, time);
                }

            break;

            case 4:
                cout<<"Introduzca el ID de la máquina que quiere modificar o el ID de una máquina nueva: ";
                cin>>m_id;
                respuesta=m.modificarMachine(m_id);
                if(respuesta=="Eliminar"){
                    /*if(m.deleteMachine(m_id)==false){
                            cout<<"Saliendo del sistema..."<<endl;
                            exit(EXIT_FAILURE);
                        }
                    cout << "Maquina eliminada correctamente" << endl;*/
                }
                else{
                    cout << "Introduzca el ID de la maquina: ";
                    cin>>m_id;
                    cout<<"Introduzca el número de núcleos que tiene dicha máquina ";
                    cin >>nucleus;
                    //m.deleteMachine(m_id);
                    //m.crearMaquina(m_id, nucleus);
                }

            break;
        }
    }while(opcion!=5);
    system("clear");
    cout<<"\t\t\tGracias por usar el sistema de gestión de núcleos"<<endl;
    cout<<"\t\t\t\t\t¡Hasta pronto!  =)"<<endl;
}