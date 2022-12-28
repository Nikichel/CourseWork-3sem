#include "interface.h"
#include "actions.cpp"

template <typename T>
void update(queue<T>& q, place* places, int count) {			//обновление информации
	for (int i = 0; i < count; i++)
		places[i].setTaken(false);			//освобождение всех мест
	if (!q.isEmpty()) {				//обновление мест
		for (queue<T>::template Iterator it = q.Begin(); it != q.End(); it++) {
			places[(*it).getPlace().getNum() - 1].setTaken(true);			//место взято
		}
	}
}

template <typename T>
void myInterface::menuSector(complect<T>& sector, queue<driver>& drivers) {			//меню сектора
	int var;
	bool flag = false;
	stack<queue<T>> vehicleSave;			//отмена действия для машины
	stack<queue<driver>> driverSave;		//отмена дейтсвия для водителя
	algorithm<T> algVeh;					//сортировка и поиск машины
	algorithm<driver> algDri;				//сортировка и поиск водителя
	do {
		update(sector.getQueue(), sector.getPLaces(), sector.getCount());		//обновление мест
		show_places(sector.getPLaces(), sector.getCount());						//вывод мест
		cout <<endl<< "Выберите операцию: " << endl << "1. Зарегистрировать въезд" << endl << "2. Зарегистрировать выезд" << endl
			<< "3. Просмотреть места" << endl << "4. Поиск трнаспорта и водителя" << endl << "5. Изменить данные транспорта" << endl
			<< "6. Изменить данные водителя" << endl << "7. Сортировать транспорт"<<endl<<"8. Сортировкать водителей"<<endl<< "9. Очистить данные" << endl
			 <<"10. Отменить последнее действие" << endl << "11. Сменить сектор" << endl;
		getNumWithBorders(var, 1, 11);			//выбор операции
		system("CLS");
		cout << endl;
		switch (var)
		{
		case 1:
		{	
			if (sector.getQueue().getSize() != sector.getCount()) {
				vehicleSave.Push(sector.getQueue());
				driverSave.Push(drivers);				//сохранение очередей
				regEntry(sector, drivers);		//регистрация въезда
			}
			else
				cout << "Свободных мест нет!" << endl;
			break;										
		}
		case 2:
		{
			vehicleSave.Push(sector.getQueue());
			driverSave.Push(drivers);			//сохранение очередей
			regExit(sector, drivers);			//регистрация выезда
			break;
		}
		case 3:
		{	
			showPark(sector, drivers);		//вывод информации о местах
			break;
		}
		case 4:
		{
			find(sector, drivers);			//поиск
			break;
		}

		case 5: {
			vehicleSave.Push(sector.getQueue());		//сохранение данных машин
			change(sector, drivers);		//изменить данные
			break;
		}
		case 6:
		{
			driverSave.Push(drivers);			//сохранение данных водителей
			driver changeDriver;
			changeDriver.filter();			//ввод параметров поиска
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
			vehicleSave.Push(sector.getQueue());		//сохранение данных машин
			T tmp;
			cout << "1. По возрастанию" << endl << "2. По убываю" << endl;
			getNumWithBorders(var, 1, 2);
			if(var==1)
				algVeh.sortAscendingOrder(sector.getQueue().Begin(), sector.getQueue().End());		//сортировка машин
			if(var==2)
				algVeh.sortDescendingOrder(sector.getQueue().Begin(), sector.getQueue().End());		//сортировка машин
			cout << endl;
			tmp.tableHead();
			sector.getQueue().show();			//вывод сортировки
			break;
		}
		case 8: {
			driverSave.Push(drivers);			//сохранение данных водителей
			driver tmp;
			cout << "1. По возрастанию" << endl << "2. По убываю" << endl;
			getNumWithBorders(var, 1, 2);
			if (var == 1)
				algDri.sortAscendingOrder(drivers.Begin(), drivers.End());		//сортировка водителей
			if (var==2)
				algDri.sortDescendingOrder(drivers.Begin(), drivers.End());
			cout << endl;
			tmp.tableHead();
			drivers.show();			//вывод сортировки
			break;
		}
		case 9:
		{
			vehicleSave.Push(sector.getQueue());		
			driverSave.Push(drivers);				//сохранение перед удалением
			drivers.clear();
			sector.getQueue().clear();			//очистка очередей
			break;
		}
		case 10: {
			vehicleSave.Pop(sector.getQueue());
			driverSave.Pop(drivers);				//отмена последнего действия
			break;
		}
		case 11: {
			flag = true;			//выход
			break;
		}
		}
	} while (!flag);
}

bool myInterface::menu(complect<car>& sectorA, complect<truck>& sectorB, complect<electrocar>& sectorC, complect<scooter>& sectorD, queue<driver>& drivers) {		//выбор сектора
    int Type;
    bool fl = true;
    while (fl) {
		cout << endl << "Введите : " << endl << "1. Сектор А (автомобили)" << endl << "2. Сектор B (грузовики)" << endl
			<< "3. Сектор С (электромашины)" << endl << "4. Сектор D (электросамокаты)" << endl << "5. Сменить пользователя" << endl
			<< "6. Выйти их программы" << endl;
		getNumWithBorders(Type, 1, 6);		//выбор типа класса
		system("CLS");
        cout << endl;
        switch (Type)
        {
        case 1:
        {
			menuSector(sectorA, drivers);		//сектор авто
            break;
        }
        case 2:
        {	
			menuSector(sectorB, drivers);		//сектор грузовик
            break;
        }
        case 3:
        {
			menuSector(sectorC, drivers);		//сектор электромашины
            break;
        }
        case 4:
        {
			menuSector(sectorD, drivers);		//сектро электросамокаты
            break;
        }
		case 5: 
		{	
			return true;		//сменить пользователя
		}
		case 6:
		{
			return false;		//выход из программы
		}
        }
    }
};

bool myInterface::menuAdmin(queue<employee>& workers) {			//меню администратора
	int var;
	bool fl = true;
	stack<queue<employee>> employeeSave;			//сохранение очереди
	algorithm<employee> alg;			//сортировка и поиск
	while (fl) {
		cout<<endl<< "Выберите операцию: " << endl << "1. Просмотреть сотрудников" << endl << "2. Удалить сотрудника" << endl
			<< "3. Поиск сотрудника" << endl << "4. Изменить данные сотрудника" << endl <<"5. Сортировать сотрудников" <<endl 
			<<"6. Отменить последнее дейтвие" << endl << "7. Сменить пользователя" << endl<<"8. Выйти из программы"<<endl;
		getNumWithBorders(var, 1, 8);			//выбор операции
		system("CLS");
		cout << endl;
		switch (var)
		{
		case 1:
		{	
			employee tmpWorker;
			tmpWorker.tableHead();			//вывод сотрудников
			workers.show();
			break;
		}
		case 2:
		{
			employeeSave.Push(workers);			//сохранение данных
			employee tmpWorker;
			tmpWorker.filter();			//ввод полей 
			workers.del(tmpWorker);		//удаление сотрудника
			break;
		}
		case 3:
		{	
			employee tmpWorker;
			tmpWorker.filter();			//ввод полей для поиска
			queue<employee> findWorkers=alg.searchQueue(workers.Begin(),workers.End(), tmpWorker);			//очередь найденных сотрудников
			tmpWorker.tableHead();
			findWorkers.show();				//вывод найденных сотрудников
			break;
		}
		case 4:
		{
			employeeSave.Push(workers);			//сохранение данных
			employee tmpWorker;
			tmpWorker.filter();			//ввод фильтра для поиска
			for (queue<employee>::Iterator it = workers.Begin(); it != workers.End(); it++) {
				if (*it == tmpWorker) {
					cout << (*it)<<endl;
					(*it).change();			//изменение поля
				}
			}
			break;
		}
		case 5: {
			employee tmpWorker;		
			employeeSave.Push(workers);			//сохранение данных
			cout << "1. По возрастанию" << endl << "2. По убываю" << endl;
			getNumWithBorders(var, 1, 2);
			if (var == 1)
				alg.sortAscendingOrder(workers.Begin(), workers.End());			//сортировка
			if (var == 2)
				alg.sortDescendingOrder(workers.Begin(), workers.End());		//сортировка
			tmpWorker.tableHead();
			workers.show();			//вывод сортировки
			break;
		}
		case 6: {
			employeeSave.Pop(workers);			//отмена последнего действия
			break;
		}
		case 7:
		{
			return true;			//сменить пользователя
		}
		case 8:
		{
			return false;			//выход из программы
		}
		}
	}
}