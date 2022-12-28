#include "scooter.h"

void scooter::setCharge(bool charge) {			//установить статус зарядки
	this->charge = charge;
};
void scooter::setVolumeCharge(int volumeCharge) {			//установить объем батареи
	this->volumeСharge = volumeCharge;
};

bool scooter::getCharge() {			//получить статус зарядки
	return this->charge;
};
int scooter::getVolumeCharge() {	//получить объем батареи
	return this->volumeСharge;
};

scooter scooter::operator=(const scooter& other) {			//оператор =
	dynamic_cast<vehicle&>(*this) = dynamic_cast<const vehicle&>(other);		//вызов оператор = класса родителя
	this->charge = other.charge;
	this->volumeСharge = other.volumeСharge;			//копирование полей класса

	return *this;
}

bool scooter::operator==(scooter& other) {			//оператор ==
	if (dynamic_cast<vehicle&>(*this) == dynamic_cast<vehicle&>(other)) {		//вызов оператора == класса родителя

		if (other.volumeСharge)
			if (this->volumeСharge != other.volumeСharge)			//сравнение полей класса
				return false;
		return true;
	}
	else
		return false;

}

bool scooter::operator>(scooter& other) {			//опреатор <
	if (dynamic_cast<vehicle&>(*this) > dynamic_cast<vehicle&>(other)) {		//вызов оператора < класса родителя

		if (other.volumeСharge)
			if (this->volumeСharge <= other.volumeСharge)			//сравнение полей
				return false;
		return true;
	}
	else
		return false;

}

void scooter::replace(scooter& other) {			//замещение не нуллевых полей
	dynamic_cast<vehicle&>(*this).replace(dynamic_cast<vehicle&>(other));		//вызов replace класса родителя
	if (this->volumeСharge)
		this->volumeСharge = other.volumeСharge;			//замещение не нуллевых полей класса
};

scooter scooter::ChooseParams() {			//параметр сортировки
	scooter SortParam;
	int var;
	cout << endl << "Сортировка по:" << endl << "1. Марке" << endl << "2. Номеру места" << endl << "3. Времени въезда"
		<< endl << "4. Времени выезда" <<endl<< "5. По зарядке" << endl;
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
	case 5: {
		SortParam.charge = this->charge;				//заполснение поля для сортировки
		break;
	}
	default:
		break;
	}

	return SortParam;
};

void scooter::tableHead() {			//шапка таблицы
	cout.setf(ios::left);
	cout << setw(5) << "id" << setw(8) << "Место"<<setw(18) << "Дата въезда" << setw(19) << "Дата выезда" << setw(9) << "Оплата" << setw(10)
		<< "Марка" << setw(16) << "Объем зарядки" <<setw(10) << "Зарядка" << endl;
	cout << setw(91) << setfill('-') << "" << endl;
	cout.unsetf(ios::left);
	cout << setfill(' ');
}

void scooter::change() {			//изменение полей класса
	int var;
	while (1) {
		cout << "Сменить" << endl << "1. Место" << endl << "2. Марку" << endl 
			<< "3. Время въезда" << endl << "4. Время въезда" <<endl<< "5. Объем батареи" <<endl
			<< "6. Зарядка" <<endl<< "7. Подтвердить изменения" << endl;
		getNumWithBorders(var, 1, 7);			//выбор 
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
			cout << "Введите время въезда" << endl;
			cin >> this->Place.getTimeOfEntry();
			break;
		}
		case 4: {
			cout << "Введите выезда" << endl;
			cin >> this->Place.getTimeOfExit();
			break;
		}
		case 5: {
			cout << "Введите объем батареи" << endl;
			getNum(this->volumeСharge);
			break;
		}
		case 6: {
			cout << "Заряжается ли самокат?(1-да, 0-нет)" << endl;			//изменение поля
			cin >> this->charge;
			break;
		}
		case 7: {
			return;
		}
		}
		this->tableHead();
		cout << *this << endl;			//вывод изменения
	}
}

void scooter::filter() {			//выбор поля для поиска
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
			cout << "Введите время въезда" << endl;
			cin >> this->Place.getTimeOfEntry();
			break;
		}
		case 4: {
			cout << "Введите выезда" << endl;
			cin >> this->Place.getTimeOfExit();			//заполнение поля
			break;
		}
		case 5: {
			return;
		}
		}
		this->tableHead();
		cout << *this << endl;			//вывод промежуточного фильтра
	}
};

istream& operator>>(istream& in, scooter& other) {			//ввод класса
	in >> dynamic_cast<vehicle&>(other);			//ввод полей класса родителя
	rewind(stdin);
	cout << "Объем заряда: ";
	getPositivNum(other.volumeСharge);
	cout << "Зарядка(1-заряжать, 0 -нет): ";
	int charge;	
	getNumWithBorders(charge, 0, 1);			//ввод полей класса
	if (charge == 0)
		other.charge = false;			//не заряжать
	else
		other.charge = true;			//заряжать
	return in;
};

ofstream& operator<<(ofstream& outf, scooter& other) {		//запись в файл
	outf << dynamic_cast<vehicle&>(other);			//запись в файл полей класса родителя
	outf.setf(ios::left);
	outf << setw(16) << other.volumeСharge;
	if (other.charge)
		outf << setw(10) << "+";
	else
		outf << setw(10) << "-";
	outf.unsetf(ios::left);				//запись в файл полей класса
	return outf;
};

ostream& operator<<(ostream& out, scooter& other) {			//вывод
	out << dynamic_cast<vehicle&>(other);			//вывод полей класса родителя
	out.setf(ios::left);
	out << setw(16) << other.volumeСharge;
	if (other.charge)
		out << setw(10) << "+";
	else
		out << setw(10) << "-";						//вывод полей класса
	out.unsetf(ios::left);
	return out;
};

ifstream& operator>>(ifstream& inf, scooter& other) {			//чтение из файла
	inf >> dynamic_cast<vehicle&>(other) >> setw(15);		//чтение из файла класса родителя
	inf >> other.volumeСharge >> setw(16);
	char charge;
	inf >> charge;
	if (charge == '+')
		other.charge = true;
	else
		other.charge = false;			//чтение полей класса
	return inf;
}