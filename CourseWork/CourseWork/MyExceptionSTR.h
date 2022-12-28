#pragma once
#include "MyException.h"

class MyExceptionSTR : public MyException {
protected:
	char errorSym;
	int poz;
public:
	MyExceptionSTR() : MyException() {
		errorSym = '\0';
		poz = 0;
	}

	MyExceptionSTR(int code, const char* message, const char errorSym,int poz) : MyException(code, message) {
		this->errorSym=errorSym;
		this->poz = poz;
	}

	MyExceptionSTR(const MyExceptionSTR& other) : MyException(other) {
		this->errorSym = other.errorSym;
		this->poz = other.poz;
	}

	~MyExceptionSTR() {}

	void what() override {
		cout << "Код ошибки: " << code << endl;
		cout << "Пояснение: " << message << endl;
		cout << "Ошибочный символ: " << errorSym<<endl;
		cout << "Позиция: " << poz << endl;
	};
};