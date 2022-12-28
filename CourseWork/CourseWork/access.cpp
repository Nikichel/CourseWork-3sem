#include "access.h"

char* access::getLogin() {		//�������� �����
	return this->login;			
};
char* access::getPassword() {	//������� ������
	return this->password;			
};

void access::setLogin(char* newLogin) {			//���������� �����
	strcpy_s(this->login, 20, newLogin);
};
void access::setPassword(char* newPassword) {	//���������� ������
	strcpy_s(this->password, 20, newPassword);
};

access access::operator=(const access& other) {			//�������� =
	strcpy_s(this->login, 20, other.login);
	strcpy_s(this->password, 20, other.password);		//����������� ����� 

	return *this;
}

bool access::operator==(access& other) {													//�����������
	if (!strcmp(this->login, other.login) && !strcmp(this->password, other.password))		//������ � ����� ���������
		return true;	
	else
		return false;
};

istream& operator>>(istream& in, access& other) {			//����
	cout << "������� �����: ";
	in.getline(other.login,20);			//���� ������
	cout << "������� ������: ";
	in.getline(other.password, 20);		//���� ������
	return in;
};
ifstream& operator>>(ifstream& inf, access& other) {			//������ �� �����
	inf >> other.login >> setw(25);			//������ ������
	inf >> other.password;					//������ ������

	return inf;
};

ofstream& operator<<(ofstream& outf, access& other) {			//������ � ����
	outf.setf(ios::left);
	outf << setw(25) << other.login << other.password;			//������ � ���� ������ � ������
	outf.unsetf(ios::left);
	return outf;
};
