#include <iostream>
#include <string>
#include <fstream>
#include "sistema.h"

using namespace std;

sistema::sistema(){}

void sistema::acceso(int id, string password){
    char cadena[128];
    int encontrado=0;
    int n_id;
    cout<<"Indique su ID"<<endl;
    cin>>id;
    ifstream f("usuarios_normales.txt");
    while (!f.eof()) {
        f >> cadena;
        n_id=stoi(cadena);
        if(id==n_id){
            encontrado=1;
            f>>cadena;
            cout<<"Indique su contraseña"<<endl;
            cin>>password;
            if(password==cadena){
                cout<<"login correcto"<<endl;
            }
            else{
                cout<<"contraseña incorrecta"<<endl;
            }
        }
    }
    f.close();
    ifstream f("usuarios_administradores.txt");
    while (!f.eof()) {
        f >> cadena;
        n_id=stoi(cadena);
        if(id==n_id){
            encontrado=1;
            f>>cadena;
            cout<<"Indique su contraseña"<<endl;
            cin>>password;
            if(password==cadena){
                cout<<"login correcto"<<endl;
            }
            else{
                cout<<"contraseña incorrecta"<<endl;
            }
        }
    }
    if(encontrado==0){
        cout<<"ID no encontrado, compruebe que lo ha introducido correctamente, sino contacte con un administrador para darse de alta"<<endl;
    }
    f.close();
}