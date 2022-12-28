#pragma once
#include <iostream>
#include <iomanip>
#include "FUNS.h"
using namespace std;

class date {		//����� ����
protected:
	int dd, mm, yyyy;	//����, �����, ���

public:
	date() {		//����������� �� ���������
		dd = mm = yyyy = 0;		//�������������
	};

	date(int day, int month, int year) {	//����������� � �����������
		dd = day;
		mm = month;
		yyyy = year;			//������������� ��������� �������
	};

	date(const date& other) {		//����������� �����������
		this->dd = other.dd;
		this->mm = other.mm;
		this->yyyy = other.yyyy;		//�����������
	};

	~date() {};		//����������

	date operator= (const date& other);		//�������� =
	date operator= (const int ms[3]);		//�������� =
	bool operator==(date& other);		//�������� ==
	bool operator<(date& other);		//������� <
	int operator-(date& other);		//�������� -

	bool isNull();			//������ �� �����
	bool leap(int year);		//���������� �� ���

	void setDay(int dd);		//���������� ����
	void setMonth(int mm);		//���������� �����
	void setYear(int yyyy);		//���������� ���

	int& getDay();			//�������� ����
	int& getMonth();		//�������� �����
	int getYear();			//�������� ���

	friend ostream& operator<<(ostream&, date&);		//�����
	friend istream& operator>>(istream&, date&);		//����
	friend ofstream& operator<<(ofstream&, date&);		//������ � ����
	friend ifstream& operator>>(ifstream& inf, date& other);		//������ �� �����

};
