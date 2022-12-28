#include "vehicle.h"
int vehicle::count = 0;

void vehicle::setId(int id) {			//���������� id
	this->id = id;
};	
void vehicle::setBrand(const char* brand) {		//���������� �����
	strcpy_s(this->brand, 10, brand);
};
void vehicle::setPlace(int num, char sector) {		//���������� �����
	Place.setSector(sector);
	Place.setNum(num);
}

int vehicle::getId() {			//�������� id
	return this->id;
};
char* vehicle::getBrand() {		//�������� �����
	return this->brand;
};

place& vehicle::getPlace() {			//�������� �����
	return Place;
}

void vehicle::operator=(const vehicle& other) {		//�������� =
	this->id = other.id;
	strcpy_s(this->brand, 10, other.brand);
	this->Place = other.Place;					//����������� ����� ������
};

bool vehicle::operator ==(vehicle& other) {			//�������� ==
	if (other.id)
		if (this->id != other.id)
			return false;
	if(!(other.Place.getTimeOfEntry().isNull()))
		if (!(other.Place.getTimeOfEntry() == this->Place.getTimeOfEntry()))
			return false;
	if (other.Place.getSector() != '\0')
		if (other.Place.getSector() != this->Place.getSector())
			return false;
	if (other.Place.getNum())
		if (this->Place.getNum() != other.Place.getNum())
			return false;
	if (strlen(other.brand))
		if (strcmp(this->brand, other.brand))				//��������� �� �������� ����� ������
			return false;
	return true;
}

void vehicle::replace(vehicle& other) {			//��������� �� �������� �����
	if (strlen(this->brand))
		strcpy_s(this->brand, 10, other.brand);
	if (this->Place.getNum())
		this->Place.setNum(other.Place.getNum());
	if (!(this->Place.getTimeOfEntry().isNull()))
		this->Place.setTimeOfEntry(other.Place.getTimeOfEntry());
	if (!(this->Place.getTimeOfExit().isNull()))
		this->Place.setTimeOfExit(other.Place.getTimeOfExit());			//���� ���� �� ������, �������� ����� ����������
};

vehicle vehicle::ChooseParams() {			//����� ���� ����������
	vehicle SortParam;
	int var;
	cout << endl << "���������� ��:" << endl << "1. �����" << endl << "2. ������ �����" << endl << "3. ������� ������" 
		<< endl<< "4. ������� ������"<<endl;
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
		SortParam.Place.setTimeOfExit(this->Place.getTimeOfExit());			//���������� ����
		break;
	}
	default:
		break;
	}

	return SortParam;
};

bool vehicle::operator >(vehicle& other) {			//������� >
	if (strlen(other.brand))
		if (strcmp(brand, other.brand) >= 0)
			return false;
	if (other.Place.getNum())
		if (this->Place.getNum() >= other.Place.getNum())
			return false;
	if (!(other.Place.getTimeOfEntry().isNull()))
		if (!(other.Place.getTimeOfEntry() < this->Place.getTimeOfEntry()))
			return false;
	if (!(other.Place.getTimeOfExit().isNull()))
		if (!(other.Place.getTimeOfExit() < this->Place.getTimeOfExit()))			//��������� �� �������� ����� ������
			return false;
	return true;
}

void vehicle::tableHead() {			//����� ����� ������
	cout.setf(ios::left);
	cout << setw(5) << "id" << setw(8) << "�����" << setw(10) << "�����"<< setw(13) << "���� ������" <<setw(13) << "���� ������" <<"������" << endl;
	cout << setw(50) << setfill('-') <<"" << endl;
	cout.unsetf(ios::left);

}

istream& operator>>(istream& in, vehicle& other) {			//����
	other.id=other.count++;		//������� id
	int num;
	rewind(stdin);
	cout << "������� ����� �����: ";
	getPositivNum(num);
	other.Place.setNum(num);
	cout << "������� �����: ";
	rewind(stdin);
	getStr("ENG", other.brand, 10);			//���� ����� ������
	cout << "�����: "<<endl;
	in >> other.Place.getTimeOfEntry();
	cout << "������ �����?(0-���, 1-��)" << endl;
	getNumWithBorders(num, 0, 1);
	if (num) {
		cout << "�����: " << endl;
		in >> other.Place.getTimeOfExit();
		other.Place.setPayment((other.Place.getTimeOfEntry() - other.Place.getTimeOfExit()));		//���� ����� ������ Place
	}
	return in;
}

ostream& operator<<(ostream& out, vehicle& other) {			//�����
	out.setf(ios::left);
	out << setw(5) << other.id << setw(2) << other.Place.getNum() << setw(6) << other.Place.getSector() 
		<< setw(15) << other.Place.getTimeOfEntry() << setw(2) << "" << other.Place.getTimeOfExit() << setw(3) << "" <<setw(9) 
		<< other.Place.getPayment() << setw(10) << other.brand;
	out.unsetf(ios::left);			//����� ����� ������
	return out;
}

ofstream& operator<<(ofstream& outf, vehicle& other) {		//������ � ����
	outf.setf(ios::left);
	outf << setw(5) << other.id << setw(2);
	outf << other.Place.getNum() << setw(6);
	outf << other.Place.getSector() << setw(15);
	outf << other.Place.getTimeOfEntry() << setw(2);
	outf << "" << other.Place.getTimeOfExit() << setw(3);
	outf << "" << setw(9) << other.Place.getPayment() << setw(10) << other.brand;			//������ ����� � ����
	outf.unsetf(ios::left);
	return outf;
}

ifstream& operator>>(ifstream& inf , vehicle& other) {		//������ �� �����
	inf >> other.id;
	inf >> other.Place>>setw(10);
	inf >> other.brand;
	other.count = other.id;			//������ ����� �� �����
	return inf;
}