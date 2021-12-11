#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Usuario_Normal.h"
#include <string>

using namespace std;

void thisIsATest() {
	ASSERTM("start writing tests", false);	
}

/*void testSetID(){
	int id;
	bool resultado;
	id=1;
	Usuario_Normal usuario1(id, "name", "123456", "user@gmail.com");
		resultado=usuario1.setID(id);
		ASSERT(resultado==true);
	id=0;
	Usuario_Normal usuario2(id, "name", "123456", "user@gmail.com");
		resultado=usuario2.setID(id);
		ASSERT(resultado==false);
	id=-1;
	Usuario_Normal usuario3(id, "name", "123456", "user@gmail.com");
		resultado=usuario3.setID(id);
		ASSERT(resultado==false);
}*/

void testSetPassword(){
	string password;
	bool resultado;
	password="123456";
	Usuario_Normal usuario1(1, "name", password, "user@gmail.com", 0, 0);
		resultado=usuario1.setPassword(password);
		ASSERT(resultado==true);
	password="12345";
	Usuario_Normal usuario2(1, "name", password, "user@gmail.com", 0, 0);
		resultado=usuario2.setPassword(password);
		ASSERT(resultado==false);
	password="";
	Usuario_Normal usuario3(1, "name", password, "user@gmail.com", 0, 0);
		resultado=usuario3.setPassword(password);
		ASSERT(resultado==false);
}

void testSetMail(){
	string mail;
	bool resultado;
	mail="user@gmail.com";
	Usuario_Normal usuario1(1, "name", "123456", mail, 0, 0);
		resultado=usuario1.setMail(mail);
		ASSERT(resultado==true);
	mail="user.com";
	Usuario_Normal usuario2(1, "name", "123456", mail, 0, 0);
		resultado=usuario2.setMail(mail);
		ASSERT(resultado==false);
	mail="user.com";
	Usuario_Normal usuario3(1, "name", "123456", mail, 0, 0);
		resultado=usuario3.setMail(mail);
		ASSERT(resultado==false);
	mail="";
	Usuario_Normal usuario4(1, "name", "123456", mail, 0, 0);
		resultado=usuario4.setMail(mail);
		ASSERT(resultado==false);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(thisIsATest));
	//s.push_back(CUTE(testSetID));
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
