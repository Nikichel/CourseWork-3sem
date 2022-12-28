#pragma once
#include <iostream>
#include <fstream>
#include "MyExceprionFile.h"
#include "MyExceptionNUM.h"
#include "MyExceptionSTR.h"
using namespace std;
template <typename T>
class MYFILE			//класс файл
{
	ofstream _outFile;		//поток ввода
	ifstream _inFile;		//поток вывода
	char nameFile[80];		//название файла
	char mode;			//режим работы
public:
	MYFILE(char* nameFile) {					//конструктор с параметрами
		strcpy_s(this->nameFile, 80, nameFile);
		mode = '\0';
	}

	MYFILE(const MYFILE& other) {			//копирования
		this->mode = other.mode;
		strcpy_s(this->nameFile, 80, other.nameFile);
	}

	MYFILE(const char* nameFile) {			//конструктор с параметрами
		strcpy_s(this->nameFile, 80, nameFile);
		mode = '\0';
	}

	void fileOpen(char mode);		//открыть файл
	void fileClose();						//закрыть файл
	void fileWrite(T& inform);				//записать объект
	void fileRead(T& inform);				//прочитать
	void remote();							//в начало
	bool isEnd();							//конец
};

