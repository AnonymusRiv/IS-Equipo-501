#ifndef Usuario_Normal_h
#define Usuario_Normal_h

#include <string>
using namespace std;

class Usuario_Normal{
	private:
		int UN_ID_;
		string UN_Name_;
		string UN_Password_;
		string UN_Mail_;
		int UN_Nucleus_;
		int UN_Time;
	public:
		Usuario_Normal(int id, string name, string password, string mail, int nucleus=0, int time=0);
		inline int getId(){return UN_ID_; };
		inline string getPassword(){return UN_Password_; };
		inline bool setPassword(string password){UN_Password_=password; };
		inline string getName(){return UN_Name_; };
		inline bool setName(string name){UN_Name_=name; };
		inline string getMail(){return UN_Mail_; };
		inline bool setMail(string mail){UN_Mail_=mail; };
		inline int getNucleus(){return UN_Nucleus_; };
		inline int getTime(){return UN_Time; };
};

#endif