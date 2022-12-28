#include "employee.h"


void employee::setJobTitle(const char* jobTitle) {			//установить должность
	strcpy_s(this->jobTitle, 15, jobTitle);
};
void employee::setSalary(int salary) {				//установить зарплату
	this->salary = salary;
};
void employee::setAccess(access& otherAccess) {			//установить логин и пароль
	this->_access = otherAccess;
}

char* employee::getJobTitle() {			//получть должность
	return jobTitle;
};
int employee::getSalary() {				//получить зарплату
	return this->salary;
};
access employee::getAccess() {			//получить пароль и логин
	return this->_access;
}
	
void employee::greeting() {				//привествие после авторизации
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 2);				//изменить цвет консоли и шрифта
	cout << "Здравствуй, " << this->name << " " << this->midname << ".Хорошей работы!" << endl;		//вывод сообщения
	cout << setw(210) << setfill('_') << "" << setfill(' ')<<endl;
	SetConsoleTextAttribute(h, (15 << 4) + 0);
}

bool employee::isNull() {			//проверка на нуллевой класс
	if (!strlen(name) && !strlen(surname) && !strlen(midname))			//если поля нуллевые
		return true;
	return false;
};

void employee::start(queue<employee>& q) {
	int var=0;
	while (isNull() || var == 2) {
		cout << "1. Авторизация" << endl << "2. Регистрация" << endl;
		getNumWithBorders(var, 1, 2);
		switch (var) {
		case 1: {
			authorization();
			break;
		}
		case 2: {
			registration();
			q.put(*this);
		}
		}
	}
};

void employee::registration() {			//регистрация
	cin >> *this;
	char fileName[40];
	strcpy_s(fileName, 40, typeid(*this).name());
	strcat_s(fileName, ".txt");						
	MYFILE<employee> fileWorker(fileName);		//файл работников
	fileWorker.fileOpen('a');			//окрыть в режим добавить (текст.)
	fileWorker.fileWrite(*this);		//запись сотрудника
	fileWorker.fileClose();				//закрыть файл
}

void employee::authorization() {			//авторизация
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	access ACC;
	employee tmp;
	char fileName[40];
	strcpy_s(fileName, 40, typeid(*this).name());
	strcat_s(fileName, ".txt");
	MYFILE<employee> fileWorker(fileName);		//файл работников			
	fileWorker.fileOpen('r');				//открыть в режиме чтения
	cin >> ACC;			//ввод пароля и логина
	while (1) {
		fileWorker.fileRead(tmp);
		if (tmp._access == ACC)			//если нашли совпадение
		{
			*this = tmp;
			break;
		}
		if (fileWorker.isEnd()) {			//если не нашли совпадения
			SetConsoleTextAttribute(h, (15 << 4) + 4);
			cout << "Неверный пароль/логин" << endl;
			SetConsoleTextAttribute(h, (15 << 4) + 0);
			break;
		}
	}
	fileWorker.fileClose();			//закрыть файл
}

employee employee::operator=(const employee& other) {				//оператор =
	dynamic_cast<human&>(*this)=dynamic_cast<const human&>(other);		//вызов оператор= класса родителя
	strcpy_s(this->jobTitle, 15, other.jobTitle);
	this->startHoliday = other.startHoliday;
	this->endHoliday = other.endHoliday;
	this->salary = other.salary;
	this->_access = other._access;				//копирование полей класса

	return *this;
}

void employee::replace(const employee& other) {			//замещение не нуллевых полей
	dynamic_cast<human&>(*this).replace(dynamic_cast<const human&>(other));		//вызов replace класса родителя
}


employee employee::ChooseParams() {				//выпор поля сортировки
	employee SortParam;
	int var;
	cout << endl << "Сортировка по:" << endl << "1. Имени" << endl << "2. Фамилии" << endl <<"3. Отчеству" << endl;
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
		strcpy_s(SortParam.surname, 15, this->midname);			//заполенние поля сортировки
		break;
	}
	default:
		break;
	}

	return SortParam;
}

bool employee::operator>(employee& other) {			//оператор >
	return (dynamic_cast<human&>(*this) > dynamic_cast<human&>(other));		//вызов оператор > класса родителя
}

bool employee::operator==(employee& other) {		//оператор == 
	if (dynamic_cast<human&>(*this) == dynamic_cast<human&>(other)) {		//вызов оператор == класса родителя		
		if (strlen(other.jobTitle)!=1)
			if (strcmp(this->jobTitle, other.jobTitle))			//сравнение полей класса
				return false;
		return true;
	}
	else
		return false;
}


void employee::tableHead() {			//шапка таблицы
	cout.setf(ios::left);
	cout<< setw(13) << "Фамилия" << setw(10) << "Имя" << setw(13) << "Отчество"
		<< setw(18) << "Должность" <<setw(10) << "Зарплата"<<setw(18)<<"Начало отпуска"<<"Конец отпуска" << endl;
	cout << setw(95) << setfill('-') << "" << endl;
	cout.unsetf(ios::left);
	cout << setfill(' ');
}

void employee::filter() {			//выбор полей для поиска			
	int var;
	while (1) {
		cout << "Поиск сотрудника по:" << endl << "1. Фамилии" << endl << "2. Имяни" << endl << "3. Отчеству" << endl
			<< "4. Должности" << endl << "5. Выйти из фильтра" << endl;				//выбор параметра
		getNumWithBorders(var, 1, 5);
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "Введите фамилию" << endl;
			getStr("RU", this->surname, 15);
			break;
		}
		case 2: {
			cout << "Введите имя" << endl;
			getStr("RU", this->name, 10);
			break;
		}
		case 3: {
			cout << "Введите отчество" << endl;
			getStr("RU", this->midname, 15);
			break;
		}
		case 4: {
			cout << "Введите должность" << endl;			//ввод значения фильтра
			getStr("RU", this->jobTitle, 15);
			break;
		}
		case 5: {
			return;
		}
		}
		tableHead();
		cout << *this << endl;			//вывод промежуточного фильтра
	}
};

void employee::change() {			//изменить поля
	int var;
	while (1) {
		cout << "Изменить:" << endl << "1. Фамилию" << endl << "2. Имя" << endl << "3. Отчество" << endl
			<< "4. Должность" << endl <<"5. Зарплату" <<endl<<"6. Отпуск"<<endl<< "7. Выйти" << endl;				//выбор параметра
		getNumWithBorders(var, 1, 7);
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "Введите фамилию" << endl;
			getStr("RU", this->surname, 15);
			break;
		}
		case 2: {
			cout << "Введите имя" << endl;
			getStr("RU", this->name, 10);
			break;
		}
		case 3: {
			cout << "Введите отчество" << endl;
			getStr("RU", this->midname, 15);
			break;
		}
		case 4: {
			cout << "Введите должность" << endl;
			getStr("RU", this->jobTitle, 15);
			break;
		}
		case 5: {
			cout << "Введите зарплату" << endl;
			getPositivNum(this->salary);
			break;
		}
		case 6: {
			cout << "Начало отпуска: "<<endl;
			cin >> this->startHoliday;
			cout << "Конец отпуска: "<<endl;				//ввод поля
			cin >> this->endHoliday;
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

istream& operator>>(istream& in, employee& other) {				//ввод
	in >> dynamic_cast<human&>(other);		//ввод полей класса родителя
	in >> other._access;		//ввод пароля и логина

	return in;
};

ofstream& operator<<(ofstream& outf, employee& other) {			//запись в файл
	outf.setf(ios::left);
	outf << setw(15) << other._access.getLogin() <<setw(13) << other._access.getPassword();
	outf << setw(13) << other.surname << setw(10) << other.name << setw(13) << other.midname << setw(18) << other.jobTitle
		<< setw(10) << other.salary << setw(8) << other.startHoliday << " " << other.endHoliday;			//запись полей класса
	outf.unsetf(ios::left);
	return outf;
}

ifstream& operator>>(ifstream& inf, employee& other) {			//чтение из файла
	inf.setf(ios::left);
	inf >> setw(15) >> other._access.getLogin() >> setw(15) >> other._access.getPassword();
	inf >> setw(13) >> other.surname >> setw(10) >> other.name >> setw(13) >> other.midname >> setw(18) >> other.jobTitle
		>> setw(10) >> other.salary >> setw(8);					//чтение полей класса
	inf >> other.startHoliday >> other.endHoliday;
	inf.unsetf(ios::left);

	return inf;
}

ostream& operator<<(ostream& out, employee& other) {			//вывод
	out.setf(ios::left);
	out << setw(13)<< other.surname << setw(10) << other.name  << setw(13)<<other.midname<<setw(18) << other.jobTitle
		<<setw(10)<<other.salary<<other.startHoliday<< setw(8) <<""<<other.endHoliday;			//вывод полей класса
	out.unsetf(ios::left);
	return out;
};