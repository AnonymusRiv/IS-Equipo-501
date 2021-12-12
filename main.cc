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
    Sistema s;
    Reserva r; //se q tengo q añadirle los parametros y por eso da error esta linea y la siguiente, cuando acabe lo demas lo añadire
    Maquina m;

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
    cout<<"BIENVENIDO AL SISTEMA DE GESTION DE NUCLEOS"<<endl;
    cout<<"Por favor introduzca su identificador para acceder al sistema: ";
    cin>>cadena;
    ID=stoi(cadena);
    cout<<"\nIntroduzca su contraseña: ";
    cin>>Password;
    s.login(ID, Password);
    while(opcion!=5){
        cout<<"------INSTRUCCIONES QUE PUEDE REALIZAR EN EL SISTEMA------"<<endl;
        cout<<"1. Crear reserva"<<endl;
        cout<<"2. Modificar reserva"<<endl;
        cout<<"3. Modificar usuario"<<endl;
        cout<<"4. Modificar maquina"<<endl;
        switch(opcion){
            case 1:
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
                    EXIT_FAILURE;
                }
                cout<<"Fecha asignada correctamente"<<endl;

                cout<<"Introduzca el numero de dias de dicha reserva: ";
                cin>>time;
                cout<<endl;
                if(r.setTime(time)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    EXIT_FAILURE;
                }
                cout<<"Tiempo asignado correctamente"<<endl;

                cout<<"Introduzca el ID de la maquina a reservar: ";
                cin>>m_id;
                if(r.setMachine(m_id)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    EXIT_FAILURE;
                }

                if(m.findMachine(m_id)==false){
                    cout<<"Saliendo del sistema..."<<endl;
                    EXIT_FAILURE;
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
                    EXIT_FAILURE;
                    }
                }
                cout<<"Reserva realizada correctamente."<<endl;
            break;

            case 2:
                reservas=r.listReservas(ID);
                list <string>:: iterator it = reservas.begin();
                while(it != reservas.end()){
                    cout<<"\t"<<*it++<<endl;
                }
                cout<<"Introduzca el ID del usuario y el ID de la reserva a modificar."<<endl;
                cout<<"ID usuario: ";
                cin>>user_id;
                cout<<"\nID reserva: ";
                cin>>r_id;
                cout<<endl;
                respuesta=r.modificarReserva(user_id, r_id);
                if(respuesta=="ELIMINAR"){
                    if(r.deleteReserva(user_id, r_id)==false){
                        cout<<"Saliendo del sistema..."<<endl;
                        EXIT_FAILURE;
                    }
                    if(m.deleteReserva(m_id, r_id)==false){     //hay que  buscar el m_id
                        cout<<"Saliendo del sistema..."<<endl;
                        EXIT_FAILURE;
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
                        EXIT_FAILURE;
                    }
                    cout<<"Fecha asignada correctamente"<<endl;

                    cout<<"Introduzca el numero de dias de dicha reserva: ";
                    cin>>time;
                    cout<<endl;
                    if(r.setTime(time)==false){
                        cout<<"Saliendo del sistema..."<<endl;
                        EXIT_FAILURE;
                    }
                    cout<<"Tiempo asignado correctamente"<<endl;

                    cout<<"Introduzca el ID de la maquina a reservar: ";
                    cin>>m_id;
                    if(r.setMachine(m_id)==false){
                        cout<<"Saliendo del sistema..."<<endl;
                        EXIT_FAILURE;
                    }

                    if(m.findMachine(m_id)==false){
                        cout<<"Saliendo del sistema..."<<endl;
                        EXIT_FAILURE;
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
                        EXIT_FAILURE;
                        }
                    }
                    cout<<"Reserva modificada correctamente."<<endl;
                }
            break;

            case 3:

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
            case 5:

            break;
        }
    }
}