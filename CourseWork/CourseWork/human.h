#pragma once
#include <iostream>
#include <iomanip>
#include "FUNS.h"
using namespace std;

class human {		//класс человек
protected:
    int id;				//уникальный номер
	char name[10];		//имя
	char surname[15];	//фамилия
	char midname[15];	//отчество
public:
	static int count;		//статическое поле для id
	human() {
		id = 0;
		*name = '\0';
		*surname = '\0';
		*midname = '\0';		//инициализация полей
	};

	human(const human& other) {			//констуктор копирования		
		this->id = other.id;
		strcpy_s(this->name, 10, other.name);
		strcpy_s(this->surname, 15, other.surname);
		strcpy_s(this->midname, 15, other.midname);			//копирование полей
	};

	~human() {};		//деуструктор

	void setId(int id);			//установить id
	void setName(const char* name);		//установить имя
	void setSurname(const char* surname);		//установить фамилию
	void setMidname(const char* midname);		//установить отчество

	int getId();		//получить id
	char* getName();	//получить имя
	char* getSurname();		//получить фамилию
	char* getMidname();		//получить отчество

	virtual void tableHead();		//шапка таблицы
	void replace(const human& other);		//замещение не нулл. полей
	human ChooseParams();		//выбор параметра сортировки

	bool operator==(human& other);			//оператор ==
	human operator=(const human& other);	//оператор =
	bool operator>(human& other);			//оператор>

	friend istream& operator>>(istream& in, human& other);		//ввод
	friend ostream& operator<<(ostream& out, human& other);		//вывод
	friend ifstream& operator>>(ifstream& inf, human& other);	//чтение из файла
};

//int human::count = 0;