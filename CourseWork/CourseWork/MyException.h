#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class MyException {
protected:
	int code;		//код
	char message[80];		//ошибка
public:
	MyException() {		//умолчанию
		code = 0;
		message[0] = '\0';
	}

	MyException(int code, const char* message) {		//с параметрами
		this->code = code;
		strcpy_s(this->message, 80, message);
	}
		
	MyException(const MyException& other){		//копирования
		this->code = other.code;
		strcpy_s(this->message, 80, other.message);
	}

	~MyException() {}

	virtual void what() {			//вывод ошибки
		cout << "Код ошибки: " << code << endl;			//код
		cout << "Пояснение: " << message << endl;			//сообщение
	};
};