#pragma once
#include "fullDate.h"
#include <Windows.h>
#include <conio.h>

class place {		//класс парковочного места
	int id;					//уникальный номер
	int num;				//номер места
	char sector;			//секция
	bool taken;				//статус занят/свободен
	fullDate timeOfEntry;	//дата въезда
	fullDate timeOfExit;	//дата выезда
	int payment;			//оплата

public:

	place() {			//конструктор по умолчанию
		id = 0;
		num = 0;
		sector = 'A';
		taken = false;
		payment = 0;			//инициализация полей
	};

	place(const place& other) {			//констуктор копирвоания
		this->num = other.num;
		this->sector = other.sector;
		this->taken = other.taken;
		this->timeOfEntry = other.timeOfEntry;
		this->timeOfExit = other.timeOfExit;
		this->payment = other.payment;
	};

	~place() {};		//деструктор

	void setTaken(bool taken);		//установить статус
	void setNum(int num);			//установить номер
	void setId(int Id);				//установить id
	void setSector(char sector);	//установить сектор
	void setPayment(int payment);	//установить оплату
	void setTimeOfEntry(const fullDate timeOfEntry);		//установить дату въезда
	void setTimeOfExit(const fullDate timeOfExit);			//установить дату выезда	

	bool getTaken();			//получить статус
	int& getNum();				//получить номер места
	int getId();				//получить id
	char getSector();			//получить сектор
	fullDate& getTimeOfEntry();	//получить дату въезда
	fullDate& getTimeOfExit();	//получить дату выезда
	int getPayment();			//получить оплату

	place operator=(const place& other);		//оператор =
	friend istream& operator>>(istream& in, place& other);		//ввод месст
	friend void show_places(place* other, int count);			//вывод мест
	friend ifstream& operator>>(ifstream& inf, place& other);	//чтение из файла
};