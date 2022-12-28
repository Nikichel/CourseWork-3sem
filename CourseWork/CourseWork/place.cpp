#include "place.h"

void place::setTaken(bool taken) {			//установить статус места
	this->taken = taken;
};
void place::setNum(int num) {			//установить место
	this->num = num;
};
void place::setId(int Id) {				//установить id
	this->id = id;
};
void place::setSector(char sector) {		//установить сектор
	this->sector = sector;
};
void place::setPayment(int payment) {		//установить оплату
	this->payment = payment;
};
void place::setTimeOfEntry(const fullDate timeOfEntry) {		//установить врем€ въезда
	this->timeOfEntry = timeOfEntry;
};
void place::setTimeOfExit(const fullDate timeOfExit) {			//установить врем€ выезда
	this->timeOfExit = timeOfExit;
};

bool place::getTaken() {		//получить статус
	return this->taken;
};
int& place::getNum() {			//получить номер
	return this->num;
};
int place::getId() {			//получить id
	return this->id;
};
char place::getSector() {		//получить сектор
	return this->sector;
};
int place::getPayment() {		//получить оплату
	return this->payment;
};
fullDate& place::getTimeOfEntry() {			//получить врем€ въезда
	return timeOfEntry;
};
fullDate& place::getTimeOfExit() {			//получить врем€ выезда
	return timeOfExit;
};

place place::operator=(const place& other) {		//оператор = 
	this->num = other.num;
	this->sector = other.sector;
	this->taken = other.taken;
	this->timeOfEntry = other.timeOfEntry;
	this->timeOfExit = other.timeOfExit;
	this->payment = other.payment;			//копирование полей класса

	return *this;
}

istream& operator>>(istream& in, place& other) {			//ввод
	cout << "¬ведите сектор: ";
	in >> other.sector;
	cout << "¬ведите номер: ";
	getPositivNum(other.num);			//ввод полей класса

	return in;
}

void show_places(place* other, int count) {			//вывод мест секции
	int bg = 15;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 2);

	for (int j = 0; j < count; j++) {
		if (other[j].taken)
			SetConsoleTextAttribute(hConsole, (bg << 4) + 4);			//зан€то - красный цвет
		else
			SetConsoleTextAttribute(hConsole, (bg << 4) + 2);			//свободно - заленый
		for (int i = 0; i < 7; i++)
			cout << "_";					//рамка 
		cout << "   ";
	}

	cout << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < count; j++) {
			if (other[j].taken)
				SetConsoleTextAttribute(hConsole, (bg << 4) + 4);		//зан€то - красный цвет
			else
				SetConsoleTextAttribute(hConsole, (bg << 4) + 2);		//свободно - заленый
			if (i == 1)
				cout << "|" << setw(2) << other[j].sector << setw(2) << other[j].num << setw(2) << "|";		//рамка и номер места
			else
				cout << "|" << setw(6) << "|";		//рамка
			cout << "   ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, (bg << 4) + 0);
}

ifstream& operator>>(ifstream& inf, place& other) {			//чтение из файла
	inf >> other.num;
	inf >> other.sector;
	inf >> other.timeOfEntry;
	inf >> other.timeOfExit;
	inf>> other.payment;				//чтение полей из файла
	return inf;
}