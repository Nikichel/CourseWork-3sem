#pragma once
#include "human.h"
#include "date.h"
#include "access.h"
#include "windows.h"

class employee : public human {		//����� ���������
	date startHoliday;		//������ �������
	date endHoliday;		//����� �������
	int salary;				//��������
	char jobTitle[15];		//���������
	access _access;			//������ � �����
public:

	employee() : human() {			//����������� �� ���������
		salary = 0;
		strcpy_s(jobTitle,15, "-");
	};

	employee(employee& other) : human(other) {			//����������� �����������
		strcpy_s(this->jobTitle, 15, other.jobTitle);
		this->startHoliday = other.startHoliday;
		this->endHoliday = other.endHoliday;
		this->salary = other.salary;
		this->_access = other._access;
	};

	~employee() {};		//����������

	void setSalary(int salary);					//���������� ��������
	void setJobTitle(const char* jobTitle);		//���������� ���������
	void setAccess(access& otherAccess);		//���������� ������ � �����

	int getSalary();			//�������� ��������
	char* getJobTitle();		//�������� ���������
	access getAccess();			//�������� ������ � �����

	void filter();		//������ ������
	void change();		//���� ��������� �����

	bool isNull();		//������� �� �����
	void start(queue<employee>& q);			//�������� ���������
	void registration();	//�����������
	void authorization();	//�����������
	void greeting();		//����������

	void tableHead() override;				//����� �������
	void replace(const employee& other);	//��������� �� ������� �����
	employee ChooseParams();				//����� ���� ��� ���������� 

	employee operator=(const employee& other);		//�������� =
	bool operator==(employee& other);				//�������� ==
	bool operator>(employee& other);				//�������� >

	friend istream& operator>>(istream& in, employee& other);			//����
	friend ostream& operator<<(ostream& out, employee& other);			//�����
	friend ofstream& operator<<(ofstream& outf, employee& other);		//������ � ����
	friend ifstream& operator>>(ifstream& inf, employee& other);		//������ �� �����
};