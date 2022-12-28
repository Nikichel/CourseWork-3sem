#pragma once
#include <iostream>
#include <iomanip>
#include "place.h"
#include "FUNS.h"
using namespace std;

class  vehicle {		//класс средство передвижения
protected:
	int id;				//уникальный номер
	char brand[10];		//марка
	place Place;		//место
public:
	static int count;		//статическая для id
	vehicle() {				//конструктор по умолчанию
		id = 0;
		brand[0] = '\0';	//инициализация
	}

	vehicle(const vehicle& other) {		//конструктор копирования
		this->id = other.id;
		strcpy_s(this->brand, 10, other.brand);
		this->Place = other.Place;			
	}

	~vehicle() {};		//деструктор

	void setId(int id);			//установить id
	void setBrand(const char* brand);		//установить марку
	void setPlace(int num, char sector);	//установить место

	int getId();		//получить id
	place& getPlace();	//получить место
	char* getBrand();	//получить марку

	void operator=(const vehicle& other);		//оператор =
	bool operator ==(vehicle& other);			//оператор ==
	bool operator>(vehicle& other);				//оператор >

	virtual void tableHead();		//шапка таблицы
	void replace(vehicle& other);	//замещение не нулевых полей
	vehicle ChooseParams();			//выбор параметра

	friend ofstream& operator<<(ofstream& outf, vehicle& other);		//запись в файл
	friend istream& operator>>(istream& in, vehicle& other);			//ввод
	friend ostream& operator<<(ostream& out, vehicle& other);			//вывод
	friend ifstream& operator>>(ifstream& in, vehicle& other);			//чтение из файла
};