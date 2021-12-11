#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Usuario_Administrador.h"
#include <string>

using namespace std;

void thisIsATest() {
	ASSERTM("start writing tests", false);	
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
	mail="user.com";
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
