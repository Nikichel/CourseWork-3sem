#include "access.h"

char* access::getLogin() {		//получить логин
	return this->login;			
};
char* access::getPassword() {	//получть пароль
	return this->password;			
};

void access::setLogin(char* newLogin) {			//установить логин
	strcpy_s(this->login, 20, newLogin);
};
void access::setPassword(char* newPassword) {	//установить пароль
	strcpy_s(this->password, 20, newPassword);
};

access access::operator=(const access& other) {			//оператор =
	strcpy_s(this->login, 20, other.login);
	strcpy_s(this->password, 20, other.password);		//копирование полей 

	return *this;
}

bool access::operator==(access& other) {													//сравнивание
	if (!strcmp(this->login, other.login) && !strcmp(this->password, other.password))		//пароль и логин совпадают
		return true;	
	else
		return false;
};

istream& operator>>(istream& in, access& other) {			//ввод
	cout << "¬ведите логин: ";
	in.getline(other.login,20);			//ввод логина
	cout << "¬ведите пароль: ";
	in.getline(other.password, 20);		//ввод парол€
	return in;
};
ifstream& operator>>(ifstream& inf, access& other) {			//чтени€ из файла
	inf >> other.login >> setw(25);			//чтение логина
	inf >> other.password;					//чтение парол€

	return inf;
};

ofstream& operator<<(ofstream& outf, access& other) {			//запись в файл
	outf.setf(ios::left);
	outf << setw(25) << other.login << other.password;			//запись в файл логина и парол€
	outf.unsetf(ios::left);
	return outf;
};
