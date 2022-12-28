#include "date.h"

date date::operator=(const date& other) {			//date=date
	this->dd = other.dd;		//день
	this->mm = other.mm;		//месяц 
	this->yyyy = other.yyyy;	//год
	return *this;
}

date date::operator=(const int ms[3]) {			//date = int ms[3]
	dd = ms[0];			//день
	mm = ms[1];			//месяц
	yyyy = ms[2];		//год
	return *this;
}

void date::setDay(int dd) {			//установить день
	this->dd = dd;
}
void date::setMonth(int mm) {		//установить месяц
	this->mm = mm;
}

void date::setYear(int yyyy) {		//установить год 
	this->yyyy = yyyy;
}
	
int& date::getDay() {			//получить день
	return this->dd;
}

int& date::getMonth() {			//получить месяц
	return this->mm;
}

int date::getYear() {			//получить год
	return this->yyyy;
}

bool date::isNull() {		//проверка на нуль
	if (dd == 0 && mm == 0)	//если нуль	
		return true;
	return false;
};

bool date::leap(int year)		//високосный? 
{
	if (year % 4 == 0 || year % 400 == 0)
		return true;
	return false;
}

bool date::operator==(date& other) {			//оператор ==
	if (dd != other.dd || mm != other.mm || yyyy != other.yyyy)			//сравнение параметров класса
		return false;
	return true;

};

bool date::operator<(date& other) {				//оператор <
	if (*this - other < 0)
		return true;
	return false;
}

int date::operator-(date& other) {				//вычитание даты из даты
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };		//массив дней месяцев
	int rez = 0;
	for (int i = this->yyyy; i <= other.yyyy; i++) {
		if (leap(i))
			rez += 366;
		else
			rez += 365;								//разница полных лет в датах
	}
	for (int i = 0; i < this->mm-1; i++) {
		rez -= month[i];							//вычитание дней 1-ой даты
	}
	rez -= this->dd;		
	for (int i = other.mm; i < 12; i++) {
		rez -= month[i];							//вычитание дней 2-ой даты
	}
	rez -= (month[other.mm-1]-other.dd);
	return rez;

}

ostream& operator<<(ostream& out, date& other) {			//вывод
	out.unsetf(ios::left);
	out << setfill('0') << setw(2) << other.dd << " " << setfill('0') << setw(2) << other.mm <<" "<<setw(4) << other.yyyy <<setfill(' ');	
	out.setf(ios::left);
	return out;
}

istream& operator>>(istream& in, date& other) {			//ввод
	getDate(other.dd, other.mm, other.yyyy);
	return in;
}

ofstream& operator<<(ofstream& out, date& other) {		//запись в файл
	out.unsetf(ios::left);
	out << setfill('0') << setw(2) << other.dd << " " << setfill('0') << setw(2) << other.mm << " " << setw(4) << other.yyyy << setfill(' ');
	out.setf(ios::left);
	return out;
};		

ifstream& operator>>(ifstream& inf, date& other) {			//чтение из файла
	inf.unsetf(ios::left);
	inf >> setw(2) >> other.dd >> setw(2) >> other.mm >> setw(4) >> other.yyyy;
	inf.setf(ios::left);
	return inf;
}