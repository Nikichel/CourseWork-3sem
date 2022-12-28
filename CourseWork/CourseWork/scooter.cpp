#include "scooter.h"

void scooter::setCharge(bool charge) {			//���������� ������ �������
	this->charge = charge;
};
void scooter::setVolumeCharge(int volumeCharge) {			//���������� ����� �������
	this->volume�harge = volumeCharge;
};

bool scooter::getCharge() {			//�������� ������ �������
	return this->charge;
};
int scooter::getVolumeCharge() {	//�������� ����� �������
	return this->volume�harge;
};

scooter scooter::operator=(const scooter& other) {			//�������� =
	dynamic_cast<vehicle&>(*this) = dynamic_cast<const vehicle&>(other);		//����� �������� = ������ ��������
	this->charge = other.charge;
	this->volume�harge = other.volume�harge;			//����������� ����� ������

	return *this;
}

bool scooter::operator==(scooter& other) {			//�������� ==
	if (dynamic_cast<vehicle&>(*this) == dynamic_cast<vehicle&>(other)) {		//����� ��������� == ������ ��������

		if (other.volume�harge)
			if (this->volume�harge != other.volume�harge)			//��������� ����� ������
				return false;
		return true;
	}
	else
		return false;

}

bool scooter::operator>(scooter& other) {			//�������� <
	if (dynamic_cast<vehicle&>(*this) > dynamic_cast<vehicle&>(other)) {		//����� ��������� < ������ ��������

		if (other.volume�harge)
			if (this->volume�harge <= other.volume�harge)			//��������� �����
				return false;
		return true;
	}
	else
		return false;

}

void scooter::replace(scooter& other) {			//��������� �� �������� �����
	dynamic_cast<vehicle&>(*this).replace(dynamic_cast<vehicle&>(other));		//����� replace ������ ��������
	if (this->volume�harge)
		this->volume�harge = other.volume�harge;			//��������� �� �������� ����� ������
};

scooter scooter::ChooseParams() {			//�������� ����������
	scooter SortParam;
	int var;
	cout << endl << "���������� ��:" << endl << "1. �����" << endl << "2. ������ �����" << endl << "3. ������� ������"
		<< endl << "4. ������� ������" <<endl<< "5. �� �������" << endl;
	getNumWithBorders(var, 1, 5);			//����� ��������
	cout << endl;
	switch (var)
	{
	case 1: {
		strcpy_s(SortParam.brand, 10, this->brand);
		break;
	}
	case 2: {
		SortParam.Place.setNum(this->Place.getNum());
		break;
	}
	case 3: {
		SortParam.Place.setTimeOfEntry(this->Place.getTimeOfEntry());
		break;
	}
	case 4: {
		SortParam.Place.setTimeOfExit(this->Place.getTimeOfExit());
		break;
	}
	case 5: {
		SortParam.charge = this->charge;				//����������� ���� ��� ����������
		break;
	}
	default:
		break;
	}

	return SortParam;
};

void scooter::tableHead() {			//����� �������
	cout.setf(ios::left);
	cout << setw(5) << "id" << setw(8) << "�����"<<setw(18) << "���� ������" << setw(19) << "���� ������" << setw(9) << "������" << setw(10)
		<< "�����" << setw(16) << "����� �������" <<setw(10) << "�������" << endl;
	cout << setw(91) << setfill('-') << "" << endl;
	cout.unsetf(ios::left);
	cout << setfill(' ');
}

void scooter::change() {			//��������� ����� ������
	int var;
	while (1) {
		cout << "�������" << endl << "1. �����" << endl << "2. �����" << endl 
			<< "3. ����� ������" << endl << "4. ����� ������" <<endl<< "5. ����� �������" <<endl
			<< "6. �������" <<endl<< "7. ����������� ���������" << endl;
		getNumWithBorders(var, 1, 7);			//����� 
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "������� �����" << endl;
			getNum(this->Place.getNum());
			break;
		}
		case 2: {
			cout << "������� �����" << endl;
			getStr("ENG", this->brand, 10);
			break;
		}
		case 3: {
			cout << "������� ����� ������" << endl;
			cin >> this->Place.getTimeOfEntry();
			break;
		}
		case 4: {
			cout << "������� ������" << endl;
			cin >> this->Place.getTimeOfExit();
			break;
		}
		case 5: {
			cout << "������� ����� �������" << endl;
			getNum(this->volume�harge);
			break;
		}
		case 6: {
			cout << "���������� �� �������?(1-��, 0-���)" << endl;			//��������� ����
			cin >> this->charge;
			break;
		}
		case 7: {
			return;
		}
		}
		this->tableHead();
		cout << *this << endl;			//����� ���������
	}
}

void scooter::filter() {			//����� ���� ��� ������
	int var;
	while (1) {
		cout << "����� ��:" << endl << "1. �����" << endl << "2. �����" << endl << "3. ���� ������" << endl << "4. ���� ������"
			<< endl << "5. ����� �� �������" << endl;				//����� ���������
		getNumWithBorders(var, 1, 5);
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "������� �����" << endl;
			getNum(this->Place.getNum());
			break;
		}
		case 2: {
			cout << "������� �����" << endl;
			getStr("ENG", this->brand, 10);
			break;
		}
		case 3: {
			cout << "������� ����� ������" << endl;
			cin >> this->Place.getTimeOfEntry();
			break;
		}
		case 4: {
			cout << "������� ������" << endl;
			cin >> this->Place.getTimeOfExit();			//���������� ����
			break;
		}
		case 5: {
			return;
		}
		}
		this->tableHead();
		cout << *this << endl;			//����� �������������� �������
	}
};

istream& operator>>(istream& in, scooter& other) {			//���� ������
	in >> dynamic_cast<vehicle&>(other);			//���� ����� ������ ��������
	rewind(stdin);
	cout << "����� ������: ";
	getPositivNum(other.volume�harge);
	cout << "�������(1-��������, 0 -���): ";
	int charge;	
	getNumWithBorders(charge, 0, 1);			//���� ����� ������
	if (charge == 0)
		other.charge = false;			//�� ��������
	else
		other.charge = true;			//��������
	return in;
};

ofstream& operator<<(ofstream& outf, scooter& other) {		//������ � ����
	outf << dynamic_cast<vehicle&>(other);			//������ � ���� ����� ������ ��������
	outf.setf(ios::left);
	outf << setw(16) << other.volume�harge;
	if (other.charge)
		outf << setw(10) << "+";
	else
		outf << setw(10) << "-";
	outf.unsetf(ios::left);				//������ � ���� ����� ������
	return outf;
};

ostream& operator<<(ostream& out, scooter& other) {			//�����
	out << dynamic_cast<vehicle&>(other);			//����� ����� ������ ��������
	out.setf(ios::left);
	out << setw(16) << other.volume�harge;
	if (other.charge)
		out << setw(10) << "+";
	else
		out << setw(10) << "-";						//����� ����� ������
	out.unsetf(ios::left);
	return out;
};

ifstream& operator>>(ifstream& inf, scooter& other) {			//������ �� �����
	inf >> dynamic_cast<vehicle&>(other) >> setw(15);		//������ �� ����� ������ ��������
	inf >> other.volume�harge >> setw(16);
	char charge;
	inf >> charge;
	if (charge == '+')
		other.charge = true;
	else
		other.charge = false;			//������ ����� ������
	return inf;
}