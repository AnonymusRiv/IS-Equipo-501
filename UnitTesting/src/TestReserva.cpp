#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "reserva.h"

void thisIsATest() {
	ASSERTM("start writing tests", false);	
}

void testSetDate(){
	date hoy;
	hoy.day="16";
	hoy.month="12";
	hoy.year="2021";
	Reserva res1=Reserva(1, hoy, 1, 1, 1, 1);
	bool resultado1=res1.setDate(hoy);
	ASSERT(resultado1==true);

	date ayer;
	ayer.day="16";
	ayer.month="12";
	ayer.year="2021";
	Reserva res2=Reserva(1, ayer, 1, 1, 1, 1);
	bool resultado2=res2.setDate(ayer);
	ASSERT(resultado2==true);
}

void testSetTime(){
	date hoy;
	int time=-2;
	Reserva res1=Reserva(1,hoy,1,1,1);
	bool resultado1=res1.setTime(time);
	ASSERT(resultado1==false);

	time=2;
	Reserva res2=Reserva(1,hoy,1,1,1);
	bool resultado2=res2.setTime(time);
	ASSERT(resultado2==true);
}

void testSetMachine(){
	date hoy;
	int machine=51;
	Reserva res1=Reserva(1,hoy,1,1,1);
	bool resultado1=res1.setMachine(machine);
	ASSERT(resultado1==false);

	machine=2;
	Reserva res2=Reserva(1,hoy,1,1,1);
	bool resultado2=res2.setMachine(machine);
	ASSERT(resultado2==true);
}

void testSetNucleus(){
	date hoy;
	int n=-3;
	Reserva res1=Reserva(1,hoy,1,1,1);
	bool resultado1=res1.setNucleus(n);
	ASSERT(resultado1==false);

	n=3;
	Reserva res2=Reserva(1,hoy,1,1,1);
	bool resultado2=res2.setNucleus(n);
	ASSERT(resultado2==true);
}

void testDeleteReserva(){
	date hoy;
	Reserva res1=Reserva(2,hoy,1,1,1,2);
	bool resultado1=res1.deleteReserva(-2,2);
	ASSERT(resultado1==false);

	Reserva res2=Reserva(2,hoy,1,1,1,2);
	bool resultado2=res1.deleteReserva(2,2);
	ASSERT(resultado2==true);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testSetDate));
	s.push_back(CUTE(testSetTime));
	s.push_back(CUTE(testSetMachine));
	s.push_back(CUTE(testSetNucleus));
	s.push_back(CUTE(testDeleteReserva));
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
