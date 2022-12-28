#include "place.h"

void place::setTaken(bool taken) {			//���������� ������ �����
	this->taken = taken;
};
void place::setNum(int num) {			//���������� �����
	this->num = num;
};
void place::setId(int Id) {				//���������� id
	this->id = id;
};
void place::setSector(char sector) {		//���������� ������
	this->sector = sector;
};
void place::setPayment(int payment) {		//���������� ������
	this->payment = payment;
};
void place::setTimeOfEntry(const fullDate timeOfEntry) {		//���������� ����� ������
	this->timeOfEntry = timeOfEntry;
};
void place::setTimeOfExit(const fullDate timeOfExit) {			//���������� ����� ������
	this->timeOfExit = timeOfExit;
};

bool place::getTaken() {		//�������� ������
	return this->taken;
};
int& place::getNum() {			//�������� �����
	return this->num;
};
int place::getId() {			//�������� id
	return this->id;
};
char place::getSector() {		//�������� ������
	return this->sector;
};
int place::getPayment() {		//�������� ������
	return this->payment;
};
fullDate& place::getTimeOfEntry() {			//�������� ����� ������
	return timeOfEntry;
};
fullDate& place::getTimeOfExit() {			//�������� ����� ������
	return timeOfExit;
};

place place::operator=(const place& other) {		//�������� = 
	this->num = other.num;
	this->sector = other.sector;
	this->taken = other.taken;
	this->timeOfEntry = other.timeOfEntry;
	this->timeOfExit = other.timeOfExit;
	this->payment = other.payment;			//����������� ����� ������

	return *this;
}

istream& operator>>(istream& in, place& other) {			//����
	cout << "������� ������: ";
	in >> other.sector;
	cout << "������� �����: ";
	getPositivNum(other.num);			//���� ����� ������

	return in;
}

void show_places(place* other, int count) {			//����� ���� ������
	int bg = 15;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 2);

	for (int j = 0; j < count; j++) {
		if (other[j].taken)
			SetConsoleTextAttribute(hConsole, (bg << 4) + 4);			//������ - ������� ����
		else
			SetConsoleTextAttribute(hConsole, (bg << 4) + 2);			//�������� - �������
		for (int i = 0; i < 7; i++)
			cout << "_";					//����� 
		cout << "   ";
	}

	cout << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < count; j++) {
			if (other[j].taken)
				SetConsoleTextAttribute(hConsole, (bg << 4) + 4);		//������ - ������� ����
			else
				SetConsoleTextAttribute(hConsole, (bg << 4) + 2);		//�������� - �������
			if (i == 1)
				cout << "|" << setw(2) << other[j].sector << setw(2) << other[j].num << setw(2) << "|";		//����� � ����� �����
			else
				cout << "|" << setw(6) << "|";		//�����
			cout << "   ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, (bg << 4) + 0);
}

ifstream& operator>>(ifstream& inf, place& other) {			//������ �� �����
	inf >> other.num;
	inf >> other.sector;
	inf >> other.timeOfEntry;
	inf >> other.timeOfExit;
	inf>> other.payment;				//������ ����� �� �����
	return inf;
}