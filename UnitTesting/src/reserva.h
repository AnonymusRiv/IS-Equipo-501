#ifndef RESERVA_H
#define RESERVA_H

#include <ctime>
#include <list>
#include "Usuario_Normal.h"
#include "Usuario_Administrador.h"

typedef struct{
    string day;
    string month;
    string year;
}date;

class Reserva{
    private:
        int R_ID_;
        int R_User_;
        date R_Date_;
        int R_Machine_;
        int R_Nucleus_;
        int R_Time_;

        bool esUsuarioNormal(int user_ID);
        bool esUsuarioAdmin(int user_ID);
        list <string> fileToList(int user_ID);
        list <string> unifyList(string user, list <string> aux);
    public:
        Reserva(int user_ID, date res_date, int res_Machine, int res_Nucleus, int res_Time, int res_ID=0);
        bool setDate(date date);
        bool setTime(int time);
        bool setMachine(int machine_ID);
        bool setNucleus(int nucleus);
        list <string> listReservas(int user_ID);
        string modificarReserva(int user_ID, int reserva_ID);
        bool deleteReserva(int user_ID, int reserva_ID);
        bool crearReserva(int user_ID, date res_date, int res_Machine, int res_Nucleus, int res_Time);
};

#endif