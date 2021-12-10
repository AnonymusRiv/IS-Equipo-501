#include <iostream>
#include <string>
#include <fstream>
#include "Sistema.h"

using namespace std;

Sistema::Sistema(){}

void Sistema::login(int ID, string Password){
    string cadena;
    int encontrado=0;
    int n_id;
    ifstream file("Usuarios_Normales.txt");
    if(!file){
        cout<<"ERROR al abrir el fichero"<<endl;
    }
    getline(file,cadena,' ');
    while (!file.eof()){
        n_id=stoi(cadena);
        if(ID==n_id){
            encontrado=1;
            getline(file,cadena,' ');
            cout<<"Indique su contraseña"<<endl;
            cin>>Password;
            if(Password==cadena){
                cout<<"login correcto"<<endl;
            }
            else{
                cout<<"contraseña incorrecta"<<endl;
            }
        }
    }
    file.close();
    ifstream file2("usuarios_administradores.txt");
    while (!file2.eof()) {
        getline(file2,cadena,' ');
        n_id=stoi(cadena);
        if(ID==n_id){
            encontrado=1;
            getline(file,cadena,' ');
            cout<<"Indique su contraseña"<<endl;
            cin>>Password;
            if(Password==cadena){
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
    file.close();
}