//Definition of class Maquina

#ifndef MAQUINA_H
#define MAQUINA_H

#include <string>
#include <list>
#include <ctime>

#include "reserva.h"

using namespace std;

typedef struct
{
	int day;
	int month;
	int year;
} date;

class Maquina
{

	private:
		int M_ID;
		int M_Nucleus;
		int M_NOcuped;

	public:
		Maquina(int machine_ID, int machine_Nucleus, int machine_NOcuped = 0);

		int getID();
		int getNucleus();
		bool setNucleus(int machine_Nucleus);

		int getNOcuped();
		bool setNOcuped(int machine_NOcuped, int OTime);

		bool setDate(date machine_Date);
		bool setTime(int machine_Time);

		list <Maquina> getInfo(list <Reserva> list_Reservas);

};

#endif