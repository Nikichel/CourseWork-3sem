#include "driver.h"

void driver::setNumPassport(int numPassport) {				//���������� ����� ��������
	this->numPassport = numPassport;
};
void driver::setDriverLicense(int driverLicense) {			//��������� ����� ������������ ����
	this->driverLicense = driverLicense;
};

int driver::getNumPassport() {			//�������� ����� ��������
	return this->numPassport;
};
int driver::getDriverLicense() {		//�������� ����� ��������
	return this->driverLicense;
};

void driver::change() {			//�������� ������
	int var;
	bool fl = true;
	while (fl) {
		cout << "�������" << endl << "1. ���" << endl << "2. �������" << endl << "3. ��������" << endl
			<< "4. ����� ��������" << endl << "5. ����� ����" << endl << "6. ����������� ���������" << endl;
		getNumWithBorders(var, 1, 6);				//����� ���������
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "������� ���" << endl;
			getStr("RU", this->name, 10);
			break;
		}
		case 2: {
			cout << "������� �������" << endl;
			getStr("RU", this->surname, 15);
			break;
		}
		case 3: {
			cout << "������� ��������" << endl;
			getStr("RU", this->midname, 15);
			break;
		}
		case 4: {
			cout << "������� ����� ��������" << endl;
			getPositivNum(this->numPassport);
			break;
		}
		case 5: {	
			cout << "������� ����� ������������ ����" << endl;
			getPositivNum(this->driverLicense);				//�������� ������
			break;
		}
		case 6: {
			fl = false;
		}
		}
		this->tableHead();
		cout << *this << endl;			//����� ���������
	}
}

driver driver::operator = (const driver& other) {			//�������� =
	this->id = other.id;
	strcpy_s(this->name, 10, other.name);
	strcpy_s(this->surname, 15, other.surname);
	strcpy_s(this->midname, 15, other.midname);		
	this->numPassport = other.numPassport;
	this->driverLicense = other.driverLicense;				//����������� ���������� ������
	return *this;
}

void driver::replace(const driver& other) {				//��������� �� �������� ����������
	dynamic_cast<human&>(*this).replace(dynamic_cast<const human&>(other));			//����� replace ������ ��������
	if (this->driverLicense)
		this->driverLicense = other.driverLicense;
	if (this->numPassport)
		this->numPassport = other.numPassport;					//��������� ���������� ������
}

driver driver::ChooseParams() {				//����� ��������� ����������
	driver SortParam;
	int var;
	cout << endl << "���������� ��:" << endl << "1. �����" << endl << "2. �������" <<endl <<"3. ��������"<<endl;
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
		strcpy_s(SortParam.surname, 15, this->midname);				//���������� ������� ����
		break;
	}
	default:
		break;
	}

	return SortParam;
}

void driver::filter() {			//����� ���������� ��� ������
	int var;
	while (1) {
		cout << "����� ��:" << endl << "1. ���" << endl << "2. ������ ��������" << endl << "3. ������ ������������ ����" << endl
			<< "4. ����� �� �������" << endl; 				//����� ���������
		getNumWithBorders(var, 1, 4);
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "���: ";
			getStr("RU", this->name, 10);
			cout << "�������: ";
			getStr("RU", this->surname, 15);
			cout << "��������: ";
			getStr("RU", this->midname, 15);
			break;
		}
		case 2: {
			cout << "����� ��������: ";
			getPositivNum(this->numPassport);
			break;
		}
		case 3: {
			cout << "����� ����: ";
			getPositivNum(this->driverLicense);				//���� ������� ����
			break;
		}
		case 4: {
			return;
		}
		}
		tableHead();
		cout << *this << endl;		//����� �������������� �������
	}
};

bool driver::operator==(driver& other) {			//���������
	if (dynamic_cast<human&>(*this) == dynamic_cast<human&>(other)) {		//��������� ���������� ������ ��������	
		if (other.driverLicense)
			if (driverLicense != other.driverLicense)
				return false;
		if (other.numPassport)
			if (numPassport != other.numPassport)			//��������� ���������� ������
				return false;
		return true;
	}
	else
		return false;
}

bool driver::operator>(driver& other) {			//�������� <
	return (dynamic_cast<human&>(*this) > dynamic_cast<human&>(other));		//����� �������� < ������ ��������
}

void driver::tableHead() {				//����� �����
	cout.setf(ios::left);
	cout << setw(5) << "id" << setw(13) << "�������" << setw(10) << "���" << setw(13) << "��������"
		<< setw(17) << "����� ��������" << "����� ����" << endl;
	cout << setw(68) << setfill('-') << "" << endl;
	cout.unsetf(ios::left);
	cout << setfill(' ');
}

istream& operator>>(istream& in, driver& other) {			//����
	in >> dynamic_cast<human&>(other);				//���� ����� ������ ��������
	cout << "����� ��������: ";
	getPositivNum(other.numPassport);
	cout << "����� ����: ";
	getPositivNum(other.driverLicense);			//���� �����
	return in;
};

ostream& operator<<(ostream& out, driver& other) {		//�����
	out << dynamic_cast<human&>(other);				//����� ����� ������ ��������
	out.setf(ios::left);
	out << setw(17) << other.numPassport << setw(13) << other.driverLicense;		//����� �����
	out.unsetf(ios::left);
	return out;
};

ifstream& operator>>(ifstream& inf, driver& other) {			//������ �� �����
	inf >> dynamic_cast<human&>(other);
	inf >> other.numPassport;
	inf >> other.driverLicense;

	return inf;
};

ofstream& operator<<(ofstream& out, driver& other) {		//������ � ����
	out << dynamic_cast<human&>(other);				//����� ����� ������ ��������
	out.setf(ios::left);
	out << setw(17) << other.numPassport << setw(13) << other.driverLicense;		//����� �����
	out.unsetf(ios::left);
	return out;
};		

//int numPassport;
//int driverLicense;