#pragma once
#include "interface.h"

template <typename T>
void myInterface::regEntry(complect<T>& sector, queue<driver>& drivers) {
	show_places(sector.getPLaces(), sector.getCount());		//����� ����
	cout << endl;
	T tmpVehicle;
	driver tmpDriver;
	cout << "������� ������:" << endl;
	cin >> tmpVehicle;
	tmpVehicle.getPlace().setSector(sector.nameSector);				//���� ���������� ����������
	checkPlace(sector, tmpVehicle);
	cin >> tmpDriver;
	tmpVehicle.setId(tmpDriver.getId());			//���� ���������� ��������
	sector.getQueue().put(tmpVehicle);
	drivers.put(tmpDriver);
}

template <typename T>
void myInterface::regExit(complect<T>& sector, queue<driver>& drivers) {
	algorithm<T> algVeh;					//���������� � ����� ������
	T delVehicle;
	delVehicle.filter();
	delVehicle = *(algVeh.searchObj(sector.getQueue().Begin(), sector.getQueue().End(), delVehicle));
	for (queue<driver>::Iterator itDriv = drivers.Begin(); itDriv != drivers.End(); itDriv++) {		//���� �� ���������
		if ((*itDriv).getId() == delVehicle.getId()) {
			(*itDriv).tableHead();
			cout << (*itDriv) << endl << endl;
			drivers.del((*itDriv));				//�������� ��������
			break;
		}
	}
	if (delVehicle.getPlace().getTimeOfExit().isNull()) {			//���� �� �����, �.�. �� ����� ���� ������
		cout << "����� ������" << endl;
		do {
			cin >> delVehicle.getPlace().getTimeOfExit();
			if (delVehicle.getPlace().getTimeOfEntry() < delVehicle.getPlace().getTimeOfExit())			//���� ���� ������
				cout << "����� ������ �� ����� ���� ������ ������" << endl;
		} while (delVehicle.getPlace().getTimeOfEntry() < delVehicle.getPlace().getTimeOfExit());
		delVehicle.getPlace().setPayment(delVehicle.getPlace().getTimeOfEntry() - delVehicle.getPlace().getTimeOfExit());	//������ ������
	}
	delVehicle.tableHead();
	cout << delVehicle << endl;
	sector.getQueue().del(delVehicle);			//��������
}

template <typename T>
void myInterface::showPark(complect<T>& sector, queue<driver>& drivers) {
	T tmpVehicle;
	driver tmpDriver;			//������� �������
	queue<driver> searchDrivers;
	cout << endl;
	if (!sector.getQueue().isEmpty() && !drivers.isEmpty())
		for (queue<driver>::Iterator itDriver = drivers.Begin(); itDriver != drivers.End(); itDriver++) {
			for (queue<T>::template Iterator itVehicle = sector.getQueue().Begin(); itVehicle != sector.getQueue().End(); itVehicle++)
				if ((*itDriver).getId() == (*itVehicle).getId()) {
					searchDrivers.put((*itDriver));			//����� ��������� ������� �������
					break;
				}
		}
	tmpVehicle.tableHead();
	sector.getQueue().show();		//����� �����
	cout << endl;
	tmpDriver.tableHead();
	searchDrivers.show();			//����� ���������
	cout << endl;
}

template <typename T>
void myInterface::find(complect<T>& sector, queue<driver>& drivers) {
	algorithm<T> algVeh;
	T tmpVehicle;
	driver tmpDriver;			//������� �������
	queue<T> searchVehicles;
	queue<driver> searchDrivers;		//������� ��� ������
	tmpVehicle.filter();		//���� ����� ��� ������
	searchVehicles = algVeh.searchQueue(sector.getQueue().Begin(), sector.getQueue().End(), tmpVehicle);
	if (!searchVehicles.isEmpty()) {
		for (queue<T>::template Iterator itVeh = searchVehicles.Begin(); itVeh != searchVehicles.End(); itVeh++) {
			for (queue<driver>::Iterator itDriv = drivers.Begin(); itDriv != drivers.End(); itDriv++) {
				if ((*itDriv).getId() == (*itVeh).getId()) {
					searchDrivers.put((*itDriv));			//����� ���������
					break;
				}
			}
		}
	}
	tmpVehicle.tableHead();
	searchVehicles.show();		//����� �������� �����
	cout << endl;
	tmpDriver.tableHead();		//� �� ���������
	searchDrivers.show();
	cout << endl;
}

template <typename T>
void myInterface::change(complect<T>& sector, queue<driver>& drivers) {
	algorithm<T> algVeh;
	T changeVehicle;
	changeVehicle.filter();			//���� ���������� ������
	queue<T> change = algVeh.searchQueue(sector.getQueue().Begin(), sector.getQueue().End(), changeVehicle);
	if (!change.isEmpty())
		for (queue<T>::template Iterator itVehicle = change.Begin(); itVehicle != change.End(); itVehicle++) {
			changeVehicle.tableHead();
			cout << (*itVehicle) << endl;
			(*itVehicle).change();
		}
}