#pragma once
#include "MyException.h"

class MyExceptionNUM : public MyException {
protected:
	char message2[80];
public:
	MyExceptionNUM() : MyException() {			//по умолчанию
		message2[0] = '\0';
	}

	MyExceptionNUM(int code, const char* message, const char* message2) : MyException(code, message) {			//с параметрами
		strcpy_s(this->message2, 80, message2);
	}
	MyExceptionNUM(const MyExceptionNUM& other) : MyException (other) {				//копирования
		strcpy_s(message2, 80, other.message2);
	}

	~MyExceptionNUM() {}

	void what() override {
		cout << "Код ошибки: " << code << endl;
		cout << "Пояснение: " << message << endl;
		cout << message2 << endl;				//вывод ошибки
	};
};