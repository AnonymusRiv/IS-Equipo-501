#include <iostream>
#include <string>
#include <fstream>
#include "Sistema.h"

using namespace std;

Sistema::Sistema(){}

void Sistema::login(int ID, string Password){
    string cadena;
    string nombre;
    int encontrado=0;
    string n_id;
    ifstream file("UsuariosN.txt");
    if(!file){
        cout<<"ERROR al abrir el fichero"<<endl;
    }
    getline(file,cadena,'\n');
    while (!file.eof() && encontrado==0){
        n_id=to_string(ID);
        if(cadena==n_id){
            encontrado=1;
            getline(file,cadena,'\n');
            if(Password==cadena){
                getline(file,nombre,'\n');
                cout<<"Login Correcto"<<endl;
            }
            else{
                cout<<"Contraseña Incorrecta"<<endl;
                exit(EXIT_FAILURE);
            }
        }
        getline(file,cadena,'\n');
    }

    file.close();

    string cadena2;
    string nombre2;

    ifstream file2("UsuariosA.txt");
    if(!file2){
        cout<<"ERROR al abrir el fichero"<<endl;
    }
    getline(file2,cadena2,'\n');
    while (!file2.eof() && encontrado==0) {
        n_id=to_string(ID);
        if(cadena2==n_id){
            encontrado=1;
            getline(file2,cadena2,'\n');
            if(Password==cadena2){
                getline(file2,nombre2,'\n');
                cout<<"Login Correcto"<<endl;
            }
            else{
                cout<<"Contraseña Incorrecta"<<endl;
                exit(EXIT_FAILURE);
            }
        }
        getline(file,cadena2,'\n');
    }
    file2.close();
    if(encontrado==0){
        cout<<"ID no encontrado, compruebe que lo ha introducido correctamente, si no contacte con un administrador para darse de alta"<<endl;
        exit(EXIT_FAILURE);
    }
    else{
        cout<<"Se ha accedido correctamente al sistema"<<endl;
        cout<<"Bienvenido "<<nombre<<endl;
    }
}