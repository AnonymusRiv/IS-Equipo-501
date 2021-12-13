#include "Usuario_Administrador.h"
#include <iostream>
#include <string>

Usuario_administrador_de_usuarios::Usuario_administrador_de_usuarios(int id, string password, string name, string mail){
	UA_ID_=id;
	UA_Password_=password;
	UA_Name_=name;
	UA_Mail_=mail;
	UA_Type_=1;
}

Usuario_administrador_de_maquinas::Usuario_administrador_de_maquinas(int id, string password, string name, string mail){
	UA_ID_=id;
	UA_Password_=password;
	UA_Name_=name;
	UA_Mail_=mail;
	UA_Type_=2;
}

bool Usuario_administrador::deleteUser(int id){
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

bool Usuario_administrador::setMail(string mail){
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
	UA_Mail_=mail;
	return true;
}

bool Usuario_administrador::setPassword(string password){
	if(password==""){
		cout << "ERROR. Contraseña no válida" << endl;
		return false;
	}else if(password.length()<6){
		cout << "ERROR. Contraseña no válida, inserte al menos seis caracteres" << endl;
		return false;
	}
	UA_Password_=password;
	return true;
}

bool Usuario_administrador::setName(string name){
	if(name==""){
		cout << "ERROR. Nombre no válido" << endl;
			return false;
	}
	UA_Name_=name;
	return true;
}

string Usuario_administrador::modificarUsuario(int id){
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
            	deleteUser(id);
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