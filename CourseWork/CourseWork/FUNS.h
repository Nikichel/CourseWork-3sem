#pragma once
#include "MyExceprionFile.h"
#include "MyExceptionNUM.h"
#include "MyExceptionSTR.h"

#include "MyFile.cpp"
#include "Queue.cpp"

using namespace std;

template <typename T>
inline void getNum(T& value) {			//проверка ввода чила
	bool fl = true;
	do {
		fl = true;
		try {
			cin >> value;			//вводи число
			cin.ignore(80, '\n');		//считываем неформальный ввод
			if (cin.fail())		//если ввели символ
				throw MyExceptionNUM(1, "Введенно не число", "Возможно вы ввели число с стронними символами");
			else if (cin.gcount() > 1)			//если ввели число и символы ( напр.: 423ывпф)
				throw MyExceptionNUM(2, "В записи числа присутсвуют сторонние символы", "Исключите символы при записи числа");
		}
		catch (MyExceptionNUM errNUM) {
			errNUM.what();
			cin.clear();			//вывод ошибки и чистка
			rewind(stdin);
			fl = false;
		}
	} while (!fl);
}

template < typename T1, typename T2, typename T3 >
inline void getNumWithBorders(T1& value, T2 FirstBorder, T3 SecondBorder) {			//ввод числа в границах
	double tmp;
	bool fl = true;
	do {
		fl = true;
		try {
			getNum(tmp);			//ввод числа с проверкой
			value = static_cast<T1> (tmp);
			if (tmp < FirstBorder || tmp > SecondBorder)			//выход за границы
				throw MyExceptionNUM(1, "Выход за границы", "Вы вышли за диапазон возможный значений числа");
			if (value - tmp)			//если ввели double когда нужно int
				throw MyExceptionNUM(-1, "Ожидался ввод целого типа", "Вы ввели число с плавующей запятой");
		}
		catch (MyExceptionNUM errNUM) {
			errNUM.what();
			cin.clear();			//вывод ошибки и чистка
			rewind(stdin);
			fl = false;
		}
	} while (!fl);
}


template <typename T>
inline void getPositivNum(T& value) {			//ввод положительного числа
	bool fl = true;
	do {
		fl = true;
		try {
			getNum(value);			//ввод и проверка числа
			if (value <= 0)					//если отрицательное
				throw MyExceptionNUM(3, "Введенно не положительное число", "Введите число >0");
		}
		catch (MyExceptionNUM errNum) {
			errNum.what();
			rewind(stdin);			//вывод ошибки + чистка
			fl = false;
		}

	} while (!fl);
}

inline void getStr(const char* language, char* str, int lenStr) {		//ввод строки на разном языке
	rewind(stdin);
	bool fl = true;
	int i = 0;
	do {
		fl = true;
		try {
			cin.getline(str, lenStr);
			if(!strlen(str))
				throw MyException(-10, "Пустая строка!");
			while (str[i] != '\0') {
				if (!strcmp(language, "RU"))			//ру строка
					if ((str[i] > 'я' || str[i] < 'А') && str[i] != ' ')
						throw MyExceptionSTR(10, "Некорректный русский ввод", str[i], i);		//если не русский символ
				if (!strcmp(language, "ENG"))			//англ строка
					if ((str[i] < 'A' || str[i]> 'Z' && str[i] < 'a' || str[i]>'z') && str[i] != ' ')
						throw MyExceptionSTR(11, "Некорректный english ввод", str[i], i);		//если не англ символ
				i++;
			}
		}
		catch (MyExceptionSTR errStr) {
			errStr.what();		//вывод ошибки чистка
			rewind(stdin);
			i = 0;
			fl = false;
		}
		catch (MyException errStr) {
			errStr.what();		//вывод ошибки чистка
			rewind(stdin);
			i = 0;
			fl = false;
		}
	} while (!fl);
}

inline void getDate(int& dd, int& mm, int& yyyy) {				//ввод даты
	cout << "Год:";
	getPositivNum(yyyy);		//положит. число
	cout << "Месяц: ";
	getNumWithBorders(mm, 1, 12);			//ввод месяца
	cout << "День:";
	if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
		getNumWithBorders(dd, 1, 31);
	else if (mm == 2 && yyyy % 4 == 0)
		getNumWithBorders(dd, 1, 29);
	else if (mm == 2)
		getNumWithBorders(dd, 1, 28);
	else
		getNumWithBorders(dd, 1, 30);			//ввод дня
}

template <typename T>
inline void saveInFile(queue<T>& q) {			//записать в файл
	char fileName[40];
	strcpy_s(fileName, 40, typeid(T).name());
	strcat_s(fileName, ".txt");						//файл записать
	MYFILE<T> File(fileName);
	File.fileOpen('w');
	if (!q.isEmpty())
		for (queue<T>::template Iterator it = q.Begin(); it != q.End(); it++) {
			File.fileWrite(*it);
		}
	File.fileClose();
}

template <typename T>
inline void loadFromFile(queue<T>& q) {			//загрузка из файла
	char fileName[40];
	strcpy_s(fileName, 40, typeid(T).name());
	strcat_s(fileName, ".txt");				//файл чтения
	MYFILE<T> File(fileName);
	File.fileOpen('r');
	T obj;
	while (1) {
		File.fileRead(obj);			//чтение
		if (File.isEnd())
			break;
		q.put(obj);		//в очередь
	}
	File.fileClose();
}