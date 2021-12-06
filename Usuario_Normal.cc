#include "Usuario_Normal.h"
#include <iostream>
#include <string>

using namespace std;

Usuario_Normal::Usuario_Normal(int id, string name, string password, string mail, int nucleus, int time){
	UN_ID_=id;
	UN_Name_=name;
	UN_Password_=password;
	UN_Mail_=mail;
	UN_Nucleus_=nucleus;
	UN_Time_=time;
}

bool Usuario_Normal::setID(int id){
	if(id<=0){
			return false;
		}
		UN_ID_=id;
		return true;
}

bool Usuario_Normal::setName(string name){
	if(name==""){
		return false;
	}
	UN_Name_=name;
	return true;
}

bool Usuario_Normal::setNucleus(int nucleus){
	if(nucleus<=0){
				return false;
			}
			UN_Nucleus_=nucleus;
			return true;
}

bool Usuario_Normal::setTime(int time){
	if(time<=0){
				return false;
			}
			UN_Time_=time;
			return true;
}

bool Usuario_Normal::deleteUser(int id){
	if(id<=0){
				return false;
			}
			UN_ID_=0;
			return true;
}

bool Usuario_Normal::setPassword(string password){
	if(password==""){
		return false;
	}
	UN_Password_=password;
	return true;
}

bool Usuario_Normal::setMail(string mail){
	if(mail==""){
		return false;
	}
	UN_Mail_=mail;
	return true;
}
