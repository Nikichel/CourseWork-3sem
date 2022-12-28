#pragma once
#include <iostream>
#include <fstream>
#include "MyExceprionFile.h"
#include "MyExceptionNUM.h"
#include "MyExceptionSTR.h"
using namespace std;
template <typename T>
class MYFILE			//����� ����
{
	ofstream _outFile;		//����� �����
	ifstream _inFile;		//����� ������
	char nameFile[80];		//�������� �����
	char mode;			//����� ������
public:
	MYFILE(char* nameFile) {					//����������� � �����������
		strcpy_s(this->nameFile, 80, nameFile);
		mode = '\0';
	}

	MYFILE(const MYFILE& other) {			//�����������
		this->mode = other.mode;
		strcpy_s(this->nameFile, 80, other.nameFile);
	}

	MYFILE(const char* nameFile) {			//����������� � �����������
		strcpy_s(this->nameFile, 80, nameFile);
		mode = '\0';
	}

	void fileOpen(char mode);		//������� ����
	void fileClose();						//������� ����
	void fileWrite(T& inform);				//�������� ������
	void fileRead(T& inform);				//���������
	void remote();							//� ������
	bool isEnd();							//�����
};

