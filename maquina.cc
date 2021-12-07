#include "maquina.h"

using namespace std;

Maquina::Maquina(int machine_ID, int machine_Nucleus, int machine_NOcuped)
{
	M_ID_ = machine_ID;
	M_Nucleus_ = machine_Nucleus;
	M_NOcuped_ = machine_NOcuped;
}

bool setNucleus(int machine_Nucleus)
{
	if(machine_Nucleus.empty())
	{
		M_Nucleus_ = machine_Nucleus;
		return true;
	}
		return false;
	
}

bool setID(int machine_ID)
{
	M_ID_ = machine_ID;
}

bool findMachine(int machine_ID)
{
	if(M_ID_ == machine_ID)
	{
		return true;
	}
	return false;
}

bool selectMachine(int machine_ID, date date, int time, int nucleus)
{
	if(M_ID_ == machine_ID)
	{
		M_Nucleus_ = nucleus;
	}
}

list listMachine(date date, int time, int nucleus);

bool deleteReserva(int machine_ID, int reserva_ID);

string modificarMachine(int machine_ID);
