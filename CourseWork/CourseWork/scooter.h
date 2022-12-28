#pragma once
#include "vehicle.h"

class scooter : public vehicle {		//����� ��������������
	bool charge;			//������ �������
	int volume�harge;		//����� �������

public:

	scooter() : vehicle() {			//����������� �� ���������
		charge = false;
		volume�harge = 0;
	};

	scooter(const scooter& other) : vehicle(other) {			//����������� �����������
		this->charge = other.charge;
		this->volume�harge = other.volume�harge;
	};

	~scooter() {};		//����������

	void setCharge(bool charge);				//���������� ������
	void setVolumeCharge(int volumeCharge);		//���������� ����� �������

	bool getCharge();		//�������� ������
	int getVolumeCharge();	//�������� ����� �������

	scooter operator=(const scooter& other);	//�������� =
	bool operator==(scooter& other);			//�������� ==
	bool operator>(scooter& other);				//�������� >

	void tableHead() override;			//����� �������
	void replace(scooter& other);		//��������� �� ������� �����
	scooter ChooseParams();				//����� ���� ����������

	void change();		//���� ��������� �����
	void filter();		//������ ������

	friend ofstream& operator<<(ofstream& out, scooter& other);		//������ � ����
	friend istream& operator>>(istream& in, scooter& other);		//����
	friend ostream& operator<<(ostream& out, scooter& other);		//�����
	friend ifstream& operator>>(ifstream& inf, scooter& other);		//������ �� �����
};