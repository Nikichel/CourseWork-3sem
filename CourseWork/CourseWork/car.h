#pragma once
#include "vehicle.h"

class car : public vehicle {		//����� ������
protected:
	char numCar[8];			//����� ������
public:
	car() : vehicle() {		//����������� �� ���������
		*numCar = '\0';		
	};

	car(const car& other) : vehicle(other) {		//�����������
		strcpy_s(this->numCar, 8, other.numCar);
	};

	~car() {};		//����������

	void setNumCar(char num[4], char series[2], char region);		//���������� ����� ������

	char* getNumCar();			//�������� ����� ������

	car operator=(const car& other);		//�������� =
	bool operator ==(car& other);			//�������� ==
	bool operator>(car& other);				//�������� >

	void tableHead() override;		//����� �������
	void replace(car& other);		//��������� �� ������� �����
	car ChooseParams();				//����� ���� ����������

	void change();		//���� ��������� ����
	void filter();		//������ ������


	friend istream& operator>>(istream& in, car&);				//����
	friend ostream& operator<<(ostream& out, car& other);		//�����
	friend ofstream& operator<<(ofstream& out, car& other);		//������ � ����
	friend ifstream& operator>>(ifstream& inf, car& other);		//������ �� �����
};