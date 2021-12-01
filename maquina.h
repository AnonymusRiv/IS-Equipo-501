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
		int M_ID_;
		int M_Nucleus_;
		int M_NOcuped_;

	public:
		Maquina(int machine_ID, int machine_Nucleus, int machine_NOcuped = 0);

		inline int getID(){return M_ID_;};
		inline int getNucleus(){return M_Nucleus_;};
		bool setNucleus(int machine_Nucleus);

		inline int getNOcuped(){return M_NOcuped_;};
		bool setNOcuped(int machine_NOcuped, int OTime);

		bool setDate(date machine_Date);
		bool setTime(int machine_Time);

		list <Maquina> getInfo(list <Reserva> list_Reservas);

};

#endif
