#include "human.h"

int human::count = 0;			//зануление статич. параметра класса

void human::setId(int id) {			//установить id
	this->id = id;
};	
void human::setName(const char* name) {		//установить имя
	strcpy_s(this->name, 10, name);
};
void human::setSurname(const char* surname) {		//установить фамилию
	strcpy_s(this->surname, 15, surname);
};
void human::setMidname(const char* midname) {		//установить отчество
	strcpy_s(this->midname, 15, midname);
};

int human::getId() {		//получить id
	return this->id;
};
char* human::getName() {		//получить имя
	return this->name;
};
char* human::getSurname() {		//получить фамилию
	return this->surname;
};
char* human::getMidname() {		//получить отчество
	return this->midname;
};

void human::replace(const human& other) {			//замещение не нуллевых полей
	if (strlen(this->name))
		strcpy_s(this->name, 10, other.name);
	if (strlen(this->surname))
		strcpy_s(this->surname, 15, other.surname);
	if (strlen(this->midname))
		strcpy_s(this->midname, 15, other.midname);
	if (this->id)
		this->id=other.id;								//замещение полей
}

human human::ChooseParams() {			//выбор параметра сортировки
	human SortParam;
	int var;
	cout << endl << "Сортировка по:" << endl << "1. Имени" << endl << "2. Фамилии" <<endl <<"3. Отчеству" << endl;
	getNumWithBorders(var, 1, 3);			//выбор операции
	cout << endl;
	switch (var)
	{
	case 1: {
		strcpy_s(SortParam.name, 10, this->name);
		break;
	}
	case 2: {
		strcpy_s(SortParam.surname, 15, this->surname);
		break;
	}
	case 3: {
		strcpy_s(SortParam.surname, 15, this->midname);			//заполнение параметра
		break;
	}
	default:
		break;
	}

	return SortParam;
}

bool human::operator==(human& other) {			//оператор ==
	if (strlen(other.name))
		if (strcmp(name, other.name)) return false;
	if (strlen(other.surname))
		if (strcmp(surname, other.surname)) return false;
	if (strlen(other.midname))
		if (strcmp(midname, other.midname)) return false;			//сравнение не нуллевых полей
	if (other.id)
		if (id != other.id)
			return false;
	return true;
}

bool human::operator>(human& other) {			//оператор >
	if (strlen(other.name))
		if (strcmp(name, other.name) <= 0)
			return false;
	if (strlen(other.surname))
		if (strcmp(surname, other.surname) <= 0)
			return false;
	if (strlen(other.midname))		
		if (strcmp(midname, other.midname) <= 0)		//сравние не нуллевых полей
			return false;

	return true;
}

human human::operator=(const human& other) {			//оператор =
	this->id = other.id;
	strcpy_s(this->name, 10, other.name);
	strcpy_s(this->surname, 15, other.surname);
	strcpy_s(this->midname, 15, other.midname);			//копирование полей класса

	return *this;
}

void human::tableHead() {			//вывод шапки таблицы
	cout.setf(ios::left);
	cout << setw(5) << "id" << setw(13) << "Фамилия" << setw(10) << "Имя" <<"Отчество" << endl;
	cout << setw(36) << setfill('-') << "" << endl << setfill(' ');
	cout.unsetf(ios::left);
}

istream& operator>>(istream& in, human& other) {			//ввод
	rewind(stdin);
	other.id = other.count++;			//уникальный id
	cout << "Имя: ";
	getStr("RU", other.name, 10);
	cout << "Фамилия: ";
	getStr("RU", other.surname, 15);
	cout << "Отчество: ";
	getStr("RU", other.midname, 15);			//ввод полей

	return in;
};

ostream& operator<<(ostream& out, human& other) {			//вывод

	out.setf(ios::left);
	out << setw(5) << other.id << setw(13) << other.surname << setw(10) << other.name << setw(13) << other.midname;		//выввод полей
	out.unsetf(ios::left);

	return out;
};

ifstream& operator>>(ifstream& inf, human& other) {			//чтение из файла
	inf >> other.id;
	inf >> other.surname >> setw(10);
	inf >> other.name >> setw(13);
	inf >> other.midname;
	other.count = other.id+1;				//чтение полей из файла
	return inf;
};

//char name[10];
//char surname[15];
//char midname[15];