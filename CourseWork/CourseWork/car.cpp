#include "car.h"

void car::setNumCar(char num[4], char series[2], char region) {			//установить номер машины
	for (int i = 0; i < 4; i++)
		this->numCar[i] = num[i];	
	for (int i = 0; i < 2; i++)
		this->numCar[i+4] = series[i];
	this->numCar[6] = region;
};

char* car::getNumCar() {		//получить номер машины
	return this->numCar;
}

car car::operator=(const car& other) {										//оператор =
	dynamic_cast<vehicle&>(*this) = dynamic_cast<const vehicle&>(other);	//вызов оператор = класса родителя
	strcpy_s(this->numCar, 8, other.numCar);								//копирование полей класса
	return *this;
};

bool car::operator ==(car& other) {				//оператор сравнения
	if (dynamic_cast<vehicle&>(*this) == dynamic_cast<vehicle&>(other)) {			//сравнение полей класса родятеля
		if (strlen(other.numCar))
			if (strcmp(this->numCar, other.numCar))
				return false;							//не нулл. и разные => false
		return true;
	}
	else
		return false;

}

bool car::operator>(car& other) {						//оператор >
	if (dynamic_cast<vehicle&>(*this) > dynamic_cast<vehicle&>(other)) {		//оператор > для класса родителя
		if (strlen(other.numCar))
			if (strcmp(this->numCar, other.numCar)<=0)
				return false;							//не нулл. и не меньше - false
		return true;
	}
	else
		return false;
};

void car::replace(car& other) {							//замещение ненуллевых полей другими значениями
	dynamic_cast<vehicle&>(*this).replace(dynamic_cast<vehicle&>(other));		//вызов метода replace класса родителя
	if (strlen(this->numCar))
		strcpy_s(this->numCar, 8, other.numCar);			//замешение полей класса
};

car car::ChooseParams() {				//выбор параментра сортировки
	car SortParam;
	int var;
	cout << endl << "Сортировка по:" << endl << "1. Марке" << endl << "2. Номеру места" << endl << "3. Времени въезда"
		<< endl << "4. Времени выезда" << endl;
	getNumWithBorders(var, 1, 4);			//выбор операции
	cout << endl;
	switch (var)
	{
	case 1: {
		strcpy_s(SortParam.brand, 10, this->brand);
		break;
	}
	case 2: {
		SortParam.Place.setNum(this->Place.getNum());
		break;
	}
	case 3: {
		SortParam.Place.setTimeOfEntry(this->Place.getTimeOfEntry());
		break;
	}
	case 4: {
		SortParam.Place.setTimeOfExit(this->Place.getTimeOfExit());				//заполнение нужного поля
		break;
	}
	default:
		break;
	}

	return SortParam;
};

void car::tableHead() {				//вывод шапки таблицы
	cout.setf(ios::left);
	cout << setw(5) << "id" << setw(8) << "Место"<< setw(18) << "Дата въезда" << setw(19) << "Дата выезда" << setw(9) << "Оплата" << setw(10) << "Марка"  << "Номер машины" << endl;
	cout << setw(81) << setfill('-') << "" << endl;
	cout.unsetf(ios::left);
	cout << setfill(' ');
}

void car::change() {			//изменить данные
	int var;
	while (1) {
		cout << "Сменить" << endl << "1. Место" << endl << "2. Марку" << endl << "3. Номер машины" << endl
			<< "4. Время въезда" << endl << "5. Время въезда" <<endl <<"6. Выйти" << endl;
		getNumWithBorders(var, 1, 6);			//выбор варианта
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "Введите место:" << endl;
			cin >> this->Place;
			break;
		}
		case 2: {
			cout << "Введите марку" << endl;
			getStr("ENG", this->brand, 10);
			break;
		}
		case 4: {
			cout << "Введите дату въезда" << endl;
			fullDate timeOfEntry;
			cin >> timeOfEntry;
			this->Place.setTimeOfEntry(timeOfEntry);
			break;
		}
		case 5: {
			cout << "Введите дату выезда" << endl;
			fullDate timeOfExit;
			cin >> timeOfExit;
			this->Place.setTimeOfExit(timeOfExit);
			break;
		}
		case 3: {
			cout << "Введите номер машины" << endl;
			cin.getline(this->numCar, 8);
			break;										//ввод параметра
		}
		case 6: {
			return;
		}
		}
		this->tableHead();
		cout << *this << endl;			//вывод изменения
	}
}

void car::filter() {			//выбор параметров для поиска
	int var;
	while (1) {
		cout << "Поиск по:" << endl << "1. Месту" << endl << "2. Марке" << endl << "3. Номеру машины" << endl
			<< "4. Дате въезда" << endl << "5. Дате выезда"  <<endl <<"6. Выйти из фильтра" << endl;				
		getNumWithBorders(var, 1, 6);			//выбор параметра
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "Введите место:" << endl;
			cin >> this->Place;
			break;
		}
		case 2: {
			cout << "Введите марку" << endl;
			getStr("ENG", this->brand, 10);
			break;
		}
		case 4: {
			cout << "Введите дату въезда" << endl;
			fullDate timeOfEntry;
			cin >> timeOfEntry;
			this->Place.setTimeOfEntry(timeOfEntry);
			break;
		}
		case 5: {
			cout << "Введите дату выезда" << endl;
			fullDate timeOfExit;
			cin >> timeOfExit;
			this->Place.setTimeOfExit(timeOfExit);
			break;
		}
		case 3: {
			cout << "Введите номер машины" << endl;
			cin.getline(this->numCar, 8);
			break;										//ввод параметра
		}
		case 6: {
			return ;
		}
		}
		tableHead();
		cout << *this<<endl;			//вывод параметров фильтра
	}
};

istream& operator>>(istream& in, car& other) {			//ввод
	in >> dynamic_cast<vehicle&>(other);	//ввод параметров класса родителя
	rewind(stdin);
	cout << "Введите номер машины: ";
	in.getline(other.numCar, 8);			//ввод параметров класса
	return in;
};

ostream& operator<<(ostream& out, car& other) {			//вывод
	out << dynamic_cast<vehicle&>(other);		//вывод параметров родителя
	out.setf(ios::left);
	out << setw(15) << other.numCar;			//вывод параметров класса
	out.unsetf(ios::left);
	return out;
};

ofstream& operator<<(ofstream& outf, car& other) {			//запись в файл
	outf << dynamic_cast<vehicle&>(other);		//запись параметров класса родителя
	outf.setf(ios::left);
	outf << setw(15) << other.numCar;			//запись параметров класса
	outf.unsetf(ios::left);
	return outf;
};

ifstream& operator>>(ifstream& inf, car& other){			//чтения из файла
	inf >> dynamic_cast<vehicle&>(other)>>setw(15);			//чтение параметров класса родителя
	inf >> other.numCar;									//чтение параметров класса
	return inf;
}