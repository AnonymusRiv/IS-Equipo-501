#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Sistema.h"

void thisIsATest() {
	ASSERTM("start writing tests", false);
}

void test_Usuario_Normal(){
	Sistema s;
	string Password="Hola";
	int ID=1234;
	s.login(ID, Password);
	//no daría error ya que se encuentra dicho ID y corresponde con su contraseña

	Password="Hola";
	ID=12;
	s.login(ID, Password);
	//da error ya que no coincide el valor de la contraseña con el ID introducido
}

void test_Usuario_Admin(){
	Sistema s;
	string Password="XxxX";
	int ID=123;
	s.login(ID, Password);
	//no daría error ya que se encuentra dicho ID y corresponde con su contraseña

	Password="Hola";
	ID=12;
	s.login(ID, Password);
	//da error ya que no coincide el valor de la contraseña con el ID introducido
}


bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(test_Usuario_Normal));
	s.push_back(CUTE(test_Usuario_Admin));
	s.push_back(CUTE(thisIsATest));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
