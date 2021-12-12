#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "maquina.h"
#include "reserva.h"



void thisIsATest() {
	ASSERTM("start writing tests", false);	
}

void testSetNucleus()
{
	Maquina m = Maquina(1,10,15);
	bool resultado = m.setNucleus(-2);
	ASSERT(resultado == false);

	Maquina m1 = Maquina(1,10,2);
	bool resultado = m1.setNucleus(5);
	ASSERT(resultado == true);
}

void testSetID()
{
	Maquina m = Maquina(2,12,2);
	bool resultado = m.setID(12);
	ASSERT(resultado == false);

	Maquina m1 = Maquina(4,4,4);
	bool resultado = m1.setID(4);
	ASSERT(resultado == true);
}

void testFindMachine()
{
	Maquina m = Maquina(5,32,5);
	bool resultado = m.setID(32);
	ASSERT(resultado == false);

	Maquina m1 = Maquina(1,1,1);
	bool resultado = m1.setID(1);
	ASSERT(resultado == true);
}

void testSelectMachine()
{
	Maquina m = Maquina(1,2,5);
	bool resultado = m.setID(1,2);
	ASSERT(resultado == false);

	Maquina m1 = Maquina(1,1,4);
	bool resultado = m1.setID(1,1);
	ASSERT(resultado == true);
}



bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testSetNucleus));
	s.push_back(CUTE(testSetID));
	s.push_back(CUTE(testFindMachine));
	s.push_back(CUTE(testSelectMachine));
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
