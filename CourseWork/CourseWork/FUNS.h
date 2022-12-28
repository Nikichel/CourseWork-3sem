#pragma once
#include "MyExceprionFile.h"
#include "MyExceptionNUM.h"
#include "MyExceptionSTR.h"

#include "MyFile.cpp"
#include "Queue.cpp"

using namespace std;

template <typename T>
inline void getNum(T& value) {			//�������� ����� ����
	bool fl = true;
	do {
		fl = true;
		try {
			cin >> value;			//����� �����
			cin.ignore(80, '\n');		//��������� ������������ ����
			if (cin.fail())		//���� ����� ������
				throw MyExceptionNUM(1, "�������� �� �����", "�������� �� ����� ����� � ��������� ���������");
			else if (cin.gcount() > 1)			//���� ����� ����� � ������� ( ����.: 423����)
				throw MyExceptionNUM(2, "� ������ ����� ����������� ��������� �������", "��������� ������� ��� ������ �����");
		}
		catch (MyExceptionNUM errNUM) {
			errNUM.what();
			cin.clear();			//����� ������ � ������
			rewind(stdin);
			fl = false;
		}
	} while (!fl);
}

template < typename T1, typename T2, typename T3 >
inline void getNumWithBorders(T1& value, T2 FirstBorder, T3 SecondBorder) {			//���� ����� � ��������
	double tmp;
	bool fl = true;
	do {
		fl = true;
		try {
			getNum(tmp);			//���� ����� � ���������
			value = static_cast<T1> (tmp);
			if (tmp < FirstBorder || tmp > SecondBorder)			//����� �� �������
				throw MyExceptionNUM(1, "����� �� �������", "�� ����� �� �������� ��������� �������� �����");
			if (value - tmp)			//���� ����� double ����� ����� int
				throw MyExceptionNUM(-1, "�������� ���� ������ ����", "�� ����� ����� � ��������� �������");
		}
		catch (MyExceptionNUM errNUM) {
			errNUM.what();
			cin.clear();			//����� ������ � ������
			rewind(stdin);
			fl = false;
		}
	} while (!fl);
}


template <typename T>
inline void getPositivNum(T& value) {			//���� �������������� �����
	bool fl = true;
	do {
		fl = true;
		try {
			getNum(value);			//���� � �������� �����
			if (value <= 0)					//���� �������������
				throw MyExceptionNUM(3, "�������� �� ������������� �����", "������� ����� >0");
		}
		catch (MyExceptionNUM errNum) {
			errNum.what();
			rewind(stdin);			//����� ������ + ������
			fl = false;
		}

	} while (!fl);
}

inline void getStr(const char* language, char* str, int lenStr) {		//���� ������ �� ������ �����
	rewind(stdin);
	bool fl = true;
	int i = 0;
	do {
		fl = true;
		try {
			cin.getline(str, lenStr);
			if(!strlen(str))
				throw MyException(-10, "������ ������!");
			while (str[i] != '\0') {
				if (!strcmp(language, "RU"))			//�� ������
					if ((str[i] > '�' || str[i] < '�') && str[i] != ' ')
						throw MyExceptionSTR(10, "������������ ������� ����", str[i], i);		//���� �� ������� ������
				if (!strcmp(language, "ENG"))			//���� ������
					if ((str[i] < 'A' || str[i]> 'Z' && str[i] < 'a' || str[i]>'z') && str[i] != ' ')
						throw MyExceptionSTR(11, "������������ english ����", str[i], i);		//���� �� ���� ������
				i++;
			}
		}
		catch (MyExceptionSTR errStr) {
			errStr.what();		//����� ������ ������
			rewind(stdin);
			i = 0;
			fl = false;
		}
		catch (MyException errStr) {
			errStr.what();		//����� ������ ������
			rewind(stdin);
			i = 0;
			fl = false;
		}
	} while (!fl);
}

inline void getDate(int& dd, int& mm, int& yyyy) {				//���� ����
	cout << "���:";
	getPositivNum(yyyy);		//�������. �����
	cout << "�����: ";
	getNumWithBorders(mm, 1, 12);			//���� ������
	cout << "����:";
	if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
		getNumWithBorders(dd, 1, 31);
	else if (mm == 2 && yyyy % 4 == 0)
		getNumWithBorders(dd, 1, 29);
	else if (mm == 2)
		getNumWithBorders(dd, 1, 28);
	else
		getNumWithBorders(dd, 1, 30);			//���� ���
}

template <typename T>
inline void saveInFile(queue<T>& q) {			//�������� � ����
	char fileName[40];
	strcpy_s(fileName, 40, typeid(T).name());
	strcat_s(fileName, ".txt");						//���� ��������
	MYFILE<T> File(fileName);
	File.fileOpen('w');
	if (!q.isEmpty())
		for (queue<T>::template Iterator it = q.Begin(); it != q.End(); it++) {
			File.fileWrite(*it);
		}
	File.fileClose();
}

template <typename T>
inline void loadFromFile(queue<T>& q) {			//�������� �� �����
	char fileName[40];
	strcpy_s(fileName, 40, typeid(T).name());
	strcat_s(fileName, ".txt");				//���� ������
	MYFILE<T> File(fileName);
	File.fileOpen('r');
	T obj;
	while (1) {
		File.fileRead(obj);			//������
		if (File.isEnd())
			break;
		q.put(obj);		//� �������
	}
	File.fileClose();
}