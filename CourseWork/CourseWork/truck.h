#pragma once
#include "car.h"

class truck : public car {		//����� ��������
	int height;			//������ 
	int length;			//����� 

public:

	truck() : car() {			//����������� �� ���������
		height = length = 0;
	};

	truck(const truck& other) : car(other) {		//����������� �����������
		this->height = other.height;
		this->length = other.length;
	};
		
	~truck() {};		//���������� 

	void setHeight(int height);		//���������� ������
	void setLength(int length);		//���������� �����

	int getHeight();		//�������� ������
	int getLength();		//�������� �����
	
	truck operator=(const truck& other);		//�������� =
	bool operator==(truck& other);				//�������� ==
	bool operator>(truck& other);				//�������� >

	void tableHead() override;		//����� �������
	void replace(truck& other);		//��������� �� ���e��� �����
	truck ChooseParams();			//����� ���� ��� ����������

	void change();		//���� ��������� ����
	void filter();		//������ ������

	friend ofstream& operator<<(ofstream& out, truck& other);		//������ � ����
	friend istream& operator>>(istream& in, truck& other);			//����
	friend ostream& operator<<(ostream& out, truck& other);			//�����
	friend ifstream& operator>>(ifstream& inf, truck& other);		//������ �� �����
};
