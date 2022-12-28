#include "electrocar.h"

void electrocar::setCharge(bool charge) {			//установить зарядку
	this->charge = charge;
};
void electrocar::setVolumeCharge(int volumeCharge) {		//установить объем батарей
	this->volumeСharge = volumeCharge;
};

bool electrocar::getCharge() {			//получить зарядку
	return this->charge;
};
int electrocar::getVolumeCharge() {		//получить объем батареи
	return this->volumeСharge;
};

electrocar electrocar::operator=(const electrocar& other) {				//оператор =
	dynamic_cast<car&>(*this) = dynamic_cast<const car&>(other);		//вызов оператор = класса родителя
	this->charge = other.charge;
	this->volumeСharge = other.volumeСharge;			//копирование полей класса
	return *this;
}

bool electrocar::operator==(electrocar& other) {				//оператор ==
	if (dynamic_cast<car&>(*this) == dynamic_cast<car&>(other)) {			//сравнение полей класса родителя

		if (other.volumeСharge)
			if (this->volumeСharge != other.volumeСharge)		//сравнение полей класса
				return false;
		return true;
	}
	else
		return false;
}

bool electrocar::operator>(electrocar& other) {				//оператор >
	if (dynamic_cast<car&>(*this) > dynamic_cast<car&>(other)) {		//вызов оператора > класса родителя
		if (other.volumeСharge)
			if (this->volumeСharge <= other.volumeСharge)
				return false;
		if (other.charge)
			if (this->charge <= other.charge)				//сравнение полей класса
				return false;
		return true;
	}
	else
		return false;
}

void electrocar::replace(electrocar& other) {			//замещение не нуллевых полей
	dynamic_cast<car&>(*this).replace(dynamic_cast<car&>(other));			//вызов replace класса родителя
	if (this->volumeСharge)
		this->volumeСharge = other.volumeСharge;
	if (this->charge)
		this->charge = other.charge;			//замещение полей класса
};

electrocar electrocar::ChooseParams() {			//выбор параметра для сортировки
	electrocar SortParam;
	int var;
	cout << endl << "Сортировка по:" << endl << "1. Марке" << endl << "2. Номеру места" << endl << "3. Времени въезда"
		<< endl << "4. Времени выезда" <<endl<<"5. По зарядке" << endl;
	getNumWithBorders(var, 1, 5);			//выбор операции
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
		SortParam.Place.setTimeOfExit(this->Place.getTimeOfExit());
		break;
	}
	case 5 : {
		SortParam.charge = this->charge;						//заполенние нужного параметра
		break;
	}
	default:
		break;
	}

	return SortParam;
};

void electrocar::tableHead() {			//шапка таблицы
	cout.setf(ios::left);
	cout << setw(5) << "id" << setw(8) << "Место" <<setw(18) << "Дата въезда" << setw(19) << "Дата выезда" << setw(9) << "Оплата"
		<< setw(10) << "Марка" << setw(15) << "Номер машины" << setw(16) << "Объем зарядки"<<setw(10) << "Зарядка" << endl;
	cout << setw(106) << setfill('-') << "" << endl;
	cout.unsetf(ios::left);
	cout << setfill(' ');
}

void electrocar::change() {				//изменить данные
	int var;
	bool fl = true;
	while (fl) {
		cout << "Сменить" << endl << "1. Место" << endl << "2. Марку" << endl << "3. Номер машины" << endl
			<< "4. Время въезда" << endl << "5. Время въезда" <<endl<<"6. Объем батареии" <<endl<<"7. Зарядка" <<endl
			<<"8. Подтвердить изменения" << endl;
		getNumWithBorders(var, 1, 8);			//выбор
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "Введите место" << endl;
			getNum(this->Place.getNum());
			break;
		}
		case 2: {
			cout << "Введите марку" << endl;
			getStr("ENG", this->brand, 10);
			break;
		}
		case 3: {
			cout << "Введите номер машины" << endl;
			cin.getline(this->numCar, 8);
			break;
		}
		case 4: {
			cout << "Введите время въезда" << endl;
			cin >> this->Place.getTimeOfEntry();
			break;
		}
		case 5: {
			cout << "Введите время выезда" << endl;
			cin >> this->Place.getTimeOfExit();
			break;
		}
		case 6: {
			cout << "Введите объем батареи" << endl;
			getNum(this->volumeСharge);
			break;
		}
		case 7: {
			cout << "Заряжается ли самокат?(1-да, 0-нет)" << endl;
			cin >> this->charge;				//сменить данные
			break;
		}
		case 8: {
			fl = false;
		}
		}
		this->tableHead();
		cout << *this << endl;			//вывод изменения
	}
}

void electrocar::filter() {				//поиск по параметрам
	int var;
	while (1) {
		cout << "Поиск по:" << endl << "1. Месту" << endl << "2. Марке" << endl << "3. Дате въезда" << endl << "4. Дате выезда"
			<< endl << "5. Выйти из фильтра" << endl;				//выбор параметра
		getNumWithBorders(var, 1, 5);
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "Введите место" << endl;
			getNum(this->Place.getNum());
			break;
		}
		case 2: {
			cout << "Введите марку" << endl;
			getStr("ENG", this->brand, 10);
			break;
		}
		case 3: {
			cout << "Введите номер машины" << endl;
			cin.getline(this->numCar, 8);
			break;
		}
		case 4: {
			cout << "Введите время въезда" << endl;
			cin >> this->Place.getTimeOfEntry();				//ввод параметра фильтра
			break;
		}
		case 5: {
			return;
		}
		}
		this->tableHead();
		cout << *this << endl;			//вывод провежуточного фильтра
	}
};

istream& operator>>(istream& in, electrocar& other) {				//ввод из консоли
	in >> dynamic_cast<car&>(other);			//ввод полей класса родителя
	rewind(stdin);
	cout << "Объем заряда: ";
	getNum(other.volumeСharge);
	cout << "Зарядка(1-заряжать, 0 -нет): ";			//ввод полей класса
	int charge;
	getNumWithBorders(charge, 0, 1);
	if (charge == 0)
		other.charge = false;			//не заряжать
	else
		other.charge = true;			//заряжать

	return in;
};

ostream& operator<<(ostream& out, electrocar& other) {				//вывод на экран
	out << dynamic_cast<car&>(other);				//вывод полей класса родителя
	out.setf(ios::left);
	out << setw(16)<<other.volumeСharge;
	if (other.charge)
		out << setw(10) << "+";
	else
		out << setw(10) << "-";				//вывод полей класса
	out.unsetf(ios::left);
	return out;
};

ofstream& operator<<(ofstream& outf, electrocar& other) {				//запись в файл
	outf << dynamic_cast<car&>(other);					//запись полей класса родителя
	outf.setf(ios::left);
	outf << setw(16) << other.volumeСharge;
	if (other.charge)
		outf << setw(10) << "+";
	else
		outf << setw(10) << "-";						//запись полей класса
	outf.unsetf(ios::left);
	return outf;
};

ifstream& operator>>(ifstream& inf, electrocar& other) {		//чтение из файла
	inf >> dynamic_cast<car&>(other);					//чтение полей класса родителя
	inf >> other.volumeСharge>>setw(16);
	char charge;
	inf >> charge;
	if (charge == '+')
		other.charge = true;
	else
		other.charge = false;				//чтение полей класса
	return inf;
}