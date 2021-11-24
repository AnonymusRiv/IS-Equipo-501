//Definition of class Reserva

#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include <ctime>
#include <list>

typedef struct{
    int day;
    int month;
    int year;
}date;

class Reserva{
    private:
        int R_ID_;
        int R_User_;
        date R_Date_;
        int R_Machine;
        int R_Nucleus;
        int R_Time;
    public:
        Reserva(int res_ID=0, int user_ID, date res_date, int res_Machine, int res_Nucleus, int res_Time);
        void getReservas(int user_ID);
        void crearReserva(int user_ID, date res_Date, int machine_ID,int res_Nucleus, int res_Time);
        bool modificarReserva(int res_ID);
};

#endif