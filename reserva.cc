#include "reserva.h"
#include "maquina.h"
#include <iomanip>
#include <ctime>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

Reserva::Reserva(int res_ID, int user_ID, date res_date, int res_Machine, int res_Nucleus, int res_Time){
    R_ID_=res_ID;
    R_User_=user_ID;
    R_Date_.day=res_date.day;
    R_Date_.month=res_date.month;
    R_Date_.year=res_date.year;
    R_Machine=res_Machine;
    R_Nucleus=res_Nucleus;
    R_Time=res_Time;
}

bool setDate(date date);
bool setTime(int time);
bool setMachine(int machine_ID);
bool setNucleus(int nucleus);
list listReservas(int user_ID);
string modificarReserva(int user_ID, int reserva_ID);
bool deleteReserva(int user_ID, int reserva_ID);

bool setDate(date date){
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y");
    auto str = oss.str();
    if()
}