#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "reserva.h"
#include "Usuario_Administrador.h"
#include "Usuario_Normal.h"
#include "maquina.h"

void thisIsATest() {
	ASSERTM("start writing tests", false);	
}

void testSetDate(){
	date hoy;
	hoy.day="16";
	hoy.month="12";
	hoy.year="2021";
	Reserva res1=Reserva(1, hoy, 1, 1, 1, 1);
	bool resultado=res1.setDate(hoy);
	ASSERT(resultado==true);

	date ayer;
	ayer.day="16";
	ayer.month="12";
	ayer.year="2021";
	Reserva res1=Reserva(1, ayer, 1, 1, 1, 1);
	bool resultado=res1.setDate(ayer);
	ASSERT(resultado==true);
}

void testSetTime(){
	date hoy;
	Reserva res1=Reserva(1,hoy,1,1,-2);
	bool resultado=res1.setTime(-2);
	ASSERT(resultado==false);

	Reserva res2=Reserva(1,hoy,1,1,2);
	bool resultado=res2.setTime(2);
	ASSERT(resultado==true);
}

void testSetMachine(){
	date hoy;
	Reserva res1=Reserva(1,hoy,51,1,1);
	bool resultado=res1.setMachine(51);
	ASSERT(resultado==false);

	Reserva res2=Reserva(1,hoy,1,1,1);
	bool resultado=res2.setMachine(1);
	ASSERT(resultado==true);
}

void testSetNucleus(){
	date hoy;
	Reserva res1=Reserva(1,hoy,1,15,1);
	bool resultado=res1.setNucleus(15);
	ASSERT(resultado==false);

	Reserva res2=Reserva(1,hoy,1,3,1);
	bool resultado=res2.setNucleus(3);
	ASSERT(resultado==true);
}

void testDeleteReserva(){
	date hoy;
	Reserva res1=Reserva(-2,hoy,1,1,1,2);
	bool resultado=res1.deleteReserva(-2,2);
	ASSERT(resultado==false);

	date hoy;
	Reserva res2=Reserva(2,hoy,1,1,1,2);
	bool resultado=res1.deleteReserva(2,2);
	ASSERT(resultado==true);
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
