#pragma once
#include "Queue.cpp"
#include "truck.h"
#include "electrocar.h"
#include "scooter.h"
#include "driver.h"
#include "FUNS.h"
#include "stack.h"
#include "employee.h"
#include "complect.h"

#include "algorithm.h"

using namespace std;

class myInterface {			//интерфейс
	template <typename T>
	void regEntry(complect<T>& sector, queue<driver>& drivers);
	template <typename T>
	void regExit(complect<T>& sector, queue<driver>& drivers);
	template <typename T>
	void showPark(complect<T>& sector, queue<driver>& drivers);
	template <typename T>
	void find(complect<T>& sector, queue<driver>& drivers);
	template <typename T>
	void change(complect<T>& sector, queue<driver>& drivers);

public:
	myInterface() {};
	
	~myInterface() {};

	bool menu(complect<car>& sectorA, complect<truck>& sectorB, complect<electrocar>& sectorC, complect<scooter>& sectorD, queue<driver>& drivers);		//меню работника
	bool menuAdmin(queue<employee>& workers);			//меню админа

	template <typename T>
	friend void update(queue<T>& q, place* places, int count);		//обномление мест
	template <typename T>
	void menuSector(complect<T>& sector, queue<driver>& drivers);		//меню сектора
};

template <typename T>
inline void checkPlace(complect<T>& sector, T& obj) {			//проверка место занято или нет
	bool fl = true;
	do {
		fl = true;
		try {
			if (sector.getCount() < obj.getPlace().getNum())		//номер места больше чем самих мест
				throw MyException(-20, "Такого места нет");
			for (queue<T>::template Iterator it = sector.getQueue().Begin(); it != sector.getQueue().End(); it++) {
				if ((*it).getPlace().getNum() == obj.getPlace().getNum())		//место занято
					throw MyException(20, "Место занято");
			}
		}
		catch (MyException errStr) {
			errStr.what();
			fl = false;
			cout << endl << "Введите другое" << endl;
			cin >> obj.getPlace();				//ввод другого места
		}
	} while (!fl);
}