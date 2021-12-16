#include "Usuario_Administrador.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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

    ifstream file("Usuarios_Normales.txt");
    if(!file){
        cout << "ERROR al abrir el fichero\n";
        exit(EXIT_FAILURE);
    }

    ofstream fileAux("fileAux.txt");
    if(!fileAux){
        cout << "ERROR al abrir el fichero\n";
        exit(EXIT_FAILURE);
    }
	string datos;
	string userID=to_string(id);
    getline(file,datos,'\n');
    int pos=datos.find(" ");
    string uID=datos.substr(0,pos);
    while(!file.eof()){
        if(uID!=userID){
            fileAux << datos << endl;
        }
        getline(file,datos,'\n');
        pos=datos.find(" ");
        uID=datos.substr(0,pos);
    }
    file.close();
    fileAux.close();

    remove("Usuarios_Normales.txt");
    cout << "Fichero eliminado\n";
    rename("fileAux.txt", "Usuarios_Normales.txt");

	ifstream file1("UsuariosN.txt");
    if(!file1){
        cout << "ERROR al abrir el fichero\n";
        exit(EXIT_FAILURE);
    }

    ofstream fileAux1("fileAux1.txt");
    if(!fileAux1){
        cout << "ERROR al abrir el fichero\n";
        exit(EXIT_FAILURE);
    }
    getline(file,datos,'\n');
    while(!file1.eof()){
        if(datos!=userID){
            fileAux1 << datos << endl;
			getline(file1,datos,'\n');
            fileAux1 << datos << endl;
			getline(file1,datos,'\n');
            fileAux1 << datos << endl;
        }
		else{
			getline(file1,datos,'\n');
			getline(file1,datos,'\n');
		}
        getline(file1,datos,'\n');
    }
    file1.close();
    fileAux1.close();

    remove("Usuarios_Normales.txt");
    cout << "Fichero eliminado\n";
    rename("fileAux.txt", "Usuarios_Normales.txt");

	string usuario_normalID=to_string(id);
	string fichero=usuario_normalID+".txt";
	if(remove(fichero.c_str())!=0){
		cout << "ERROR al eliminar el fichero\n";
		return false;
	} else{
		cout << "Fichero eliminado\n";
		return true;
    }
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
	ifstream file("UsuariosN.txt");
	if(!file){
		cout<<"Error al abrir el fichero"<<endl;
		cout<<"Saliendo del sistema..."<<endl;
		exit(EXIT_FAILURE);
	}
	
	int select;
	string userID=to_string(id);
	string datos;
	getline(file,datos,'\n');
	while(!file.eof()){
		if(datos==userID){
			system("clear");
    	    selection:
    	    cout << "Seleccione la acción que desea realizar con la reserva:\n";
    	    cout << "1. ELIMINAR usuario\n";
    	    cout << "2. MODIFICAR usuario\n";
    	    cin >> select;
    	    if(select==1){
    	        return "ELIMINAR";
    	    }
    	    else if(select==2){
    	        return "MODIFICAR";
    	    }
    	    else{
    	        cout << "Seleccione una opción válida\n";
    	        goto selection;
    	    }
    	}
		getline(file,datos,'\n');
		getline(file,datos,'\n');
		getline(file,datos,'\n');
	}
    file.close();

	cout<<"Usuario no encontrado"<<endl;
	cout<<"Saliendo del sistema..."<<endl;
	exit(EXIT_FAILURE);

}

bool Usuario_administrador::crearUser(int user_ID, string user_password, string user_name, string user_Mail, int user_Nucleus, int user_Time){
	fstream file1(("Usurios_Normales.txt"),fstream::app);
	if(!file1){
		cout<<"Error al abrir el fichero"<<endl;
		return false;
	}
	
    file1 << user_ID << " " << user_password << " " << user_name << " " << user_Mail<< " " << user_Nucleus << " " << user_Time << endl;
    file1.close();

	fstream file2("UsuariosN.txt",fstream::app);
	if(!file2){
		cout<<"Error al abrir el fichero"<<endl;
		return false;
	}
	file2 << user_ID << endl << user_password << endl << user_name << endl;
	file2.close();

    return true;
}