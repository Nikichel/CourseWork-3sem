#pragma once
#include "human.h"
#include "date.h"
#include "access.h"
#include "windows.h"

class employee : public human {		//класс работника
	date startHoliday;		//начало отпуска
	date endHoliday;		//конец отпуска
	int salary;				//зарплата
	char jobTitle[15];		//Должность
	access _access;			//пароль и логин
public:

	employee() : human() {			//конструктор по умолчанию
		salary = 0;
		strcpy_s(jobTitle,15, "-");
	};

	employee(employee& other) : human(other) {			//конструктор копирование
		strcpy_s(this->jobTitle, 15, other.jobTitle);
		this->startHoliday = other.startHoliday;
		this->endHoliday = other.endHoliday;
		this->salary = other.salary;
		this->_access = other._access;
	};

	~employee() {};		//деструктор

	void setSalary(int salary);					//установить зарплату
	void setJobTitle(const char* jobTitle);		//установить должность
	void setAccess(access& otherAccess);		//установить пароль и логин

	int getSalary();			//получить зарплату
	char* getJobTitle();		//получить должность
	access getAccess();			//получить пароль и логин

	void filter();		//фильтр поиска
	void change();		//меню изменения полей

	bool isNull();		//нулевой ли класс
	void start(queue<employee>& q);			//загрузка работника
	void registration();	//регистрация
	void authorization();	//авторизация
	void greeting();		//приветсвие

	void tableHead() override;				//шапка таблицы
	void replace(const employee& other);	//замещение не нулевых полей
	employee ChooseParams();				//выбор поля для сортировки 

	employee operator=(const employee& other);		//оператор =
	bool operator==(employee& other);				//оператор ==
	bool operator>(employee& other);				//оператор >

	friend istream& operator>>(istream& in, employee& other);			//ввод
	friend ostream& operator<<(ostream& out, employee& other);			//вывод
	friend ofstream& operator<<(ofstream& outf, employee& other);		//запись в файл
	friend ifstream& operator>>(ifstream& inf, employee& other);		//чтение из файла
};