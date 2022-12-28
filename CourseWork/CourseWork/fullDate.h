#pragma once
#include "date.h"

class fullDate : public date {		//����� ������� ���� 
	int hour;	//���
	int min;	//������
public:
	fullDate() : date() {		//����������� �� ���������
		hour = min = 0;		//�������������
	};

	fullDate(const fullDate& other) : date(other) {		//����������� �����������
		this->hour = other.hour;		
		this->min = other.min;		//����������� �����
	};

	~fullDate() {};		//����������

	void setHour(int hour);		//���������� ���
	void setMin(int min);		//���������� ������

	int& getHour();		//�������� ���
	int& getMin();		//�������� ������

	bool isNull();		//������ �� �����
	bool operator==(fullDate& other); 		//�������� ==
	bool operator<(fullDate& other);		//�������� <
	int operator-(fullDate& other);			//�������� -

	fullDate operator=(const fullDate& other);		//��������=

	friend istream& operator>>(istream& in, fullDate& other);		//����
	friend ostream& operator<<(ostream& out, fullDate& other);		//����� 
	friend ofstream& operator<<(ofstream& out, fullDate& other);	//������ � ���� 
	friend ifstream& operator>>(ifstream& inf, fullDate& other);	//������ �� �����
};
