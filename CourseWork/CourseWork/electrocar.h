#pragma once
#include "car.h"

class electrocar : public car {		//класс электромашины
	bool charge;		//статус зарядки
	int volumeСharge;	//объем батаери

public:

	electrocar() : car() {			//конструктор по умолчанию
		charge = false;
		volumeСharge = 0;
	};

	electrocar(const electrocar& other) : car(other) {		//конструктор с параметрами
		this->charge = other.charge;
		this->volumeСharge = other.volumeСharge;
	};

	~electrocar() {};		//деструктор

	void setCharge(bool charge);				//установить статус
	void setVolumeCharge(int volumeCharge);		//установить объем батареи

	bool getCharge();			//получить статус
	int getVolumeCharge();		//получить объем батареи

	electrocar operator=(const electrocar& other);		//оператор =
	bool operator==(electrocar& other);					//оператор ==
	bool operator>(electrocar& other);					//оператор >

	void tableHead() override;			//шапка таблицы
	void replace(electrocar& other);	//замещение не нулевых полей
	electrocar ChooseParams();			//выбор поля сортировки

	void change();		//меню изменения полей
	void filter();		//фильтр поиска

	friend ofstream& operator<<(ofstream& out, electrocar& other);		//запись в файл
	friend istream& operator>>(istream& in, electrocar& other);			//ввод
	friend ostream& operator<<(ostream& out, electrocar& other);		//вывод
	friend ifstream& operator>>(ifstream& inf, electrocar& other);		//чтение из файла
};