#pragma once
#include <iostream>
#include <iomanip>
#include "place.h"
#include "FUNS.h"
using namespace std;

class  vehicle {		//����� �������� ������������
protected:
	int id;				//���������� �����
	char brand[10];		//�����
	place Place;		//�����
public:
	static int count;		//����������� ��� id
	vehicle() {				//����������� �� ���������
		id = 0;
		brand[0] = '\0';	//�������������
	}

	vehicle(const vehicle& other) {		//����������� �����������
		this->id = other.id;
		strcpy_s(this->brand, 10, other.brand);
		this->Place = other.Place;			
	}

	~vehicle() {};		//����������

	void setId(int id);			//���������� id
	void setBrand(const char* brand);		//���������� �����
	void setPlace(int num, char sector);	//���������� �����

	int getId();		//�������� id
	place& getPlace();	//�������� �����
	char* getBrand();	//�������� �����

	void operator=(const vehicle& other);		//�������� =
	bool operator ==(vehicle& other);			//�������� ==
	bool operator>(vehicle& other);				//�������� >

	virtual void tableHead();		//����� �������
	void replace(vehicle& other);	//��������� �� ������� �����
	vehicle ChooseParams();			//����� ���������

	friend ofstream& operator<<(ofstream& outf, vehicle& other);		//������ � ����
	friend istream& operator>>(istream& in, vehicle& other);			//����
	friend ostream& operator<<(ostream& out, vehicle& other);			//�����
	friend ifstream& operator>>(ifstream& in, vehicle& other);			//������ �� �����
};