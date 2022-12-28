#pragma once
#include "human.h"
#include "place.h"

class driver : public human {		//класс водитель
	int numPassport;		//номер паспорта
	int driverLicense;		//номер лицензи
public:
	driver() : human() {		//конструктор по умолчанию
		numPassport = 0;
		driverLicense = 0;		//инициализация полей
	};

	driver(const driver& other) : human(other) {		//конструктор копирования
		this->driverLicense = other.driverLicense;
		this->numPassport = other.numPassport;
	};

	~driver() {};		//деструктор

	void setNumPassport(int numPassport);		//установить номер паспорта
	void setDriverLicense(int driverLicense);	//установить номер прав

	int getNumPassport();		//получить номер паспорта
	int getDriverLicense();		//получить номер прав

	void tableHead() override;			//шапка таблицы
	void change();						//меню изменения полей					
	void replace(const driver& other);	//замещение не нулевых полей
	driver ChooseParams();				//выбор поля сортировки
	void filter();						//фильтр поиска

	driver operator = (const driver& other);	//оператор =
	bool operator==(driver& other);				//оператор ==
	bool operator>(driver& other);				//оператор >

	friend istream& operator>>(istream& in, driver& other);		//ввод
	friend ostream& operator<<(ostream& out, driver& other);	//вывод
	friend ifstream& operator>>(ifstream& inf, driver& other);	//чтение из файла
	friend ofstream& operator<<(ofstream& out, driver& other);	//запись в файл
};