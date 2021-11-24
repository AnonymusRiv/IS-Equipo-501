#include "string"
using namespace std;

class Usuario_normal{
	public:
		int UN_ID_;
		string UN_Name_;
		string UN_Password_;
		string UN_Mail_;
		int UN_Nucleus_;
		int N_Time;
	private:
		 int UsuarioNormal();
		int getId();
		string getPassword();
		bool setPassword();
		string getName();
		bool setName();
		string getMail();
		bool setMail();
		int getNucleus();
		int getTime();
};

class Usuario_administrador{
	public:
		int UA_ID_;
		string UA_Password_;
		string UA_Name_;
		string UA_Mail_;
	private:
		int getId();
		string getPassword();
		bool setPassword();
		string getName();
		bool setName();
		string getMail();
		bool setMail();
};
class Usuario_administrador_de_usuarios{
	public:
		int UA_Type_;
	private:
		bool UAdministradorUsuarios();
};


