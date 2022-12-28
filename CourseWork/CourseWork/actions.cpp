#pragma once
#include "interface.h"

template <typename T>
void myInterface::regEntry(complect<T>& sector, queue<driver>& drivers) {
	show_places(sector.getPLaces(), sector.getCount());		//вывод мест
	cout << endl;
	T tmpVehicle;
	driver tmpDriver;
	cout << "Введите данные:" << endl;
	cin >> tmpVehicle;
	tmpVehicle.getPlace().setSector(sector.nameSector);				//ввод информации транспорта
	checkPlace(sector, tmpVehicle);
	cin >> tmpDriver;
	tmpVehicle.setId(tmpDriver.getId());			//ввод информации водителя
	sector.getQueue().put(tmpVehicle);
	drivers.put(tmpDriver);
}

template <typename T>
void myInterface::regExit(complect<T>& sector, queue<driver>& drivers) {
	algorithm<T> algVeh;					//сортировка и поиск машины
	T delVehicle;
	delVehicle.filter();
	delVehicle = *(algVeh.searchObj(sector.getQueue().Begin(), sector.getQueue().End(), delVehicle));
	for (queue<driver>::Iterator itDriv = drivers.Begin(); itDriv != drivers.End(); itDriv++) {		//цикл по водителям
		if ((*itDriv).getId() == delVehicle.getId()) {
			(*itDriv).tableHead();
			cout << (*itDriv) << endl << endl;
			drivers.del((*itDriv));				//удаление водителя
			break;
		}
	}
	if (delVehicle.getPlace().getTimeOfExit().isNull()) {			//если не бронь, т.е. не ввели даты выезда
		cout << "Время выезда" << endl;
		do {
			cin >> delVehicle.getPlace().getTimeOfExit();
			if (delVehicle.getPlace().getTimeOfEntry() < delVehicle.getPlace().getTimeOfExit())			//ввод даты выезда
				cout << "Время выезда не может быть раньше въезда" << endl;
		} while (delVehicle.getPlace().getTimeOfEntry() < delVehicle.getPlace().getTimeOfExit());
		delVehicle.getPlace().setPayment(delVehicle.getPlace().getTimeOfEntry() - delVehicle.getPlace().getTimeOfExit());	//расчет оплаты
	}
	delVehicle.tableHead();
	cout << delVehicle << endl;
	sector.getQueue().del(delVehicle);			//удаление
}

template <typename T>
void myInterface::showPark(complect<T>& sector, queue<driver>& drivers) {
	T tmpVehicle;
	driver tmpDriver;			//обеъкты классов
	queue<driver> searchDrivers;
	cout << endl;
	if (!sector.getQueue().isEmpty() && !drivers.isEmpty())
		for (queue<driver>::Iterator itDriver = drivers.Begin(); itDriver != drivers.End(); itDriver++) {
			for (queue<T>::template Iterator itVehicle = sector.getQueue().Begin(); itVehicle != sector.getQueue().End(); itVehicle++)
				if ((*itDriver).getId() == (*itVehicle).getId()) {
					searchDrivers.put((*itDriver));			//поиск водителей данного сектора
					break;
				}
		}
	tmpVehicle.tableHead();
	sector.getQueue().show();		//вывод машин
	cout << endl;
	tmpDriver.tableHead();
	searchDrivers.show();			//вывод выдителей
	cout << endl;
}

template <typename T>
void myInterface::find(complect<T>& sector, queue<driver>& drivers) {
	algorithm<T> algVeh;
	T tmpVehicle;
	driver tmpDriver;			//объекты классов
	queue<T> searchVehicles;
	queue<driver> searchDrivers;		//очереди для поиска
	tmpVehicle.filter();		//ввод полей для поиска
	searchVehicles = algVeh.searchQueue(sector.getQueue().Begin(), sector.getQueue().End(), tmpVehicle);
	if (!searchVehicles.isEmpty()) {
		for (queue<T>::template Iterator itVeh = searchVehicles.Begin(); itVeh != searchVehicles.End(); itVeh++) {
			for (queue<driver>::Iterator itDriv = drivers.Begin(); itDriv != drivers.End(); itDriv++) {
				if ((*itDriv).getId() == (*itVeh).getId()) {
					searchDrivers.put((*itDriv));			//поиск водителей
					break;
				}
			}
		}
	}
	tmpVehicle.tableHead();
	searchVehicles.show();		//вывод найденых машин
	cout << endl;
	tmpDriver.tableHead();		//и их водителей
	searchDrivers.show();
	cout << endl;
}

template <typename T>
void myInterface::change(complect<T>& sector, queue<driver>& drivers) {
	algorithm<T> algVeh;
	T changeVehicle;
	changeVehicle.filter();			//ввод параметров поиска
	queue<T> change = algVeh.searchQueue(sector.getQueue().Begin(), sector.getQueue().End(), changeVehicle);
	if (!change.isEmpty())
		for (queue<T>::template Iterator itVehicle = change.Begin(); itVehicle != change.End(); itVehicle++) {
			changeVehicle.tableHead();
			cout << (*itVehicle) << endl;
			(*itVehicle).change();
		}
}