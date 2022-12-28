#include "truck.h"

void truck::setHeight(int height) {			//���������� ������
	this->height = height;
};
void truck::setLength(int length) {			//���������� �����
	this->length = length;
};

int truck::getHeight() {			//�������� ������
	return this->height;
};
int truck::getLength() {			//�������� �����
	return this->length;
};

truck truck::operator=(const truck& other) {		//�������� =
	dynamic_cast<car&>(*this) = dynamic_cast<const car&>(other);	//����� �������� = ������ ��������

	this->height = other.height;
	this->length = other.length;		//���������� ����� ������
	return *this;
};

bool truck::operator==(truck& other) {			//�������� ==
	if (dynamic_cast<car&>(*this) == dynamic_cast<car&>(other)) {		//����������� ����� ������ ��������

		if (other.height)
			if (this->height != other.height)
				return false;
		if (other.length)
			if (this->length != other.length)			//����������� ����� ������
				return false;
		return true;
	}
	else
		return false;
}

bool truck::operator>(truck& other) {			//�������� >
	if (dynamic_cast<car&>(*this) > dynamic_cast<car&>(other)) {			//����������� ����� ������ ��������

		if (other.height)
			if (this->height <= other.height)
				return false;
		if (other.length)
			if (this->length <= other.length)			//����������� ����� ������
				return false;
		return true;
	}
	else
		return false;
};

void truck::replace(truck& other) {			//��������� �� �������� ����� 
	dynamic_cast<car&>(*this).replace(dynamic_cast<car&>(other));			//����� replace ������ ��������
	if (this->height)
		this->height = other.height;
	if (this->length)
		this->length = other.length;			//��������� ����� ������
};

truck truck::ChooseParams() {			//����� ��������� ����������
	truck SortParam;
	int var;
	cout << endl << "���������� ��:" << endl << "1. �����" << endl << "2. ������ �����" << endl << "3. ������� ������"
		<< endl << "4. ������� ������"<<endl<<"5. ������"<<endl<<"6. �����" << endl;
	getNumWithBorders(var, 1, 6);			//����� ��������
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
		SortParam.height = this->height;
		break;
	}
	case 6: {
		SortParam.length = this->length;			//���������� ���������
		break;
	}
	default:
		break;
	}

	return SortParam;
};

void truck::tableHead() {			//����� ������� 
	cout.setf(ios::left);
	cout << setw(5) << "id" << setw(8) << "�����" << setw(18) << "���� ������" << setw(19) << "���� ������" << setw(9) << "������"
		<< setw(10) << "�����" << setw(15) << "����� ������" << setw(9) << "������" <<setw(8) << "�����" << endl;
	cout << setw(97) << setfill('-') << "" << endl;
	cout.unsetf(ios::left);
	cout << setfill(' ');
}

void truck::change() {			//�������� ���� ������
	int var;
	while (1) {
		cout << "�������" << endl << "1. �����" << endl << "2. �����" << endl << "3. ����� ������" << endl
			<< "4. ����� ������" << endl << "5. ����� ������" <<endl<< "6. ������" <<endl
			<< "7. �����" << endl<<"8. ����������� ���������" << endl;
		getNumWithBorders(var, 1, 8);			//����� ����
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
			cout << "������� ���� ������" << endl;
			cin >> this->Place.getTimeOfEntry();
			break;
		}
		case 5: {
			cout << "������� ���� ������" << endl;
			cin >> this->Place.getTimeOfExit();
			break;
		}
		case 6: {
			cout << "������� ������" << endl;
			getPositivNum(this->height);
			break;
		}
		case 7: {
			cout << "������� �����" << endl;			//���� �����
			getPositivNum(this->length);
			break;
		}
		case 8: {
			return;
		}
		}
		this->tableHead();
		cout << *this << endl;			//����� ���������� ������
	}
}

void truck::filter() {			//����� ���������� ��� ������
	int var;
	while (1) {
		cout << "����� ��:" << endl << "1. �����" << endl << "2. �����" << endl <<"3. ������ ������" <<endl<< "4. ���� ������" 
			<< endl << "5. ���� ������"	<< endl <<"6. �����"<<endl<<"7. ������" <<endl<<"8. ����� �� �������" << endl;				
		getNumWithBorders(var, 1, 8);		//����� ���������
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
			cout << "������� ���� ������" << endl;
			cin >> this->Place.getTimeOfEntry();
			break;
		}
		case 5: {
			cout << "������� ���� ������" << endl;
			cin >> this->Place.getTimeOfExit();
			break;
		}
		case 6: {
			cout << "������� �����" << endl;
			getPositivNum(this->length);
			break;
		}
		case 7: {
			cout << "������� ������" << endl;				//���������� ���������
			getPositivNum(this->height);
			break;	
		}
		case 8: {
			return;
		}
		}
		this->tableHead();
		cout << *this << endl;			//����� �������������� ���������
	}
};
	
istream& operator>>(istream& in, truck& other) {			//����
	in >> dynamic_cast<car&>(other);		//���� ����� ������ ��������
	rewind(stdin);
	cout << "�����: ";
	getPositivNum(other.length);
	cout << "������: ";
	getPositivNum(other.height);			//���� ����� ������

	return in;
}; 

ostream& operator<<(ostream& out, truck& other) {		//�����
	out << dynamic_cast<car&>(other);			//����� ����� ������ ��������
	out.setf(ios::left);
	out << setw(9) << other.height << setw(8) << other.length;		//����� ����� ������
	out.unsetf(ios::left);
	return out;
};

ofstream& operator<<(ofstream& outf, truck& other) {		//������ � ����
	outf << dynamic_cast<car&>(other);			//������ � ���� ����� ������ ��������
	outf.setf(ios::left);
	outf << setw(9) << other.height << setw(8) << other.length;		//������ � ���� ������
	outf.unsetf(ios::left);
	return outf;
};

ifstream& operator>>(ifstream& inf, truck& other) {				//������ �� �����
	inf >> dynamic_cast<car&>(other);			//������ ����� ������ ��������
	inf>> other.height >> other.length;			//������ ����� ������
	return inf;
}