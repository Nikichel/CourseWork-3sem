#include "fullDate.h"

void fullDate::setHour(int hour) {			//���������� ���
	this->hour = hour;
};
void fullDate::setMin(int min) {			//���������� ������
	this->min = min;
};

int& fullDate::getHour() {		//�������� ���
	return this->hour;
};
int& fullDate::getMin() {		//�������� ������
	return this->min;
};

fullDate fullDate::operator=(const fullDate& other) {		//�������� =
	dynamic_cast<date&>(*this) = dynamic_cast<const date&>(other);		//����� �������� = ������ ��������
	this->hour = other.hour;
	this->min = other.min;				//����������� ����� ������

	return *this;
}

bool fullDate::isNull() {		//�������� �� ����
	if (hour == 0 && min == 0)	//���� ����	
		return true;
	return false;
};

bool fullDate::operator==(fullDate& other) {			//�������� ==
	if (dynamic_cast<date&>(*this) == dynamic_cast<date&>(other)) {		//��������� ����� ������ ��������
		if (hour != other.hour || min != other.min)		//��������� ����� ������
			return false;

		return true;
	}
	else
		return false;

};

bool fullDate::operator<(fullDate& other) {				//�������� <
	if (dynamic_cast<date&>(*this) < dynamic_cast<date&>(other)) {		//����� ��������� < ������ ��������
		if (*this - other < 0)
			return true;
		return false;
	}
	return false;
}

int fullDate::operator-(fullDate& other) {			//�������� - 
	int rez = dynamic_cast<date&>(*this) - dynamic_cast<date&>(other);		//��������� �������

	rez *= 24;		//������� � ����
	rez += (-this->hour+other.hour);		//�������
	return rez;
}

istream& operator>>(istream& in, fullDate& other) {			//����
	in >> dynamic_cast<date&>(other);			//���� ����� ������ ��������
	cout << "���: ";
	getNumWithBorders(other.hour, 0, 23);
	cout << "������: ";
	getNumWithBorders(other.min, 0, 59);			//���� ����� ������

	return in;
};

ostream& operator<<(ostream& out, fullDate& other) {			//����� 
	out << dynamic_cast<date&>(other);			//����� ����� ������ ��������
	out.unsetf(ios::left);
	out << setw(1) << "";
	out << setfill('0') << setw(2) << other.hour << " " << setfill('0') << setw(2) << other.min << setfill(' ');		//����� ����� ������
	out.setf(ios::left);
	return out;
};

ofstream& operator<<(ofstream& out, fullDate& other) {		//������ � ���� 
	out << dynamic_cast<date&>(other);			//����� ����� ������ ��������
	out.unsetf(ios::left);
	out << setw(1) << "";
	out << setfill('0') << setw(2) << other.hour << " " << setfill('0') << setw(2) << other.min << setfill(' ');		//����� ����� ������
	out.setf(ios::left);
	return out;
};	

ifstream& operator>>(ifstream& inf, fullDate& other) {			//������ �� �����
	inf >> dynamic_cast<date&>(other);			//������ �� ����� ������ ��������
	inf.unsetf(ios::left);
	inf >> setw(2) >> other.hour >> setw(2) >> other.min;			//������ ����� ������
	inf.setf(ios::left);
	return inf;
}