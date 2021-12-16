#include <iostream>
#include <string>
#include <fstream>
#include "Sistema.h"

using namespace std;

Sistema::Sistema(){}

void Sistema::login(int ID, string Password){
    string cadena;
    int encontrado=0;
    string n_id;
    ifstream file("Usuarios_Normales.txt");
    ifstream file2("Usuarios_Administradores.txt");
    if(!file){
        cout<<"ERROR al abrir el fichero"<<endl;
    }
    if(!file2){
        cout<<"ERROR al abrir el fichero"<<endl;
    }
    getline(file,cadena,' ');
    while (!file.eof() && encontrado==0){
        //cout<<cadena<<endl;
        n_id=to_string(ID);
        if(cadena==n_id){
            encontrado=1;
            getline(file,cadena,' ');
            if(Password==cadena){
                getline(file,cadena,' ');
                cout<<"login correcto"<<endl;
            }
            else{
                cout<<"contraseña incorrecta"<<endl;
                exit(EXIT_FAILURE);
            }
        }
        //cout<<cadena<<endl;
    }
    getline(file2,cadena,' ');
    while (file2>>cadena && encontrado==0) {
        getline(file2,cadena,' ');
        n_id=to_string(ID);
        if(cadena==n_id){
            encontrado=1;
            getline(file2,cadena,' ');
            if(Password==cadena){
                getline(file2,cadena,' ');
                cout<<"login correcto"<<endl;
            }
            else{
                cout<<"contraseña incorrecta"<<endl;
                exit(EXIT_FAILURE);
            }
        }
    }
    file.close();
    file2.close();
    if(encontrado==0){
        cout<<"ID no encontrado, compruebe que lo ha introducido correctamente, sino contacte con un administrador para darse de alta"<<endl;
        exit(EXIT_FAILURE);
    }
    else{
        cout<<"Se ha accedido correctamente al sistema"<<endl;
        cout<<"Bienvenido "<<cadena<<endl;
    }
}