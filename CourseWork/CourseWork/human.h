#pragma once
#include <iostream>
#include <iomanip>
#include "FUNS.h"
using namespace std;

class human {		//����� �������
protected:
    int id;				//���������� �����
	char name[10];		//���
	char surname[15];	//�������
	char midname[15];	//��������
public:
	static int count;		//����������� ���� ��� id
	human() {
		id = 0;
		*name = '\0';
		*surname = '\0';
		*midname = '\0';		//������������� �����
	};

	human(const human& other) {			//���������� �����������		
		this->id = other.id;
		strcpy_s(this->name, 10, other.name);
		strcpy_s(this->surname, 15, other.surname);
		strcpy_s(this->midname, 15, other.midname);			//����������� �����
	};

	~human() {};		//�����������

	void setId(int id);			//���������� id
	void setName(const char* name);		//���������� ���
	void setSurname(const char* surname);		//���������� �������
	void setMidname(const char* midname);		//���������� ��������

	int getId();		//�������� id
	char* getName();	//�������� ���
	char* getSurname();		//�������� �������
	char* getMidname();		//�������� ��������

	virtual void tableHead();		//����� �������
	void replace(const human& other);		//��������� �� ����. �����
	human ChooseParams();		//����� ��������� ����������

	bool operator==(human& other);			//�������� ==
	human operator=(const human& other);	//�������� =
	bool operator>(human& other);			//��������>

	friend istream& operator>>(istream& in, human& other);		//����
	friend ostream& operator<<(ostream& out, human& other);		//�����
	friend ifstream& operator>>(ifstream& inf, human& other);	//������ �� �����
};

//int human::count = 0;