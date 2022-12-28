#pragma once
#include "vehicle.h"

class car : public vehicle {		//класс машины
protected:
	char numCar[8];			//номер машины
public:
	car() : vehicle() {		//конструктор по умолчанию
		*numCar = '\0';		
	};

	car(const car& other) : vehicle(other) {		//копирования
		strcpy_s(this->numCar, 8, other.numCar);
	};

	~car() {};		//деструктор

	void setNumCar(char num[4], char series[2], char region);		//установить номер машины

	char* getNumCar();			//получить номер машины

	car operator=(const car& other);		//оператор =
	bool operator ==(car& other);			//оператор ==
	bool operator>(car& other);				//оператор >

	void tableHead() override;		//шапка таблицы
	void replace(car& other);		//замещение не нулевых полей
	car ChooseParams();				//выпор поля сортировки

	void change();		//меню изменения поля
	void filter();		//фильтр поиска


	friend istream& operator>>(istream& in, car&);				//ввод
	friend ostream& operator<<(ostream& out, car& other);		//вывод
	friend ofstream& operator<<(ofstream& out, car& other);		//запись в файл
	friend ifstream& operator>>(ifstream& inf, car& other);		//чтение из файла
};