#ifndef USUARIO_NORMAL_H
#define USUARIO_NORMAL_H

#include <string>
using namespace std;

class Usuario_Normal{
	private:
		int UN_ID_;
		string UN_Name_;
		string UN_Password_;
		string UN_Mail_;
		int UN_Nucleus_;
		int UN_Time_;

		bool setID(int id);
		bool setName(string name);
		bool setNucleus(int nucleus);
		bool setTime(int time);
		inline string getPassword(){return UN_Password_; };
		string modificarUsuario(int id);
		bool deleteUser(int id);
	public:
		Usuario_Normal(int id, string name, string password, string mail, int nucleus=0, int time=0);
		inline int getId(){return UN_ID_; };
		inline string getName(){return UN_Name_; };
		inline string getMail(){return UN_Mail_; };
		inline int getNucleus(){return UN_Nucleus_; };
		inline int getTime(){return UN_Time_; };
		bool setPassword(string password);
		bool setMail(string mail);
};

#endif
