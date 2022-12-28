#pragma once
#include "date.h"

class fullDate : public date {		//класс полноый даты 
	int hour;	//час
	int min;	//минуты
public:
	fullDate() : date() {		//конструктор по умолчанию
		hour = min = 0;		//инициализация
	};

	fullDate(const fullDate& other) : date(other) {		//конструктор копирования
		this->hour = other.hour;		
		this->min = other.min;		//копирование полей
	};

	~fullDate() {};		//деструктор

	void setHour(int hour);		//установить час
	void setMin(int min);		//установить минуту

	int& getHour();		//получить час
	int& getMin();		//получить минуту

	bool isNull();		//пустой ли класс
	bool operator==(fullDate& other); 		//оператор ==
	bool operator<(fullDate& other);		//оператор <
	int operator-(fullDate& other);			//орпеатор -

	fullDate operator=(const fullDate& other);		//оператор=

	friend istream& operator>>(istream& in, fullDate& other);		//ввод
	friend ostream& operator<<(ostream& out, fullDate& other);		//вывод 
	friend ofstream& operator<<(ofstream& out, fullDate& other);	//запись в файл 
	friend ifstream& operator>>(ifstream& inf, fullDate& other);	//чтение из файла
};
