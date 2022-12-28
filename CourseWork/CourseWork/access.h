#pragma once
#include <iostream>
#include <iomanip>
#include "MyFile.cpp"

using namespace std;
class access			//����� �������
{
	char login[20];		//�����
	char password[20];		//������
public:
	access() {				//����������� �� ���������
		login[0] = '\0';
		password[0] = '\0';			//������������
	}

	access(const access& other) {			//�����������
		strcpy_s(this->login, 20, other.login);
		strcpy_s(this->password, 20, other.password);		//����������� �����
	}

	~access(){};		//����������

	char* getLogin();		//�������� �����
	char* getPassword();	//�������� ������

	void setLogin(char* newLogin);			//���������� �����
	void setPassword(char* newPassword);	//���������� ������

	access operator=(const access& other);	//�������� =
	bool operator==(access& other);			//�������� ==

	friend istream& operator>>(istream& in, access& other);			//����
	friend ofstream& operator<<(ofstream& outf, access& other);		//������ � ����
	friend ifstream& operator>>(ifstream& inf, access& other);		//������ �� �����
};

