#include "date.h"

date date::operator=(const date& other) {			//date=date
	this->dd = other.dd;		//����
	this->mm = other.mm;		//����� 
	this->yyyy = other.yyyy;	//���
	return *this;
}

date date::operator=(const int ms[3]) {			//date = int ms[3]
	dd = ms[0];			//����
	mm = ms[1];			//�����
	yyyy = ms[2];		//���
	return *this;
}

void date::setDay(int dd) {			//���������� ����
	this->dd = dd;
}
void date::setMonth(int mm) {		//���������� �����
	this->mm = mm;
}

void date::setYear(int yyyy) {		//���������� ��� 
	this->yyyy = yyyy;
}
	
int& date::getDay() {			//�������� ����
	return this->dd;
}

int& date::getMonth() {			//�������� �����
	return this->mm;
}

int date::getYear() {			//�������� ���
	return this->yyyy;
}

bool date::isNull() {		//�������� �� ����
	if (dd == 0 && mm == 0)	//���� ����	
		return true;
	return false;
};

bool date::leap(int year)		//����������? 
{
	if (year % 4 == 0 || year % 400 == 0)
		return true;
	return false;
}

bool date::operator==(date& other) {			//�������� ==
	if (dd != other.dd || mm != other.mm || yyyy != other.yyyy)			//��������� ���������� ������
		return false;
	return true;

};

bool date::operator<(date& other) {				//�������� <
	if (*this - other < 0)
		return true;
	return false;
}

int date::operator-(date& other) {				//��������� ���� �� ����
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };		//������ ���� �������
	int rez = 0;
	for (int i = this->yyyy; i <= other.yyyy; i++) {
		if (leap(i))
			rez += 366;
		else
			rez += 365;								//������� ������ ��� � �����
	}
	for (int i = 0; i < this->mm-1; i++) {
		rez -= month[i];							//��������� ���� 1-�� ����
	}
	rez -= this->dd;		
	for (int i = other.mm; i < 12; i++) {
		rez -= month[i];							//��������� ���� 2-�� ����
	}
	rez -= (month[other.mm-1]-other.dd);
	return rez;

}

ostream& operator<<(ostream& out, date& other) {			//�����
	out.unsetf(ios::left);
	out << setfill('0') << setw(2) << other.dd << " " << setfill('0') << setw(2) << other.mm <<" "<<setw(4) << other.yyyy <<setfill(' ');	
	out.setf(ios::left);
	return out;
}

istream& operator>>(istream& in, date& other) {			//����
	getDate(other.dd, other.mm, other.yyyy);
	return in;
}

ofstream& operator<<(ofstream& out, date& other) {		//������ � ����
	out.unsetf(ios::left);
	out << setfill('0') << setw(2) << other.dd << " " << setfill('0') << setw(2) << other.mm << " " << setw(4) << other.yyyy << setfill(' ');
	out.setf(ios::left);
	return out;
};		

ifstream& operator>>(ifstream& inf, date& other) {			//������ �� �����
	inf.unsetf(ios::left);
	inf >> setw(2) >> other.dd >> setw(2) >> other.mm >> setw(4) >> other.yyyy;
	inf.setf(ios::left);
	return inf;
}