#include "driver.h"

void driver::setNumPassport(int numPassport) {				//установить номер паспорта
	this->numPassport = numPassport;
};
void driver::setDriverLicense(int driverLicense) {			//становить номер водительских прав
	this->driverLicense = driverLicense;
};

int driver::getNumPassport() {			//получить номер паспорта
	return this->numPassport;
};
int driver::getDriverLicense() {		//получить номер лицензии
	return this->driverLicense;
};

void driver::change() {			//изменить данные
	int var;
	bool fl = true;
	while (fl) {
		cout << "Сменить" << endl << "1. Имя" << endl << "2. Фамилию" << endl << "3. Отчество" << endl
			<< "4. Номер паспорта" << endl << "5. Номер прав" << endl << "6. Подтвердить изменения" << endl;
		getNumWithBorders(var, 1, 6);				//выбор параметра
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "Введите имя" << endl;
			getStr("RU", this->name, 10);
			break;
		}
		case 2: {
			cout << "Введите фамилию" << endl;
			getStr("RU", this->surname, 15);
			break;
		}
		case 3: {
			cout << "Введите отчество" << endl;
			getStr("RU", this->midname, 15);
			break;
		}
		case 4: {
			cout << "Введите номер паспорта" << endl;
			getPositivNum(this->numPassport);
			break;
		}
		case 5: {	
			cout << "Введите номер водительских прав" << endl;
			getPositivNum(this->driverLicense);				//изменить данные
			break;
		}
		case 6: {
			fl = false;
		}
		}
		this->tableHead();
		cout << *this << endl;			//вывод изменений
	}
}

driver driver::operator = (const driver& other) {			//оператор =
	this->id = other.id;
	strcpy_s(this->name, 10, other.name);
	strcpy_s(this->surname, 15, other.surname);
	strcpy_s(this->midname, 15, other.midname);		
	this->numPassport = other.numPassport;
	this->driverLicense = other.driverLicense;				//копиривание параметров класса
	return *this;
}

void driver::replace(const driver& other) {				//замещение не нуллевых параметров
	dynamic_cast<human&>(*this).replace(dynamic_cast<const human&>(other));			//вызов replace класса родителя
	if (this->driverLicense)
		this->driverLicense = other.driverLicense;
	if (this->numPassport)
		this->numPassport = other.numPassport;					//замещение параметров класса
}

driver driver::ChooseParams() {				//выбор параметра сортировки
	driver SortParam;
	int var;
	cout << endl << "Сортировка по:" << endl << "1. Имени" << endl << "2. Фамилии" <<endl <<"3. Отчеству"<<endl;
	getNumWithBorders(var, 1, 3);			//выбор операции
	cout << endl;
	switch (var)
	{
	case 1: {
		strcpy_s(SortParam.name, 10, this->name);
		break;
	}
	case 2: {
		strcpy_s(SortParam.surname, 15, this->surname);
		break;
	}
	case 3: {
		strcpy_s(SortParam.surname, 15, this->midname);				//заполнение нужного поля
		break;
	}
	default:
		break;
	}

	return SortParam;
}

void driver::filter() {			//выбор параметров для поиска
	int var;
	while (1) {
		cout << "Поиск по:" << endl << "1. ФИО" << endl << "2. Номеру паспорта" << endl << "3. Номеру водительских прав" << endl
			<< "4. Выйти из фильтра" << endl; 				//выбор параметра
		getNumWithBorders(var, 1, 4);
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "Имя: ";
			getStr("RU", this->name, 10);
			cout << "Фамилия: ";
			getStr("RU", this->surname, 15);
			cout << "Отчество: ";
			getStr("RU", this->midname, 15);
			break;
		}
		case 2: {
			cout << "Номер паспорта: ";
			getPositivNum(this->numPassport);
			break;
		}
		case 3: {
			cout << "Номер прав: ";
			getPositivNum(this->driverLicense);				//ввод нужного поля
			break;
		}
		case 4: {
			return;
		}
		}
		tableHead();
		cout << *this << endl;		//вывод промежуточного фильтра
	}
};

bool driver::operator==(driver& other) {			//сравнение
	if (dynamic_cast<human&>(*this) == dynamic_cast<human&>(other)) {		//сравнение параметров класса родителя	
		if (other.driverLicense)
			if (driverLicense != other.driverLicense)
				return false;
		if (other.numPassport)
			if (numPassport != other.numPassport)			//сравнение параметров класса
				return false;
		return true;
	}
	else
		return false;
}

bool driver::operator>(driver& other) {			//оператор <
	return (dynamic_cast<human&>(*this) > dynamic_cast<human&>(other));		//вызов оператор < класса родителя
}

void driver::tableHead() {				//вывод шапки
	cout.setf(ios::left);
	cout << setw(5) << "id" << setw(13) << "Фамилия" << setw(10) << "Имя" << setw(13) << "Отчество"
		<< setw(17) << "Номер паспорта" << "Номер прав" << endl;
	cout << setw(68) << setfill('-') << "" << endl;
	cout.unsetf(ios::left);
	cout << setfill(' ');
}

istream& operator>>(istream& in, driver& other) {			//ввод
	in >> dynamic_cast<human&>(other);				//ввод полей класса родителя
	cout << "Номер паспорта: ";
	getPositivNum(other.numPassport);
	cout << "Номер прав: ";
	getPositivNum(other.driverLicense);			//ввод полей
	return in;
};

ostream& operator<<(ostream& out, driver& other) {		//вывод
	out << dynamic_cast<human&>(other);				//вывод полей класса родителя
	out.setf(ios::left);
	out << setw(17) << other.numPassport << setw(13) << other.driverLicense;		//вывод полей
	out.unsetf(ios::left);
	return out;
};

ifstream& operator>>(ifstream& inf, driver& other) {			//чтение из файла
	inf >> dynamic_cast<human&>(other);
	inf >> other.numPassport;
	inf >> other.driverLicense;

	return inf;
};

ofstream& operator<<(ofstream& out, driver& other) {		//запись в файл
	out << dynamic_cast<human&>(other);				//вывод полей класса родителя
	out.setf(ios::left);
	out << setw(17) << other.numPassport << setw(13) << other.driverLicense;		//вывод полей
	out.unsetf(ios::left);
	return out;
};		

//int numPassport;
//int driverLicense;