#pragma once
#include "car.h"

class electrocar : public car {		//����� �������������
	bool charge;		//������ �������
	int volume�harge;	//����� �������

public:

	electrocar() : car() {			//����������� �� ���������
		charge = false;
		volume�harge = 0;
	};

	electrocar(const electrocar& other) : car(other) {		//����������� � �����������
		this->charge = other.charge;
		this->volume�harge = other.volume�harge;
	};

	~electrocar() {};		//����������

	void setCharge(bool charge);				//���������� ������
	void setVolumeCharge(int volumeCharge);		//���������� ����� �������

	bool getCharge();			//�������� ������
	int getVolumeCharge();		//�������� ����� �������

	electrocar operator=(const electrocar& other);		//�������� =
	bool operator==(electrocar& other);					//�������� ==
	bool operator>(electrocar& other);					//�������� >

	void tableHead() override;			//����� �������
	void replace(electrocar& other);	//��������� �� ������� �����
	electrocar ChooseParams();			//����� ���� ����������

	void change();		//���� ��������� �����
	void filter();		//������ ������

	friend ofstream& operator<<(ofstream& out, electrocar& other);		//������ � ����
	friend istream& operator>>(istream& in, electrocar& other);			//����
	friend ostream& operator<<(ostream& out, electrocar& other);		//�����
	friend ifstream& operator>>(ifstream& inf, electrocar& other);		//������ �� �����
};