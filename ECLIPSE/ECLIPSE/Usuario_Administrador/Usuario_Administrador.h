#include <string>
using namespace std;

class Usuario_administrador{
	private:
		int UA_ID_;
		string UA_Password_;
		string UA_Name_;
		string UA_Mail_;
	public:
		int getId();
		string getPassword();
		bool setPassword();
		string getName();
		bool setName();
		string getMail();
		bool setMail();
};
class Usuario_administrador_de_usuarios : public Usuario_administrador{
	private:
		int UA_Type_;
	public:
		UAdministradorUsuarios();
};