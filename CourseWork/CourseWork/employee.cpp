#include "employee.h"


void employee::setJobTitle(const char* jobTitle) {			//���������� ���������
	strcpy_s(this->jobTitle, 15, jobTitle);
};
void employee::setSalary(int salary) {				//���������� ��������
	this->salary = salary;
};
void employee::setAccess(access& otherAccess) {			//���������� ����� � ������
	this->_access = otherAccess;
}

char* employee::getJobTitle() {			//������� ���������
	return jobTitle;
};
int employee::getSalary() {				//�������� ��������
	return this->salary;
};
access employee::getAccess() {			//�������� ������ � �����
	return this->_access;
}
	
void employee::greeting() {				//���������� ����� �����������
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 2);				//�������� ���� ������� � ������
	cout << "����������, " << this->name << " " << this->midname << ".������� ������!" << endl;		//����� ���������
	cout << setw(210) << setfill('_') << "" << setfill(' ')<<endl;
	SetConsoleTextAttribute(h, (15 << 4) + 0);
}

bool employee::isNull() {			//�������� �� �������� �����
	if (!strlen(name) && !strlen(surname) && !strlen(midname))			//���� ���� ��������
		return true;
	return false;
};

void employee::start(queue<employee>& q) {
	int var=0;
	while (isNull() || var == 2) {
		cout << "1. �����������" << endl << "2. �����������" << endl;
		getNumWithBorders(var, 1, 2);
		switch (var) {
		case 1: {
			authorization();
			break;
		}
		case 2: {
			registration();
			q.put(*this);
		}
		}
	}
};

void employee::registration() {			//�����������
	cin >> *this;
	char fileName[40];
	strcpy_s(fileName, 40, typeid(*this).name());
	strcat_s(fileName, ".txt");						
	MYFILE<employee> fileWorker(fileName);		//���� ����������
	fileWorker.fileOpen('a');			//������ � ����� �������� (�����.)
	fileWorker.fileWrite(*this);		//������ ����������
	fileWorker.fileClose();				//������� ����
}

void employee::authorization() {			//�����������
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	access ACC;
	employee tmp;
	char fileName[40];
	strcpy_s(fileName, 40, typeid(*this).name());
	strcat_s(fileName, ".txt");
	MYFILE<employee> fileWorker(fileName);		//���� ����������			
	fileWorker.fileOpen('r');				//������� � ������ ������
	cin >> ACC;			//���� ������ � ������
	while (1) {
		fileWorker.fileRead(tmp);
		if (tmp._access == ACC)			//���� ����� ����������
		{
			*this = tmp;
			break;
		}
		if (fileWorker.isEnd()) {			//���� �� ����� ����������
			SetConsoleTextAttribute(h, (15 << 4) + 4);
			cout << "�������� ������/�����" << endl;
			SetConsoleTextAttribute(h, (15 << 4) + 0);
			break;
		}
	}
	fileWorker.fileClose();			//������� ����
}

employee employee::operator=(const employee& other) {				//�������� =
	dynamic_cast<human&>(*this)=dynamic_cast<const human&>(other);		//����� ��������= ������ ��������
	strcpy_s(this->jobTitle, 15, other.jobTitle);
	this->startHoliday = other.startHoliday;
	this->endHoliday = other.endHoliday;
	this->salary = other.salary;
	this->_access = other._access;				//����������� ����� ������

	return *this;
}

void employee::replace(const employee& other) {			//��������� �� �������� �����
	dynamic_cast<human&>(*this).replace(dynamic_cast<const human&>(other));		//����� replace ������ ��������
}


employee employee::ChooseParams() {				//����� ���� ����������
	employee SortParam;
	int var;
	cout << endl << "���������� ��:" << endl << "1. �����" << endl << "2. �������" << endl <<"3. ��������" << endl;
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
		strcpy_s(SortParam.surname, 15, this->midname);			//���������� ���� ����������
		break;
	}
	default:
		break;
	}

	return SortParam;
}

bool employee::operator>(employee& other) {			//�������� >
	return (dynamic_cast<human&>(*this) > dynamic_cast<human&>(other));		//����� �������� > ������ ��������
}

bool employee::operator==(employee& other) {		//�������� == 
	if (dynamic_cast<human&>(*this) == dynamic_cast<human&>(other)) {		//����� �������� == ������ ��������		
		if (strlen(other.jobTitle)!=1)
			if (strcmp(this->jobTitle, other.jobTitle))			//��������� ����� ������
				return false;
		return true;
	}
	else
		return false;
}


void employee::tableHead() {			//����� �������
	cout.setf(ios::left);
	cout<< setw(13) << "�������" << setw(10) << "���" << setw(13) << "��������"
		<< setw(18) << "���������" <<setw(10) << "��������"<<setw(18)<<"������ �������"<<"����� �������" << endl;
	cout << setw(95) << setfill('-') << "" << endl;
	cout.unsetf(ios::left);
	cout << setfill(' ');
}

void employee::filter() {			//����� ����� ��� ������			
	int var;
	while (1) {
		cout << "����� ���������� ��:" << endl << "1. �������" << endl << "2. �����" << endl << "3. ��������" << endl
			<< "4. ���������" << endl << "5. ����� �� �������" << endl;				//����� ���������
		getNumWithBorders(var, 1, 5);
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "������� �������" << endl;
			getStr("RU", this->surname, 15);
			break;
		}
		case 2: {
			cout << "������� ���" << endl;
			getStr("RU", this->name, 10);
			break;
		}
		case 3: {
			cout << "������� ��������" << endl;
			getStr("RU", this->midname, 15);
			break;
		}
		case 4: {
			cout << "������� ���������" << endl;			//���� �������� �������
			getStr("RU", this->jobTitle, 15);
			break;
		}
		case 5: {
			return;
		}
		}
		tableHead();
		cout << *this << endl;			//����� �������������� �������
	}
};

void employee::change() {			//�������� ����
	int var;
	while (1) {
		cout << "��������:" << endl << "1. �������" << endl << "2. ���" << endl << "3. ��������" << endl
			<< "4. ���������" << endl <<"5. ��������" <<endl<<"6. ������"<<endl<< "7. �����" << endl;				//����� ���������
		getNumWithBorders(var, 1, 7);
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "������� �������" << endl;
			getStr("RU", this->surname, 15);
			break;
		}
		case 2: {
			cout << "������� ���" << endl;
			getStr("RU", this->name, 10);
			break;
		}
		case 3: {
			cout << "������� ��������" << endl;
			getStr("RU", this->midname, 15);
			break;
		}
		case 4: {
			cout << "������� ���������" << endl;
			getStr("RU", this->jobTitle, 15);
			break;
		}
		case 5: {
			cout << "������� ��������" << endl;
			getPositivNum(this->salary);
			break;
		}
		case 6: {
			cout << "������ �������: "<<endl;
			cin >> this->startHoliday;
			cout << "����� �������: "<<endl;				//���� ����
			cin >> this->endHoliday;
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

istream& operator>>(istream& in, employee& other) {				//����
	in >> dynamic_cast<human&>(other);		//���� ����� ������ ��������
	in >> other._access;		//���� ������ � ������

	return in;
};

ofstream& operator<<(ofstream& outf, employee& other) {			//������ � ����
	outf.setf(ios::left);
	outf << setw(15) << other._access.getLogin() <<setw(13) << other._access.getPassword();
	outf << setw(13) << other.surname << setw(10) << other.name << setw(13) << other.midname << setw(18) << other.jobTitle
		<< setw(10) << other.salary << setw(8) << other.startHoliday << " " << other.endHoliday;			//������ ����� ������
	outf.unsetf(ios::left);
	return outf;
}

ifstream& operator>>(ifstream& inf, employee& other) {			//������ �� �����
	inf.setf(ios::left);
	inf >> setw(15) >> other._access.getLogin() >> setw(15) >> other._access.getPassword();
	inf >> setw(13) >> other.surname >> setw(10) >> other.name >> setw(13) >> other.midname >> setw(18) >> other.jobTitle
		>> setw(10) >> other.salary >> setw(8);					//������ ����� ������
	inf >> other.startHoliday >> other.endHoliday;
	inf.unsetf(ios::left);

	return inf;
}

ostream& operator<<(ostream& out, employee& other) {			//�����
	out.setf(ios::left);
	out << setw(13)<< other.surname << setw(10) << other.name  << setw(13)<<other.midname<<setw(18) << other.jobTitle
		<<setw(10)<<other.salary<<other.startHoliday<< setw(8) <<""<<other.endHoliday;			//����� ����� ������
	out.unsetf(ios::left);
	return out;
};