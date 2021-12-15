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
    Sistema s;
    Reserva r = Reserva(1, dates, 1, 1, 1);
    Maquina m = Maquina(1, 1);
    //Usuario_Normal UN;

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
    cout<<"Por favor introduzca su identificador para acceder al sistema: ";
    cin>>cadena;
    ID=stoi(cadena);
    cout<<"Introduzca su contraseña: ";
    cin>>Password;
    s.login(ID, Password);
    cout<<"\n----------------------INSTRUCCIONES QUE PUEDE REALIZAR EN EL SISTEMA--------------------------------"<<endl;
    cout<<"\t\t\t\t1. Crear reserva"<<endl;
    cout<<"\t\t\t\t2. Modificar reserva"<<endl;
    cout<<"\t\t\t\t3. Modificar usuario"<<endl;
    cout<<"\t\t\t\t4. Modificar maquina"<<endl;
    cout<<"\t\t\t\t5. Salir del sistema"<<endl;
    cin>>opcion;
    while(opcion!=5){
        switch(opcion){
            case 1:
                cout<<"Introduzca la fecha de comienzo de la reserva:"<<endl;
                cout<<"Dia: ";
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

                cout<<"Introduzca el numero de dias de dicha reserva: ";
                cin>>time;
                cout<<endl;
                if(r.setTime(time)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }
                cout<<"Tiempo asignado correctamente"<<endl;

                cout<<"Introduzca el ID de la maquina a reservar: ";
                cin>>m_id;
                if(r.setMachine(m_id)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }

                if(m.findMachine(m_id)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }
                cout<<"Maquina encontrada"<<endl;

                cout<<"Introduzca el numero de nucleos que desea reservar: ";
                cin>>nucleus;
                if(r.setNucleus(nucleus)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    exit(EXIT_FAILURE);
                }
                cout<<"Nucleos asignados correctamente"<<endl;

                if(m.selectMachine(m_id, fecha, time, nucleus)==false){
                    //añadir dentro del fichero maquina.cc la escritura de la maquina en la base de datos
                    maquinas=m.listMachine(fecha, time, nucleus);
                    cout<<"Maquina no disponible, no tiene los nucleos solicitados."<<endl;
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
                //if(r.crearReserva(ID, , , , ,))
                //!guardar la reserva en el fichero
                cout<<"Reserva realizada correctamente."<<endl;
            break;

            case 2:
                {
                reservas=r.listReservas(ID);
                list <string>:: iterator it = reservas.begin();
                while(it != reservas.end()){
                    cout<<"\t"<<*it++<<endl;
                }
                cout<<"Introduzca el ID del usuario, el ID de la reserva y el ID de la maquina a modificar."<<endl;
                cout<<"ID usuario: ";
                cin>>user_id;
                cout<<"\nID reserva: ";
                cin>>r_id;
                cout<<"\nID maquina: ";
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
                    cout<<"Dia: ";
                    cin>>fecha.day;
                    cout<<"\nMes: ";
                    cin>>fecha.month;
                    cout<<"\nAño: ";
                    cin>>fecha.year;
                    cout<<endl;
                    if(r.setDate(fecha)==false){
                        cout<<"Saliendo del sistema..."<<endl;
                        exit(EXIT_FAILURE);
                    }
                    cout<<"Fecha asignada correctamente"<<endl;

                    cout<<"Introduzca el numero de dias de dicha reserva: ";
                    cin>>time;
                    cout<<endl;
                    if(r.setTime(time)==false){
                        cout<<"Saliendo del sistema..."<<endl;
                        exit(EXIT_FAILURE);
                    }
                    cout<<"Tiempo asignado correctamente"<<endl;

                    cout<<"Introduzca el ID de la maquina a reservar: ";
                    cin>>m_id;
                    if(r.setMachine(m_id)==false){
                        cout<<"Saliendo del sistema..."<<endl;
                        exit(EXIT_FAILURE);
                    }

                    if(m.findMachine(m_id)==false){
                        cout<<"Saliendo del sistema..."<<endl;
                        exit(EXIT_FAILURE);
                    }
                    cout<<"Maquina encontrada"<<endl;

                    cout<<"Introduzca el numero de nucleos que desea reservar: ";
                    cin>>nucleus;
                    if(r.setNucleus(nucleus)==false){
                        cout<<"Saliendo del sistema..."<<endl;
                    }
                    cout<<"Nucleos asignados correctamente"<<endl;

                    if(m.selectMachine(m_id, fecha, time, nucleus)==false){
                        //añadir dentro del fichero maquina.cc la escritura de la maquina en la base de datos
                        maquinas=m.listMachine(fecha, time, nucleus);
                        cout<<"Maquina no disponible, no tiene los nucleos solicitados."<<endl;
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
                    //añadir una funcion para guardar la reserva en el fichero
                    cout<<"Reserva modificada correctamente."<<endl;
                }
            }
            break;

            case 3:
                //poner si no es UA que dalga q no tiene permisos
                cout<<"Introduzca el ID de la persona a modificar: ";
                cin>>user_id;
                //respuesta=UN.modificarUsuario(user_id);
                //cambiar las funciones a publicas de UA_maquinas y UA_usuarios
                if(respuesta=="ELIMINAR"){

                }
                else{

                }

            break;

            case 4:
                cout<<"Introduzca el ID de la maquina que quiere modificar o el ID de una maquina nueva: ";
                cin>>m_id;
                respuesta=m.modificarMachine(m_id);    //añadir dentro de modificarMachine la opción de cancelar
                if(respuesta=="Eliminar"){

                }
                else{

                }

            break;
        }
    }
    cout<<"Gracias por usar el sistema de gestion de nucleos"<<endl;
    cout<<"¡Hasta pronto!"<<endl;
}