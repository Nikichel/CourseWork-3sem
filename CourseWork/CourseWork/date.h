#pragma once
#include <iostream>
#include <iomanip>
#include "FUNS.h"
using namespace std;

class date {		//класс даты
protected:
	int dd, mm, yyyy;	//день, месяц, год

public:
	date() {		//конструктор по умолчанию
		dd = mm = yyyy = 0;		//инициализация
	};

	date(int day, int month, int year) {	//конструктро с параметрами
		dd = day;
		mm = month;
		yyyy = year;			//инициализация введеными числами
	};

	date(const date& other) {		//конструктор копирования
		this->dd = other.dd;
		this->mm = other.mm;
		this->yyyy = other.yyyy;		//копирование
	};

	~date() {};		//деструктор

	date operator= (const date& other);		//оператор =
	date operator= (const int ms[3]);		//оператор =
	bool operator==(date& other);		//оператор ==
	bool operator<(date& other);		//операто <
	int operator-(date& other);		//оператор -

	bool isNull();			//пустой ли класс
	bool leap(int year);		//високосный ли год

	void setDay(int dd);		//установить день
	void setMonth(int mm);		//установить месяц
	void setYear(int yyyy);		//установить год

	int& getDay();			//получить день
	int& getMonth();		//получить месяц
	int getYear();			//получить год

	friend ostream& operator<<(ostream&, date&);		//вывод
	friend istream& operator>>(istream&, date&);		//ввод
	friend ofstream& operator<<(ofstream&, date&);		//запись в файл
	friend ifstream& operator>>(ifstream& inf, date& other);		//чтение из файла

};
