#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "maquina.h"



void thisIsATest() {
	ASSERTM("start writing tests", false);	
}

void testSetNucleus()
{
	int nucl = -2;
	Maquina m = Maquina(1,nucl,15);
	bool resultado = m.setNucleus(nucl);
	ASSERT(resultado == false);

	int nucl1 = 5;
	Maquina m1 = Maquina(1,nucl1,2);
	resultado = m1.setNucleus(nucl1);
	ASSERT(resultado == true);
}

void testSetID()
{
	Maquina m = Maquina(2,12,2);
	bool resultado = m.setID(12);
	ASSERT(resultado == false);

	Maquina m1 = Maquina(4,4,4);
	 resultado = m1.setID(4);
	ASSERT(resultado == true);
}

void testFindMachine()
{
	Maquina m = Maquina(5,32,5);
	bool resultado = m.findMachine(32);
	ASSERT(resultado == false);

	Maquina m1 = Maquina(1,1,1);
	resultado = m1.findMachine(1);
	ASSERT(resultado == true);
}

void testSelectMachine()
{
	date hoy;
	hoy.day="16";
	hoy.month="12";
	hoy.year="2021";

	Maquina m = Maquina(1,2,5);
	bool resultado = m.selectMachine(1,hoy,5,2);
	ASSERT(resultado == false);

	Maquina m1 = Maquina(1,1,4);
	resultado = m1.selectMachine(1,hoy,3,1);
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
