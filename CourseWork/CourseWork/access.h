#pragma once
#include <iostream>
#include <iomanip>
#include "MyFile.cpp"

using namespace std;
class access			//класс доступа
{
	char login[20];		//логин
	char password[20];		//пароль
public:
	access() {				//конструктор по умолчанию
		login[0] = '\0';
		password[0] = '\0';			//иницилизация
	}

	access(const access& other) {			//копирования
		strcpy_s(this->login, 20, other.login);
		strcpy_s(this->password, 20, other.password);		//копирование полей
	}

	~access(){};		//деструктор

	char* getLogin();		//получить логин
	char* getPassword();	//получить пароль

	void setLogin(char* newLogin);			//установить логин
	void setPassword(char* newPassword);	//установить пароль

	access operator=(const access& other);	//оператор =
	bool operator==(access& other);			//оператор ==

	friend istream& operator>>(istream& in, access& other);			//ввод
	friend ofstream& operator<<(ofstream& outf, access& other);		//запись в файл
	friend ifstream& operator>>(ifstream& inf, access& other);		//чтение из файла
};

