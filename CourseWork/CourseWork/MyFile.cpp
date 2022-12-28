#pragma once
#include "MyFile.h"

template <typename T>
void MYFILE<T>::fileOpen(char mode) {		//������� ����� � ������
	this->mode = mode;
	bool flr = false;
	bool flw = false;
	try {
		if (mode == 'w') {		//������
			_outFile.open(nameFile, ios::out);
			flw = true;
		}
		if (mode == 'r') {		//������
			_inFile.open(nameFile, ios::in);
			if(!_inFile.is_open())
				throw MyExceprionFile(-110, "����� ���");
			flr = true;
		}
		if (mode == 'a') {		//�������� � �����
			_outFile.open(nameFile, ios::out | ios::app);
			flw = true;
		}
		if (!flw && !flr)
			throw MyExceprionFile(-100, "�������� �����");
		if (flw && !_outFile.is_open() || flr && !_inFile.is_open()) {
			throw MyExceprionFile(100, "������ �������� �����");				//����������
		}
	}
	catch (MyExceprionFile ErrFile) {
		ErrFile.what();			//����� ������
		exit(1);
	}
};

template <typename T>
void MYFILE<T>::fileClose() {		//�������� �����
	try {
		if (mode == 'r') {
			_inFile.close();
		}
		if (mode == 'w' || mode == 'a') {
			_outFile.close();				//�������� ������
		}
		if (_outFile.is_open() && _inFile.is_open()) {
			throw MyExceprionFile(101, "������ �������� �����");			//����������
		}
	}
	catch (MyExceprionFile ErrFile) {
		ErrFile.what();			//����� ������
	}
};

template <typename T>
void MYFILE<T>::fileWrite(T& inform) {			//������
	try {
		if (mode=='r')
			throw MyExceprionFile(-100, "�������� �����");		//����������
		_outFile << inform;			//������ �������
		_outFile << endl;
	}
	catch (MyExceprionFile ErrFile) {
		ErrFile.what();
	}
};

template <typename T>
void MYFILE<T>::fileRead(T& inform) {			//������
	try {
		if (mode=='w')
			throw MyExceprionFile(-100, "�������� �����");		//����������
		_inFile >> inform;		//������ �����
	}
	catch (MyExceprionFile ErrFile) {
		ErrFile.what();
	}
};

template <typename T>
void MYFILE<T>::remote() {			//���������� � ������
	if (_outFile.is_open())
		_outFile.seekp(0, ios::beg);			//�������� � ������
};

template <typename T>
bool MYFILE<T>::isEnd() {			//����� �����
	if (_inFile.eof() && _inFile.is_open() || _outFile.eof() && _outFile.is_open())
		return true;			//�� �����
	else
		return false;		//��� 
}

