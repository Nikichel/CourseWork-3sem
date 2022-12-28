#pragma once
#include "human.h"
#include "place.h"

class driver : public human {		//����� ��������
	int numPassport;		//����� ��������
	int driverLicense;		//����� �������
public:
	driver() : human() {		//����������� �� ���������
		numPassport = 0;
		driverLicense = 0;		//������������� �����
	};

	driver(const driver& other) : human(other) {		//����������� �����������
		this->driverLicense = other.driverLicense;
		this->numPassport = other.numPassport;
	};

	~driver() {};		//����������

	void setNumPassport(int numPassport);		//���������� ����� ��������
	void setDriverLicense(int driverLicense);	//���������� ����� ����

	int getNumPassport();		//�������� ����� ��������
	int getDriverLicense();		//�������� ����� ����

	void tableHead() override;			//����� �������
	void change();						//���� ��������� �����					
	void replace(const driver& other);	//��������� �� ������� �����
	driver ChooseParams();				//����� ���� ����������
	void filter();						//������ ������

	driver operator = (const driver& other);	//�������� =
	bool operator==(driver& other);				//�������� ==
	bool operator>(driver& other);				//�������� >

	friend istream& operator>>(istream& in, driver& other);		//����
	friend ostream& operator<<(ostream& out, driver& other);	//�����
	friend ifstream& operator>>(ifstream& inf, driver& other);	//������ �� �����
	friend ofstream& operator<<(ofstream& out, driver& other);	//������ � ����
};