#include "human.h"

int human::count = 0;			//��������� ������. ��������� ������

void human::setId(int id) {			//���������� id
	this->id = id;
};	
void human::setName(const char* name) {		//���������� ���
	strcpy_s(this->name, 10, name);
};
void human::setSurname(const char* surname) {		//���������� �������
	strcpy_s(this->surname, 15, surname);
};
void human::setMidname(const char* midname) {		//���������� ��������
	strcpy_s(this->midname, 15, midname);
};

int human::getId() {		//�������� id
	return this->id;
};
char* human::getName() {		//�������� ���
	return this->name;
};
char* human::getSurname() {		//�������� �������
	return this->surname;
};
char* human::getMidname() {		//�������� ��������
	return this->midname;
};

void human::replace(const human& other) {			//��������� �� �������� �����
	if (strlen(this->name))
		strcpy_s(this->name, 10, other.name);
	if (strlen(this->surname))
		strcpy_s(this->surname, 15, other.surname);
	if (strlen(this->midname))
		strcpy_s(this->midname, 15, other.midname);
	if (this->id)
		this->id=other.id;								//��������� �����
}

human human::ChooseParams() {			//����� ��������� ����������
	human SortParam;
	int var;
	cout << endl << "���������� ��:" << endl << "1. �����" << endl << "2. �������" <<endl <<"3. ��������" << endl;
	getNumWithBorders(var, 1, 3);			//����� ��������
	cout << endl;
	switch (var)
	{
	case 1: {
		strcpy_s(SortParam.name, 10, this->name);
		break;
	}
	case 2: {
		strcpy_s(SortParam.surname, 15, this->surname);
		break;
	}
	case 3: {
		strcpy_s(SortParam.surname, 15, this->midname);			//���������� ���������
		break;
	}
	default:
		break;
	}

	return SortParam;
}

bool human::operator==(human& other) {			//�������� ==
	if (strlen(other.name))
		if (strcmp(name, other.name)) return false;
	if (strlen(other.surname))
		if (strcmp(surname, other.surname)) return false;
	if (strlen(other.midname))
		if (strcmp(midname, other.midname)) return false;			//��������� �� �������� �����
	if (other.id)
		if (id != other.id)
			return false;
	return true;
}

bool human::operator>(human& other) {			//�������� >
	if (strlen(other.name))
		if (strcmp(name, other.name) <= 0)
			return false;
	if (strlen(other.surname))
		if (strcmp(surname, other.surname) <= 0)
			return false;
	if (strlen(other.midname))		
		if (strcmp(midname, other.midname) <= 0)		//������� �� �������� �����
			return false;

	return true;
}

human human::operator=(const human& other) {			//�������� =
	this->id = other.id;
	strcpy_s(this->name, 10, other.name);
	strcpy_s(this->surname, 15, other.surname);
	strcpy_s(this->midname, 15, other.midname);			//����������� ����� ������

	return *this;
}

void human::tableHead() {			//����� ����� �������
	cout.setf(ios::left);
	cout << setw(5) << "id" << setw(13) << "�������" << setw(10) << "���" <<"��������" << endl;
	cout << setw(36) << setfill('-') << "" << endl << setfill(' ');
	cout.unsetf(ios::left);
}

istream& operator>>(istream& in, human& other) {			//����
	rewind(stdin);
	other.id = other.count++;			//���������� id
	cout << "���: ";
	getStr("RU", other.name, 10);
	cout << "�������: ";
	getStr("RU", other.surname, 15);
	cout << "��������: ";
	getStr("RU", other.midname, 15);			//���� �����

	return in;
};

ostream& operator<<(ostream& out, human& other) {			//�����

	out.setf(ios::left);
	out << setw(5) << other.id << setw(13) << other.surname << setw(10) << other.name << setw(13) << other.midname;		//������ �����
	out.unsetf(ios::left);

	return out;
};

ifstream& operator>>(ifstream& inf, human& other) {			//������ �� �����
	inf >> other.id;
	inf >> other.surname >> setw(10);
	inf >> other.name >> setw(13);
	inf >> other.midname;
	other.count = other.id+1;				//������ ����� �� �����
	return inf;
};

//char name[10];
//char surname[15];
//char midname[15];