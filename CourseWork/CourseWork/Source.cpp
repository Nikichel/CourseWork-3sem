#include "driver.h"
#include "electrocar.h"
#include "employee.h"
#include "fullDate.h" 
#include "human.h"
#include "place.h"
#include "scooter.h"
#include "truck.h"
#include "interface.h"
#include "FUNS.h"


int main() {
	bool fl=true;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 0);		//��������� ����� ������� � ������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);				//���. �������� �����

	queue<employee> workers;
	queue<car> cars;
	queue<truck> trucks;
	queue<electrocar> electrocars;
	queue<scooter> scooters;
	queue<driver> drivers;				//���������� �������� �������

	int countA = 15;
	int countB = 10;
	int countC = 5;
	int countD = 5;

	place* placeA = new place[countA];
	place* placeB = new place[countB];
	place* placeC = new place[countC];
	place* placeD = new place[countD];			//���������� ���� ��������

	for (int i = 0; i < countA; i++) {
		placeA[i].setSector('A');
		placeA[i].setNum(i + 1);
	}
	for (int i = 0; i < countB; i++) {
		placeB[i].setSector('B');
		placeB[i].setNum(i + 1);
	}
	for (int i = 0; i < countC; i++) {
		placeC[i].setSector('C');
		placeC[i].setNum(i + 1);
	}
	for (int i = 0; i < countD; i++) {
		placeD[i].setSector('D');
		placeD[i].setNum(i + 1);				//������������� ���� ��������
	}

	complect<car> sectorA('A', countA, placeA, cars);
	complect<truck> sectorB('B', countB, placeB, trucks);
	complect<electrocar> sectorC('C', countC, placeC, electrocars);
	complect<scooter> sectorD('D', countD, placeD, scooters);			//���������� �������� 
	
	loadFromFile(workers);
	loadFromFile(drivers);
	loadFromFile(sectorA.getQueue());
	loadFromFile(sectorB.getQueue());
	loadFromFile(sectorC.getQueue());
	loadFromFile(sectorD.getQueue());			//�������� ���������� �� ������
		
	myInterface enter;
	while (fl) {
		employee worker;
		worker.start(workers);		//������������� ���������
		system("CLS");
		worker.greeting();	//����������
		if (!strcmp(worker.getJobTitle(), "�������������") || !strcmp(worker.getJobTitle(), "���������"))
			fl=enter.menuAdmin(workers);
		else
			fl=enter.menu(sectorA, sectorB, sectorC, sectorD, drivers);			//����� ����������
	}
	saveInFile(workers);
	saveInFile(drivers);
	saveInFile(sectorA.getQueue());
	saveInFile(sectorB.getQueue());
	saveInFile(sectorC.getQueue());
	saveInFile(sectorD.getQueue());				//���������� ���������� � �����

	delete[] placeA;
	delete[] placeB;
	delete[] placeC;
	delete[] placeD;			//������� ������
	return 0;					//���������� ������
}