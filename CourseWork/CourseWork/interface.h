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

class myInterface {			//���������
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

	bool menu(complect<car>& sectorA, complect<truck>& sectorB, complect<electrocar>& sectorC, complect<scooter>& sectorD, queue<driver>& drivers);		//���� ���������
	bool menuAdmin(queue<employee>& workers);			//���� ������

	template <typename T>
	friend void update(queue<T>& q, place* places, int count);		//���������� ����
	template <typename T>
	void menuSector(complect<T>& sector, queue<driver>& drivers);		//���� �������
};

template <typename T>
inline void checkPlace(complect<T>& sector, T& obj) {			//�������� ����� ������ ��� ���
	bool fl = true;
	do {
		fl = true;
		try {
			if (sector.getCount() < obj.getPlace().getNum())		//����� ����� ������ ��� ����� ����
				throw MyException(-20, "������ ����� ���");
			for (queue<T>::template Iterator it = sector.getQueue().Begin(); it != sector.getQueue().End(); it++) {
				if ((*it).getPlace().getNum() == obj.getPlace().getNum())		//����� ������
					throw MyException(20, "����� ������");
			}
		}
		catch (MyException errStr) {
			errStr.what();
			fl = false;
			cout << endl << "������� ������" << endl;
			cin >> obj.getPlace();				//���� ������� �����
		}
	} while (!fl);
}