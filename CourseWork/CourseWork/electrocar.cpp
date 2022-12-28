#include "electrocar.h"

void electrocar::setCharge(bool charge) {			//���������� �������
	this->charge = charge;
};
void electrocar::setVolumeCharge(int volumeCharge) {		//���������� ����� �������
	this->volume�harge = volumeCharge;
};

bool electrocar::getCharge() {			//�������� �������
	return this->charge;
};
int electrocar::getVolumeCharge() {		//�������� ����� �������
	return this->volume�harge;
};

electrocar electrocar::operator=(const electrocar& other) {				//�������� =
	dynamic_cast<car&>(*this) = dynamic_cast<const car&>(other);		//����� �������� = ������ ��������
	this->charge = other.charge;
	this->volume�harge = other.volume�harge;			//����������� ����� ������
	return *this;
}

bool electrocar::operator==(electrocar& other) {				//�������� ==
	if (dynamic_cast<car&>(*this) == dynamic_cast<car&>(other)) {			//��������� ����� ������ ��������

		if (other.volume�harge)
			if (this->volume�harge != other.volume�harge)		//��������� ����� ������
				return false;
		return true;
	}
	else
		return false;
}

bool electrocar::operator>(electrocar& other) {				//�������� >
	if (dynamic_cast<car&>(*this) > dynamic_cast<car&>(other)) {		//����� ��������� > ������ ��������
		if (other.volume�harge)
			if (this->volume�harge <= other.volume�harge)
				return false;
		if (other.charge)
			if (this->charge <= other.charge)				//��������� ����� ������
				return false;
		return true;
	}
	else
		return false;
}

void electrocar::replace(electrocar& other) {			//��������� �� �������� �����
	dynamic_cast<car&>(*this).replace(dynamic_cast<car&>(other));			//����� replace ������ ��������
	if (this->volume�harge)
		this->volume�harge = other.volume�harge;
	if (this->charge)
		this->charge = other.charge;			//��������� ����� ������
};

electrocar electrocar::ChooseParams() {			//����� ��������� ��� ����������
	electrocar SortParam;
	int var;
	cout << endl << "���������� ��:" << endl << "1. �����" << endl << "2. ������ �����" << endl << "3. ������� ������"
		<< endl << "4. ������� ������" <<endl<<"5. �� �������" << endl;
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
	case 5 : {
		SortParam.charge = this->charge;						//���������� ������� ���������
		break;
	}
	default:
		break;
	}

	return SortParam;
};

void electrocar::tableHead() {			//����� �������
	cout.setf(ios::left);
	cout << setw(5) << "id" << setw(8) << "�����" <<setw(18) << "���� ������" << setw(19) << "���� ������" << setw(9) << "������"
		<< setw(10) << "�����" << setw(15) << "����� ������" << setw(16) << "����� �������"<<setw(10) << "�������" << endl;
	cout << setw(106) << setfill('-') << "" << endl;
	cout.unsetf(ios::left);
	cout << setfill(' ');
}

void electrocar::change() {				//�������� ������
	int var;
	bool fl = true;
	while (fl) {
		cout << "�������" << endl << "1. �����" << endl << "2. �����" << endl << "3. ����� ������" << endl
			<< "4. ����� ������" << endl << "5. ����� ������" <<endl<<"6. ����� ��������" <<endl<<"7. �������" <<endl
			<<"8. ����������� ���������" << endl;
		getNumWithBorders(var, 1, 8);			//�����
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
			cin.getline(this->numCar, 8);
			break;
		}
		case 4: {
			cout << "������� ����� ������" << endl;
			cin >> this->Place.getTimeOfEntry();
			break;
		}
		case 5: {
			cout << "������� ����� ������" << endl;
			cin >> this->Place.getTimeOfExit();
			break;
		}
		case 6: {
			cout << "������� ����� �������" << endl;
			getNum(this->volume�harge);
			break;
		}
		case 7: {
			cout << "���������� �� �������?(1-��, 0-���)" << endl;
			cin >> this->charge;				//������� ������
			break;
		}
		case 8: {
			fl = false;
		}
		}
		this->tableHead();
		cout << *this << endl;			//����� ���������
	}
}

void electrocar::filter() {				//����� �� ����������
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
			cin.getline(this->numCar, 8);
			break;
		}
		case 4: {
			cout << "������� ����� ������" << endl;
			cin >> this->Place.getTimeOfEntry();				//���� ��������� �������
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

istream& operator>>(istream& in, electrocar& other) {				//���� �� �������
	in >> dynamic_cast<car&>(other);			//���� ����� ������ ��������
	rewind(stdin);
	cout << "����� ������: ";
	getNum(other.volume�harge);
	cout << "�������(1-��������, 0 -���): ";			//���� ����� ������
	int charge;
	getNumWithBorders(charge, 0, 1);
	if (charge == 0)
		other.charge = false;			//�� ��������
	else
		other.charge = true;			//��������

	return in;
};

ostream& operator<<(ostream& out, electrocar& other) {				//����� �� �����
	out << dynamic_cast<car&>(other);				//����� ����� ������ ��������
	out.setf(ios::left);
	out << setw(16)<<other.volume�harge;
	if (other.charge)
		out << setw(10) << "+";
	else
		out << setw(10) << "-";				//����� ����� ������
	out.unsetf(ios::left);
	return out;
};

ofstream& operator<<(ofstream& outf, electrocar& other) {				//������ � ����
	outf << dynamic_cast<car&>(other);					//������ ����� ������ ��������
	outf.setf(ios::left);
	outf << setw(16) << other.volume�harge;
	if (other.charge)
		outf << setw(10) << "+";
	else
		outf << setw(10) << "-";						//������ ����� ������
	outf.unsetf(ios::left);
	return outf;
};

ifstream& operator>>(ifstream& inf, electrocar& other) {		//������ �� �����
	inf >> dynamic_cast<car&>(other);					//������ ����� ������ ��������
	inf >> other.volume�harge>>setw(16);
	char charge;
	inf >> charge;
	if (charge == '+')
		other.charge = true;
	else
		other.charge = false;				//������ ����� ������
	return inf;
}