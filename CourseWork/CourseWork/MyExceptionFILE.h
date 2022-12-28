#pragma once
#include "MyException.h"
class MyExceptionFILE : public MyException {			//ошибка файла
protected:
	char message2[80];		//2 сообщение пояснение
public:
	MyExceptionFILE() : MyException() {
		message2[0] = '\0';
	}

	MyExceptionFILE(int code, const char* message ,const char* message2) : MyException(code, message) {			//с параметрами
		strcpy_s(this->message2, 80, message2);
	}

	MyExceptionFILE(const MyExceptionFILE& other) : MyException(other) {			//копирования
		strcpy_s(message2, 80, other.message2);
	}
	~MyExceptionFILE() {}

	void what() override {		//вывод ошибки
		cout << "Код ошибки: " << code << endl;
		cout << "Пояснение: " << message << endl;
		cout << message2 << endl;					//вывод ошибки
	}

};

