#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Usuario_Administrador.h"
#include "Usuario_Normal.h"
#include <string>

using namespace std;

void thisIsATest() {
	ASSERTM("start writing tests", true);
}

void testCrearUser(){
	int id;
	bool resultado;
	id=8;
	Usuario_Normal usuarionormal1(id, "name", "123456", "user@gmail.com", 0, 0);
	Usuario_administrador_de_usuarios usuario1(1, "123456", "name", "user@gmail.com");
	resultado=usuario1.crearUser(id, "name", "123456", "user@gmail.com", 0, 0);
		ASSERT(resultado==true);
	id=-1;
	Usuario_Normal usuarionormal2(id, "name", "123456", "user@gmail.com", 0, 0);
	Usuario_administrador_de_usuarios usuario2(2, "123456", "name", "user@gmail.com");
	resultado=usuario2.crearUser(id, "name", "123456", "user@gmail.com", 0, 0);
		ASSERT(resultado==false);
	id=0;
	Usuario_Normal usuarionormal3(id, "name", "123456", "user@gmail.com", 0, 0);
	Usuario_administrador_de_usuarios usuario3(3, "123456", "name", "user@gmail.com");
	resultado=usuario3.crearUser(id, "name", "123456", "user@gmail.com", 0, 0);
		ASSERT(resultado==false);
}

void testModificarUsuario(){
	int id;
	string resultado;
	id=8;
	Usuario_Normal usuarionormal1(id, "name", "123456", "user@gmail.com", 0, 0);
	Usuario_administrador_de_usuarios usuario1(1, "123456", "name", "user@gmail.com");
	usuario1.crearUser(id, "name", "123456", "user@gmail.com", 0, 0);
		resultado=usuario1.modificarUsuario(id);
		ASSERT_EQUAL("MODIFICAR", resultado);
	id=-1;
	Usuario_Normal usuarionormal2(id, "name", "123456", "user@gmail.com", 0, 0);
	Usuario_administrador_de_usuarios usuario2(2, "123456", "name", "user@gmail.com");
	usuario2.crearUser(id, "name", "123456", "user@gmail.com", 0, 0);
		resultado=usuario2.modificarUsuario(id);
		ASSERT_EQUAL("", resultado);
	id=0;
	Usuario_Normal usuarionormal3(id, "name", "123456", "user@gmail.com", 0, 0);
	Usuario_administrador_de_usuarios usuario3(3, "123456", "name", "user@gmail.com");
	usuario3.crearUser(id, "name", "123456", "user@gmail.com", 0, 0);
		resultado=usuario3.modificarUsuario(id);
		ASSERT_EQUAL("", resultado);
}

void testDeleteUser(){
	int id;
	bool resultado;
	id=8;
	Usuario_Normal usuarionormal1(id, "name", "123456", "user@gmail.com", 0, 0);
	Usuario_administrador_de_usuarios usuario1(1, "123456", "name", "user@gmail.com");
	usuario1.crearUser(id, "name", "123456", "user@gmail.com", 0, 0);
		resultado=usuario1.deleteUser(id);
		ASSERT(resultado==true);
	id=-1;
	Usuario_Normal usuarionormal2(id, "name", "123456", "user@gmail.com", 0, 0);
	Usuario_administrador_de_usuarios usuario2(2, "123456", "name", "user@gmail.com");
	usuario2.crearUser(id, "name", "123456", "user@gmail.com", 0, 0);
		resultado=usuario2.deleteUser(id);
		ASSERT(resultado==false);
	id=0;
	Usuario_Normal usuarionormal3(id, "name", "123456", "user@gmail.com", 0, 0);
	Usuario_administrador_de_usuarios usuario3(3, "123456", "name", "user@gmail.com");
	usuario3.crearUser(id, "name", "123456", "user@gmail.com", 0, 0);
		resultado=usuario3.deleteUser(id);
		ASSERT(resultado==false);
}

void testSetPassword(){
	string password;
	bool resultado;
	password="123456";
	Usuario_administrador_de_usuarios usuario1(1, password, "name", "user@gmail.com");
		resultado=usuario1.setPassword(password);
		ASSERT(resultado==true);
	Usuario_administrador_de_maquinas usuario2(1, password, "name", "user@gmail.com");
		resultado=usuario2.setPassword(password);
		ASSERT(resultado==true);
	password="12345";
	Usuario_administrador_de_usuarios usuario3(1, password, "name", "user@gmail.com");
		resultado=usuario3.setPassword(password);
		ASSERT(resultado==false);
	Usuario_administrador_de_maquinas usuario4(1, password, "name", "user@gmail.com");
		resultado=usuario4.setPassword(password);
		ASSERT(resultado==false);
	password="";
	Usuario_administrador_de_usuarios usuario5(1, password, "name", "user@gmail.com");
		resultado=usuario5.setPassword(password);
		ASSERT(resultado==false);
	Usuario_administrador_de_maquinas usuario6(1, password, "name", "user@gmail.com");
		resultado=usuario6.setPassword(password);
		ASSERT(resultado==false);
}

void testSetMail(){
	string mail;
	bool resultado;
	mail="user@gmail.com";
	Usuario_administrador_de_usuarios usuario1(1, "123456", "name", mail);
		resultado=usuario1.setMail(mail);
			ASSERT(resultado==true);
	Usuario_administrador_de_maquinas usuario2(1, "123456", "name", mail);
		resultado=usuario2.setMail(mail);
		ASSERT(resultado==true);
	mail="user.com";
	Usuario_administrador_de_usuarios usuario3(1, "123456", "name", mail);
		resultado=usuario3.setMail(mail);
		ASSERT(resultado==false);
	Usuario_administrador_de_maquinas usuario4(1, "123456", "name", mail);
		resultado=usuario4.setMail(mail);
		ASSERT(resultado==false);
	mail="user@gmail";
	Usuario_administrador_de_usuarios usuario5(1, "123456", "name", mail);
		resultado=usuario5.setMail(mail);
			ASSERT(resultado==false);
	Usuario_administrador_de_maquinas usuario6(1, "123456", "name", mail);
		resultado=usuario6.setMail(mail);
		ASSERT(resultado==false);
	mail="";
	Usuario_administrador_de_usuarios usuario7(1, "123456", "name", mail);
		resultado=usuario7.setMail(mail);
			ASSERT(resultado==false);
	Usuario_administrador_de_maquinas usuario8(1, "123456", "name", mail);
		resultado=usuario8.setMail(mail);
		ASSERT(resultado==false);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(thisIsATest));
	s.push_back(CUTE(testCrearUser));
	s.push_back(CUTE(testModificarUsuario));
	s.push_back(CUTE(testDeleteUser));
	s.push_back(CUTE(testSetPassword));
	s.push_back(CUTE(testSetMail));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
