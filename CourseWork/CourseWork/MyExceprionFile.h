#pragma once
#include "MyException.h"
class MyExceprionFile :
    public MyException
{
protected:

public:
	MyExceprionFile() : MyException() {}

	MyExceprionFile(int code, const char* message) : MyException(code, message) {}

	MyExceprionFile(const MyExceprionFile& other) : MyException(other) {}
	~MyExceprionFile() {}

	void what() override {
		cout << "��� ������: " << code << endl;
		cout << "���������: " << message << endl;
	}

};

