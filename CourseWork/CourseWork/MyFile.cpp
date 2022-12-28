#pragma once
#include "MyFile.h"

template <typename T>
void MYFILE<T>::fileOpen(char mode) {		//отрытие файла в решиме
	this->mode = mode;
	bool flr = false;
	bool flw = false;
	try {
		if (mode == 'w') {		//запись
			_outFile.open(nameFile, ios::out);
			flw = true;
		}
		if (mode == 'r') {		//чтение
			_inFile.open(nameFile, ios::in);
			if(!_inFile.is_open())
				throw MyExceprionFile(-110, "Файла нет");
			flr = true;
		}
		if (mode == 'a') {		//добавить в конец
			_outFile.open(nameFile, ios::out | ios::app);
			flw = true;
		}
		if (!flw && !flr)
			throw MyExceprionFile(-100, "Неверный режим");
		if (flw && !_outFile.is_open() || flr && !_inFile.is_open()) {
			throw MyExceprionFile(100, "Ошибка открытия файла");				//исключения
		}
	}
	catch (MyExceprionFile ErrFile) {
		ErrFile.what();			//вывод ошибки
		exit(1);
	}
};

template <typename T>
void MYFILE<T>::fileClose() {		//закрытие файла
	try {
		if (mode == 'r') {
			_inFile.close();
		}
		if (mode == 'w' || mode == 'a') {
			_outFile.close();				//закрытие файлов
		}
		if (_outFile.is_open() && _inFile.is_open()) {
			throw MyExceprionFile(101, "Ошибка закрытия файла");			//исключение
		}
	}
	catch (MyExceprionFile ErrFile) {
		ErrFile.what();			//вывод ошибки
	}
};

template <typename T>
void MYFILE<T>::fileWrite(T& inform) {			//запись
	try {
		if (mode=='r')
			throw MyExceprionFile(-100, "Неверный режим");		//иселючение
		_outFile << inform;			//запись объекта
		_outFile << endl;
	}
	catch (MyExceprionFile ErrFile) {
		ErrFile.what();
	}
};

template <typename T>
void MYFILE<T>::fileRead(T& inform) {			//чтение
	try {
		if (mode=='w')
			throw MyExceprionFile(-100, "Неверный режим");		//исключение
		_inFile >> inform;		//чтение файла
	}
	catch (MyExceprionFile ErrFile) {
		ErrFile.what();
	}
};

template <typename T>
void MYFILE<T>::remote() {			//сместиться в начало
	if (_outFile.is_open())
		_outFile.seekp(0, ios::beg);			//сместить в начало
};

template <typename T>
bool MYFILE<T>::isEnd() {			//конец файла
	if (_inFile.eof() && _inFile.is_open() || _outFile.eof() && _outFile.is_open())
		return true;			//да конец
	else
		return false;		//нет 
}

