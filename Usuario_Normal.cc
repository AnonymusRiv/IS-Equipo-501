#include "Usuario_Normal.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

Usuario_Normal::Usuario_Normal(int id, string name, string password, string mail, int nucleus, int time){
	UN_ID_=id;
	UN_Name_=name;
	UN_Password_=password;
	UN_Mail_=mail;
	UN_Nucleus_=nucleus;
	UN_Time_=time;
}

bool Usuario_Normal::setID(int id){
	if(id<=0){
		cout << "ERROR. ID no válido" << endl;
		return false;
	}
	UN_ID_=id;
	return true;
}

bool Usuario_Normal::setName(string name){
	if(name==""){
		cout << "ERROR. Nombre no válido" << endl;
		return false;
	}
	UN_Name_=name;
	return true;
}

bool Usuario_Normal::setNucleus(int nucleus){
	if(nucleus<=0){
		cout << "ERROR. Núcleos no válidos" << endl;
		return false;
	}
	UN_Nucleus_=nucleus;
	return true;
}

bool Usuario_Normal::setTime(int time){
	if(time<=0){
		cout << "ERROR. Tiempo no válido" << endl;
		return false;
	}
	UN_Time_=time;
	return true;
}

string Usuario_Normal::modificarUsuario(int id){
	string usuario_normalID=to_string(id);
	ifstream file(usuario_normalID+".txt");
    if(!file){
        cout << "ERROR al abrir el fichero\n";
        EXIT_FAILURE;
    }
    int select;
    string usuario;
    getline(file,usuario,' ');
    while(!file.eof()){
        if(usuario==usuario_normalID){
            selection:
            system("clear");
            cout << "Seleccione la acción que desea realizar con el usuario:\n";
            cout << "1. ELIMINAR usuario\n";
            cout << "2. MODIFICAR usuario\n";
            cin >> select;
            if(select==1){
                return "CANCELAR";
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
}

bool Usuario_Normal::deleteUser(int id){
	if(id<=0){
		cout << "ERROR. ID no válido" << endl;
		return false;
	}

	string usuario_normalID=to_string(id);
	string fichero=usuario_normalID+".txt";
	if(remove(fichero.c_str())!=0){
    	cout << "ERROR al eliminar el fichero\n";
    	return false;
	} else{
    	cout << "Fichero eliminado\n";
    }
	return true;
}

bool Usuario_Normal::setPassword(string password){
	if(password==""){
		cout << "ERROR. Contraseña no válida" << endl;
		return false;
	}else if(password.length()<6){
		cout << "ERROR. Contraseña no válida, inserte al menos seis caracteres" << endl;
		return false;
	}
	UN_Password_=password;
	return true;
}

bool Usuario_Normal::setMail(string mail){
	if(mail==""){
		cout << "ERROR. Correo no válido" << endl;
		return false;
	}else if(mail.find('@')==string::npos){
		cout << "ERROR. Correo no válido, falta el @" << endl;
		return false;
	}else if(mail.find('.')==string::npos){
		cout << "ERROR. Correo no válido, falta el dominio" << endl;
		return false;
	}
	UN_Mail_=mail;
	return true;
}
