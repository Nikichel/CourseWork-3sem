#include "interface.h"
#include "actions.cpp"

template <typename T>
void update(queue<T>& q, place* places, int count) {			//���������� ����������
	for (int i = 0; i < count; i++)
		places[i].setTaken(false);			//������������ ���� ����
	if (!q.isEmpty()) {				//���������� ����
		for (queue<T>::template Iterator it = q.Begin(); it != q.End(); it++) {
			places[(*it).getPlace().getNum() - 1].setTaken(true);			//����� �����
		}
	}
}

template <typename T>
void myInterface::menuSector(complect<T>& sector, queue<driver>& drivers) {			//���� �������
	int var;
	bool flag = false;
	stack<queue<T>> vehicleSave;			//������ �������� ��� ������
	stack<queue<driver>> driverSave;		//������ �������� ��� ��������
	algorithm<T> algVeh;					//���������� � ����� ������
	algorithm<driver> algDri;				//���������� � ����� ��������
	do {
		update(sector.getQueue(), sector.getPLaces(), sector.getCount());		//���������� ����
		show_places(sector.getPLaces(), sector.getCount());						//����� ����
		cout <<endl<< "�������� ��������: " << endl << "1. ���������������� �����" << endl << "2. ���������������� �����" << endl
			<< "3. ����������� �����" << endl << "4. ����� ���������� � ��������" << endl << "5. �������� ������ ����������" << endl
			<< "6. �������� ������ ��������" << endl << "7. ����������� ���������"<<endl<<"8. ������������ ���������"<<endl<< "9. �������� ������" << endl
			 <<"10. �������� ��������� ��������" << endl << "11. ������� ������" << endl;
		getNumWithBorders(var, 1, 11);			//����� ��������
		system("CLS");
		cout << endl;
		switch (var)
		{
		case 1:
		{	
			if (sector.getQueue().getSize() != sector.getCount()) {
				vehicleSave.Push(sector.getQueue());
				driverSave.Push(drivers);				//���������� ��������
				regEntry(sector, drivers);		//����������� ������
			}
			else
				cout << "��������� ���� ���!" << endl;
			break;										
		}
		case 2:
		{
			vehicleSave.Push(sector.getQueue());
			driverSave.Push(drivers);			//���������� ��������
			regExit(sector, drivers);			//����������� ������
			break;
		}
		case 3:
		{	
			showPark(sector, drivers);		//����� ���������� � ������
			break;
		}
		case 4:
		{
			find(sector, drivers);			//�����
			break;
		}

		case 5: {
			vehicleSave.Push(sector.getQueue());		//���������� ������ �����
			change(sector, drivers);		//�������� ������
			break;
		}
		case 6:
		{
			driverSave.Push(drivers);			//���������� ������ ���������
			driver changeDriver;
			changeDriver.filter();			//���� ���������� ������
			queue<driver> change = algDri.searchQueue(drivers.Begin(), drivers.End(), changeDriver);
			if(!change.isEmpty())
				for (queue<driver>::Iterator itDriver = change.Begin(); itDriver != change.End(); itDriver++) {
					changeDriver.tableHead();
					cout << (*itDriver) << endl;
					(*itDriver).change();
				}
			break;
		}
		case 7: {
			vehicleSave.Push(sector.getQueue());		//���������� ������ �����
			T tmp;
			cout << "1. �� �����������" << endl << "2. �� ������" << endl;
			getNumWithBorders(var, 1, 2);
			if(var==1)
				algVeh.sortAscendingOrder(sector.getQueue().Begin(), sector.getQueue().End());		//���������� �����
			if(var==2)
				algVeh.sortDescendingOrder(sector.getQueue().Begin(), sector.getQueue().End());		//���������� �����
			cout << endl;
			tmp.tableHead();
			sector.getQueue().show();			//����� ����������
			break;
		}
		case 8: {
			driverSave.Push(drivers);			//���������� ������ ���������
			driver tmp;
			cout << "1. �� �����������" << endl << "2. �� ������" << endl;
			getNumWithBorders(var, 1, 2);
			if (var == 1)
				algDri.sortAscendingOrder(drivers.Begin(), drivers.End());		//���������� ���������
			if (var==2)
				algDri.sortDescendingOrder(drivers.Begin(), drivers.End());
			cout << endl;
			tmp.tableHead();
			drivers.show();			//����� ����������
			break;
		}
		case 9:
		{
			vehicleSave.Push(sector.getQueue());		
			driverSave.Push(drivers);				//���������� ����� ���������
			drivers.clear();
			sector.getQueue().clear();			//������� ��������
			break;
		}
		case 10: {
			vehicleSave.Pop(sector.getQueue());
			driverSave.Pop(drivers);				//������ ���������� ��������
			break;
		}
		case 11: {
			flag = true;			//�����
			break;
		}
		}
	} while (!flag);
}

bool myInterface::menu(complect<car>& sectorA, complect<truck>& sectorB, complect<electrocar>& sectorC, complect<scooter>& sectorD, queue<driver>& drivers) {		//����� �������
    int Type;
    bool fl = true;
    while (fl) {
		cout << endl << "������� : " << endl << "1. ������ � (����������)" << endl << "2. ������ B (���������)" << endl
			<< "3. ������ � (�������������)" << endl << "4. ������ D (���������������)" << endl << "5. ������� ������������" << endl
			<< "6. ����� �� ���������" << endl;
		getNumWithBorders(Type, 1, 6);		//����� ���� ������
		system("CLS");
        cout << endl;
        switch (Type)
        {
        case 1:
        {
			menuSector(sectorA, drivers);		//������ ����
            break;
        }
        case 2:
        {	
			menuSector(sectorB, drivers);		//������ ��������
            break;
        }
        case 3:
        {
			menuSector(sectorC, drivers);		//������ �������������
            break;
        }
        case 4:
        {
			menuSector(sectorD, drivers);		//������ ���������������
            break;
        }
		case 5: 
		{	
			return true;		//������� ������������
		}
		case 6:
		{
			return false;		//����� �� ���������
		}
        }
    }
};

bool myInterface::menuAdmin(queue<employee>& workers) {			//���� ��������������
	int var;
	bool fl = true;
	stack<queue<employee>> employeeSave;			//���������� �������
	algorithm<employee> alg;			//���������� � �����
	while (fl) {
		cout<<endl<< "�������� ��������: " << endl << "1. ����������� �����������" << endl << "2. ������� ����������" << endl
			<< "3. ����� ����������" << endl << "4. �������� ������ ����������" << endl <<"5. ����������� �����������" <<endl 
			<<"6. �������� ��������� �������" << endl << "7. ������� ������������" << endl<<"8. ����� �� ���������"<<endl;
		getNumWithBorders(var, 1, 8);			//����� ��������
		system("CLS");
		cout << endl;
		switch (var)
		{
		case 1:
		{	
			employee tmpWorker;
			tmpWorker.tableHead();			//����� �����������
			workers.show();
			break;
		}
		case 2:
		{
			employeeSave.Push(workers);			//���������� ������
			employee tmpWorker;
			tmpWorker.filter();			//���� ����� 
			workers.del(tmpWorker);		//�������� ����������
			break;
		}
		case 3:
		{	
			employee tmpWorker;
			tmpWorker.filter();			//���� ����� ��� ������
			queue<employee> findWorkers=alg.searchQueue(workers.Begin(),workers.End(), tmpWorker);			//������� ��������� �����������
			tmpWorker.tableHead();
			findWorkers.show();				//����� ��������� �����������
			break;
		}
		case 4:
		{
			employeeSave.Push(workers);			//���������� ������
			employee tmpWorker;
			tmpWorker.filter();			//���� ������� ��� ������
			for (queue<employee>::Iterator it = workers.Begin(); it != workers.End(); it++) {
				if (*it == tmpWorker) {
					cout << (*it)<<endl;
					(*it).change();			//��������� ����
				}
			}
			break;
		}
		case 5: {
			employee tmpWorker;		
			employeeSave.Push(workers);			//���������� ������
			cout << "1. �� �����������" << endl << "2. �� ������" << endl;
			getNumWithBorders(var, 1, 2);
			if (var == 1)
				alg.sortAscendingOrder(workers.Begin(), workers.End());			//����������
			if (var == 2)
				alg.sortDescendingOrder(workers.Begin(), workers.End());		//����������
			tmpWorker.tableHead();
			workers.show();			//����� ����������
			break;
		}
		case 6: {
			employeeSave.Pop(workers);			//������ ���������� ��������
			break;
		}
		case 7:
		{
			return true;			//������� ������������
		}
		case 8:
		{
			return false;			//����� �� ���������
		}
		}
	}
}