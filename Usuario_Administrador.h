#include <string>
using namespace std;

class Usuario_administrador{
	protected:
		int UA_ID_;
		string UA_Password_;
		string UA_Name_;
		string UA_Mail_;

		inline string getPassword(){return UA_Password_; };
	public:
		inline int getID(){return UA_ID_; };
		inline string getName(){return UA_Name_; };
		inline string getMail(){return UA_Mail_; };
		bool setMail(string mail);
		bool setPassword(string password);
		bool setName(string name);
};
class Usuario_administrador_de_usuarios : public Usuario_administrador{
	private:
		int UA_Type_;
	public:
		Usuario_administrador_de_usuarios(int id, string password, string name, string mail);
};
class Usuario_administrador_de_maquinas : public Usuario_administrador{
	private:
		int UA_Type_;
	public:
		Usuario_administrador_de_maquinas(int id, string password, string name, string mail);
};
