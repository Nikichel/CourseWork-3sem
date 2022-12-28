#include "truck.h"

void truck::setHeight(int height) {			//установить высоту
	this->height = height;
};
void truck::setLength(int length) {			//установить длину
	this->length = length;
};

int truck::getHeight() {			//получить высоты
	return this->height;
};
int truck::getLength() {			//получить длину
	return this->length;
};

truck truck::operator=(const truck& other) {		//оператор =
	dynamic_cast<car&>(*this) = dynamic_cast<const car&>(other);	//вызов оператор = класса родителя

	this->height = other.height;
	this->length = other.length;		//копировние полей класса
	return *this;
};

bool truck::operator==(truck& other) {			//оператор ==
	if (dynamic_cast<car&>(*this) == dynamic_cast<car&>(other)) {		//сравнивание полей класса родителя

		if (other.height)
			if (this->height != other.height)
				return false;
		if (other.length)
			if (this->length != other.length)			//сравнивание полей класса
				return false;
		return true;
	}
	else
		return false;
}

bool truck::operator>(truck& other) {			//оператор >
	if (dynamic_cast<car&>(*this) > dynamic_cast<car&>(other)) {			//сравнивание полей класса родителя

		if (other.height)
			if (this->height <= other.height)
				return false;
		if (other.length)
			if (this->length <= other.length)			//сравнивание полей класса
				return false;
		return true;
	}
	else
		return false;
};

void truck::replace(truck& other) {			//замещение не нуллевых полей 
	dynamic_cast<car&>(*this).replace(dynamic_cast<car&>(other));			//вызов replace класса родителя
	if (this->height)
		this->height = other.height;
	if (this->length)
		this->length = other.length;			//замещение полей класса
};

truck truck::ChooseParams() {			//выпор параметра сортировки
	truck SortParam;
	int var;
	cout << endl << "Сортировка по:" << endl << "1. Марке" << endl << "2. Номеру места" << endl << "3. Времени въезда"
		<< endl << "4. Времени выезда"<<endl<<"5. Высоте"<<endl<<"6. Длние" << endl;
	getNumWithBorders(var, 1, 6);			//выбор операции
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
		SortParam.height = this->height;
		break;
	}
	case 6: {
		SortParam.length = this->length;			//заполнение параметра
		break;
	}
	default:
		break;
	}

	return SortParam;
};

void truck::tableHead() {			//шапка таблицы 
	cout.setf(ios::left);
	cout << setw(5) << "id" << setw(8) << "Место" << setw(18) << "Дата въезда" << setw(19) << "Дата выезда" << setw(9) << "Оплата"
		<< setw(10) << "Марка" << setw(15) << "Номер машины" << setw(9) << "Высота" <<setw(8) << "Длина" << endl;
	cout << setw(97) << setfill('-') << "" << endl;
	cout.unsetf(ios::left);
	cout << setfill(' ');
}

void truck::change() {			//изменить поля класса
	int var;
	while (1) {
		cout << "Сменить" << endl << "1. Место" << endl << "2. Марку" << endl << "3. Номер машины" << endl
			<< "4. Время въезда" << endl << "5. Время въезда" <<endl<< "6. Высота" <<endl
			<< "7. Длина" << endl<<"8. Подтвердить изменения" << endl;
		getNumWithBorders(var, 1, 8);			//выбыр поля
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
			cout << "Введите дату въезда" << endl;
			cin >> this->Place.getTimeOfEntry();
			break;
		}
		case 5: {
			cout << "Введите дату выезда" << endl;
			cin >> this->Place.getTimeOfExit();
			break;
		}
		case 6: {
			cout << "Введите высоту" << endl;
			getPositivNum(this->height);
			break;
		}
		case 7: {
			cout << "Введите длину" << endl;			//ввод полей
			getPositivNum(this->length);
			break;
		}
		case 8: {
			return;
		}
		}
		this->tableHead();
		cout << *this << endl;			//вывод измененных данных
	}
}

void truck::filter() {			//выбор параметров для поиска
	int var;
	while (1) {
		cout << "Поиск по:" << endl << "1. Месту" << endl << "2. Марке" << endl <<"3. Номеру машины" <<endl<< "4. Дате въезда" 
			<< endl << "5. Дате выезда"	<< endl <<"6. Длине"<<endl<<"7. Высоте" <<endl<<"8. Выйти из фильтра" << endl;				
		getNumWithBorders(var, 1, 8);		//выбор параметра
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
			cout << "Введите дату въезда" << endl;
			cin >> this->Place.getTimeOfEntry();
			break;
		}
		case 5: {
			cout << "Введите дату выезда" << endl;
			cin >> this->Place.getTimeOfExit();
			break;
		}
		case 6: {
			cout << "Введите длину" << endl;
			getPositivNum(this->length);
			break;
		}
		case 7: {
			cout << "Введите высоту" << endl;				//заполнение параметра
			getPositivNum(this->height);
			break;	
		}
		case 8: {
			return;
		}
		}
		this->tableHead();
		cout << *this << endl;			//вывод промежуточного параметра
	}
};
	
istream& operator>>(istream& in, truck& other) {			//ввод
	in >> dynamic_cast<car&>(other);		//ввод полей класса родителя
	rewind(stdin);
	cout << "Длина: ";
	getPositivNum(other.length);
	cout << "Высота: ";
	getPositivNum(other.height);			//ввод полей класса

	return in;
}; 

ostream& operator<<(ostream& out, truck& other) {		//вывод
	out << dynamic_cast<car&>(other);			//вывод полей класса родителя
	out.setf(ios::left);
	out << setw(9) << other.height << setw(8) << other.length;		//вывод полей класса
	out.unsetf(ios::left);
	return out;
};

ofstream& operator<<(ofstream& outf, truck& other) {		//запись в файл
	outf << dynamic_cast<car&>(other);			//запись в файл полей класса родителя
	outf.setf(ios::left);
	outf << setw(9) << other.height << setw(8) << other.length;		//запись в файл класса
	outf.unsetf(ios::left);
	return outf;
};

ifstream& operator>>(ifstream& inf, truck& other) {				//чтение из файла
	inf >> dynamic_cast<car&>(other);			//чтение полей класса родителя
	inf>> other.height >> other.length;			//чтение полей класса
	return inf;
}