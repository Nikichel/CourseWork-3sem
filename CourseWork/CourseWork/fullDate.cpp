#include "fullDate.h"

void fullDate::setHour(int hour) {			//установить час
	this->hour = hour;
};
void fullDate::setMin(int min) {			//установить минуту
	this->min = min;
};

int& fullDate::getHour() {		//получить час
	return this->hour;
};
int& fullDate::getMin() {		//получить минуту
	return this->min;
};

fullDate fullDate::operator=(const fullDate& other) {		//оператор =
	dynamic_cast<date&>(*this) = dynamic_cast<const date&>(other);		//вызов оператор = класса родителя
	this->hour = other.hour;
	this->min = other.min;				//копирование полей класса

	return *this;
}

bool fullDate::isNull() {		//проверка на нуль
	if (hour == 0 && min == 0)	//если нуль	
		return true;
	return false;
};

bool fullDate::operator==(fullDate& other) {			//оператор ==
	if (dynamic_cast<date&>(*this) == dynamic_cast<date&>(other)) {		//сравнение полей класса родителя
		if (hour != other.hour || min != other.min)		//сравнение полей класса
			return false;

		return true;
	}
	else
		return false;

};

bool fullDate::operator<(fullDate& other) {				//оператор <
	if (dynamic_cast<date&>(*this) < dynamic_cast<date&>(other)) {		//вызов оператора < класса родителя
		if (*this - other < 0)
			return true;
		return false;
	}
	return false;
}

int fullDate::operator-(fullDate& other) {			//опреатор - 
	int rez = dynamic_cast<date&>(*this) - dynamic_cast<date&>(other);		//вычитание времени

	rez *= 24;		//перевод в часы
	rez += (-this->hour+other.hour);		//времени
	return rez;
}

istream& operator>>(istream& in, fullDate& other) {			//ввод
	in >> dynamic_cast<date&>(other);			//ввод полей класса родителя
	cout << "Час: ";
	getNumWithBorders(other.hour, 0, 23);
	cout << "Минута: ";
	getNumWithBorders(other.min, 0, 59);			//ввод полей класса

	return in;
};

ostream& operator<<(ostream& out, fullDate& other) {			//вывод 
	out << dynamic_cast<date&>(other);			//вывод полей класса родителя
	out.unsetf(ios::left);
	out << setw(1) << "";
	out << setfill('0') << setw(2) << other.hour << " " << setfill('0') << setw(2) << other.min << setfill(' ');		//вывод полей класса
	out.setf(ios::left);
	return out;
};

ofstream& operator<<(ofstream& out, fullDate& other) {		//запись в файл 
	out << dynamic_cast<date&>(other);			//вывод полей класса родителя
	out.unsetf(ios::left);
	out << setw(1) << "";
	out << setfill('0') << setw(2) << other.hour << " " << setfill('0') << setw(2) << other.min << setfill(' ');		//вывод полей класса
	out.setf(ios::left);
	return out;
};	

ifstream& operator>>(ifstream& inf, fullDate& other) {			//чтение из файла
	inf >> dynamic_cast<date&>(other);			//чтение из файла класса родителя
	inf.unsetf(ios::left);
	inf >> setw(2) >> other.hour >> setw(2) >> other.min;			//чтение полей класса
	inf.setf(ios::left);
	return inf;
}