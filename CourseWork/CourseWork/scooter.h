#pragma once
#include "vehicle.h"

class scooter : public vehicle {		//класс электросамокат
	bool charge;			//статус зарядки
	int volumeСharge;		//объем зарядки

public:

	scooter() : vehicle() {			//конструктор по умолчанию
		charge = false;
		volumeСharge = 0;
	};

	scooter(const scooter& other) : vehicle(other) {			//конструктор копирования
		this->charge = other.charge;
		this->volumeСharge = other.volumeСharge;
	};

	~scooter() {};		//деструктор

	void setCharge(bool charge);				//установить статус
	void setVolumeCharge(int volumeCharge);		//установить объем батареи

	bool getCharge();		//получить статус
	int getVolumeCharge();	//получить объем батареи

	scooter operator=(const scooter& other);	//оператор =
	bool operator==(scooter& other);			//оператор ==
	bool operator>(scooter& other);				//оператор >

	void tableHead() override;			//шапка таблицы
	void replace(scooter& other);		//замещение не нулевых полей
	scooter ChooseParams();				//выбор поля сортировки

	void change();		//меню изменения полей
	void filter();		//фильтр поиска

	friend ofstream& operator<<(ofstream& out, scooter& other);		//запись в файл
	friend istream& operator>>(istream& in, scooter& other);		//ввод
	friend ostream& operator<<(ostream& out, scooter& other);		//вывод
	friend ifstream& operator>>(ifstream& inf, scooter& other);		//чтение из файла
};