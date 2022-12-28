#pragma once
#include "car.h"

class truck : public car {		//класс грузовик
	int height;			//высота 
	int length;			//длина 

public:

	truck() : car() {			//конструктор по умолчанию
		height = length = 0;
	};

	truck(const truck& other) : car(other) {		//конструктор копирования
		this->height = other.height;
		this->length = other.length;
	};
		
	~truck() {};		//деструктор 

	void setHeight(int height);		//установить высоту
	void setLength(int length);		//установить длину

	int getHeight();		//получить высоту
	int getLength();		//получить длину
	
	truck operator=(const truck& other);		//оператор =
	bool operator==(truck& other);				//оператор ==
	bool operator>(truck& other);				//оператор >

	void tableHead() override;		//шапка таблицы
	void replace(truck& other);		//замещение не нулeвых полей
	truck ChooseParams();			//выбор поля для сортировки

	void change();		//меню изменения поля
	void filter();		//фильтр поиска

	friend ofstream& operator<<(ofstream& out, truck& other);		//запись в файл
	friend istream& operator>>(istream& in, truck& other);			//ввод
	friend ostream& operator<<(ostream& out, truck& other);			//вывод
	friend ifstream& operator>>(ifstream& inf, truck& other);		//чтение из файла
};
