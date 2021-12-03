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

bool setNOcuped(int machine_NOcuped, int OTime)
{

}

bool setDate(date machine_Date)
{

}
