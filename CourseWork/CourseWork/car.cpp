#include "car.h"

void car::setNumCar(char num[4], char series[2], char region) {			//���������� ����� ������
	for (int i = 0; i < 4; i++)
		this->numCar[i] = num[i];	
	for (int i = 0; i < 2; i++)
		this->numCar[i+4] = series[i];
	this->numCar[6] = region;
};

char* car::getNumCar() {		//�������� ����� ������
	return this->numCar;
}

car car::operator=(const car& other) {										//�������� =
	dynamic_cast<vehicle&>(*this) = dynamic_cast<const vehicle&>(other);	//����� �������� = ������ ��������
	strcpy_s(this->numCar, 8, other.numCar);								//����������� ����� ������
	return *this;
};

bool car::operator ==(car& other) {				//�������� ���������
	if (dynamic_cast<vehicle&>(*this) == dynamic_cast<vehicle&>(other)) {			//��������� ����� ������ ��������
		if (strlen(other.numCar))
			if (strcmp(this->numCar, other.numCar))
				return false;							//�� ����. � ������ => false
		return true;
	}
	else
		return false;

}

bool car::operator>(car& other) {						//�������� >
	if (dynamic_cast<vehicle&>(*this) > dynamic_cast<vehicle&>(other)) {		//�������� > ��� ������ ��������
		if (strlen(other.numCar))
			if (strcmp(this->numCar, other.numCar)<=0)
				return false;							//�� ����. � �� ������ - false
		return true;
	}
	else
		return false;
};

void car::replace(car& other) {							//��������� ���������� ����� ������� ����������
	dynamic_cast<vehicle&>(*this).replace(dynamic_cast<vehicle&>(other));		//����� ������ replace ������ ��������
	if (strlen(this->numCar))
		strcpy_s(this->numCar, 8, other.numCar);			//��������� ����� ������
};

car car::ChooseParams() {				//����� ���������� ����������
	car SortParam;
	int var;
	cout << endl << "���������� ��:" << endl << "1. �����" << endl << "2. ������ �����" << endl << "3. ������� ������"
		<< endl << "4. ������� ������" << endl;
	getNumWithBorders(var, 1, 4);			//����� ��������
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
		SortParam.Place.setTimeOfExit(this->Place.getTimeOfExit());				//���������� ������� ����
		break;
	}
	default:
		break;
	}

	return SortParam;
};

void car::tableHead() {				//����� ����� �������
	cout.setf(ios::left);
	cout << setw(5) << "id" << setw(8) << "�����"<< setw(18) << "���� ������" << setw(19) << "���� ������" << setw(9) << "������" << setw(10) << "�����"  << "����� ������" << endl;
	cout << setw(81) << setfill('-') << "" << endl;
	cout.unsetf(ios::left);
	cout << setfill(' ');
}

void car::change() {			//�������� ������
	int var;
	while (1) {
		cout << "�������" << endl << "1. �����" << endl << "2. �����" << endl << "3. ����� ������" << endl
			<< "4. ����� ������" << endl << "5. ����� ������" <<endl <<"6. �����" << endl;
		getNumWithBorders(var, 1, 6);			//����� ��������
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "������� �����:" << endl;
			cin >> this->Place;
			break;
		}
		case 2: {
			cout << "������� �����" << endl;
			getStr("ENG", this->brand, 10);
			break;
		}
		case 4: {
			cout << "������� ���� ������" << endl;
			fullDate timeOfEntry;
			cin >> timeOfEntry;
			this->Place.setTimeOfEntry(timeOfEntry);
			break;
		}
		case 5: {
			cout << "������� ���� ������" << endl;
			fullDate timeOfExit;
			cin >> timeOfExit;
			this->Place.setTimeOfExit(timeOfExit);
			break;
		}
		case 3: {
			cout << "������� ����� ������" << endl;
			cin.getline(this->numCar, 8);
			break;										//���� ���������
		}
		case 6: {
			return;
		}
		}
		this->tableHead();
		cout << *this << endl;			//����� ���������
	}
}

void car::filter() {			//����� ���������� ��� ������
	int var;
	while (1) {
		cout << "����� ��:" << endl << "1. �����" << endl << "2. �����" << endl << "3. ������ ������" << endl
			<< "4. ���� ������" << endl << "5. ���� ������"  <<endl <<"6. ����� �� �������" << endl;				
		getNumWithBorders(var, 1, 6);			//����� ���������
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "������� �����:" << endl;
			cin >> this->Place;
			break;
		}
		case 2: {
			cout << "������� �����" << endl;
			getStr("ENG", this->brand, 10);
			break;
		}
		case 4: {
			cout << "������� ���� ������" << endl;
			fullDate timeOfEntry;
			cin >> timeOfEntry;
			this->Place.setTimeOfEntry(timeOfEntry);
			break;
		}
		case 5: {
			cout << "������� ���� ������" << endl;
			fullDate timeOfExit;
			cin >> timeOfExit;
			this->Place.setTimeOfExit(timeOfExit);
			break;
		}
		case 3: {
			cout << "������� ����� ������" << endl;
			cin.getline(this->numCar, 8);
			break;										//���� ���������
		}
		case 6: {
			return ;
		}
		}
		tableHead();
		cout << *this<<endl;			//����� ���������� �������
	}
};

istream& operator>>(istream& in, car& other) {			//����
	in >> dynamic_cast<vehicle&>(other);	//���� ���������� ������ ��������
	rewind(stdin);
	cout << "������� ����� ������: ";
	in.getline(other.numCar, 8);			//���� ���������� ������
	return in;
};

ostream& operator<<(ostream& out, car& other) {			//�����
	out << dynamic_cast<vehicle&>(other);		//����� ���������� ��������
	out.setf(ios::left);
	out << setw(15) << other.numCar;			//����� ���������� ������
	out.unsetf(ios::left);
	return out;
};

ofstream& operator<<(ofstream& outf, car& other) {			//������ � ����
	outf << dynamic_cast<vehicle&>(other);		//������ ���������� ������ ��������
	outf.setf(ios::left);
	outf << setw(15) << other.numCar;			//������ ���������� ������
	outf.unsetf(ios::left);
	return outf;
};

ifstream& operator>>(ifstream& inf, car& other){			//������ �� �����
	inf >> dynamic_cast<vehicle&>(other)>>setw(15);			//������ ���������� ������ ��������
	inf >> other.numCar;									//������ ���������� ������
	return inf;
}