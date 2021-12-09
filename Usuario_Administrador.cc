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

bool Usuario_administrador::setMail(string mail){
	if(mail==""){
		cout << "ERROR. Correo no válido" << endl;
			return false;
	}
	UA_Mail_=mail;
	return true;
}

bool Usuario_administrador::setPassword(string password){
	if(password==""){
		cout << "ERROR. Contraseña no válida" << endl;
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