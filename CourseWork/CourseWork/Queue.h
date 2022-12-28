#pragma once
#include <iostream>
#include <iomanip>
#include "Node.h"

#include "MyException.h"
using namespace std;

template <typename T>
class queue {				//очередь

	nodeQ<T>* head;		//указатель на голову
	nodeQ<T>* tail;		//на хвост
	int size;		//кол-во элементов

public:
	queue() {			//по умолчанию
		head = tail = nullptr;
		size = 0;
	}

	queue(T* arr, int count) {			//с параметрами
		head = tail = nullptr;
		for (int i = 0; i < count; i++)
			put(arr[i]);			//добавление элемента
		size = count;
	}

	queue(const queue<T>& other) {				//копирования
		//cout << "КОНСТР" << endl;
		this->size = 0;
		head = tail = nullptr;
		nodeQ<T>* tmp = other.head;
		while (tmp) {
			this->put(tmp->inform);
			tmp = tmp->pr;				//копирование данных
		}

	}

	~queue() {				//деструктор
		if (!isEmpty()) {		//если не пусто
			do {
				del();				//удаление элементов
			} while (head && tail);				//пока не пусто
		}
		head = tail = nullptr;
	}

	void put(T& value);			//добавить в очередь

	void show();			//вывод очереди

	void del();				//удалить с головы
	void del(T del_value);			//удалить с сохранением элемента
	void del_any(queue<T> other);
	void clear();

	bool isEmpty();			//пуста ли очередь
	int getSize();			//количетсво элементов

	queue<T> operator=(const queue<T>& other);			//оператор =
	queue<T> operator+(const queue<T>& other);			//опертор +

	class Iterator {			//класс итератор
		nodeQ<T>* curNode;		//текущий
		nodeQ<T>* prevNode;		//предыдущий
	public:
		Iterator() {			//конструктор по умолчанию
			curNode = nullptr;
			prevNode = nullptr;
		}

		Iterator(nodeQ<T>* current, nodeQ<T>* prev = nullptr) {		//копирования
			this->curNode = current;
			this->prevNode = prev;
		}

		T& operator++(int value);		//оператор++
		T& operator--(int value);		//оператор--
		T& operator*();					//оператор *

		bool operator==(Iterator other);		//оператор ==
		bool operator!=(Iterator other);		//оператор !=
	};

	Iterator Begin();		//итератор на начало
	Iterator End();			//итератор на конец
};

template<typename T>
queue<T>::template Iterator queue<T>::Begin() {		//итератор на начало
	Iterator it(queue<T>::head);
	return it;
}

template<typename T>
queue<T>::template Iterator queue<T>::End() {			//итератор на конец
	Iterator iter(queue<T>::tail->pr, queue<T>::tail);		//итератор на след. за последним
	return iter;
}

template<typename T>
T& queue<T>::Iterator::operator++(int value) {		//оператор ++
	try {
		if (curNode) {
			prevNode = curNode;
			curNode = curNode->pr;			//итератор смещается в сторону хвсота
			return curNode->inform;
		}
		else
			throw MyException(-15, "Выход за пределы контейнера");
	}
	catch (MyException err) {
		err.what();
	}
}

template<typename T>
T& queue<T>::Iterator::operator--(int value) {		//оператор --
	try {
		if (curNode) {
			prevNode = prevNode->nx;
			curNode = curNode->nx;			//итератор вмещается в сторону головы
			return curNode->inform;
		}
		else
			throw MyException(-15, "Выход за пределы контейнера");
	}
	catch(MyException err) {
		err.what();
	}
}

template<typename T>
T& queue<T>::Iterator::operator*() {		//оператор *
	return curNode->inform;		//получание значения
}

template<typename T>
bool queue<T>::Iterator::operator==(Iterator other) {			//опреатор ==
	if (this->curNode != other.curNode || this->prevNode != other.prevNode)		//сравнение полей
		return false;
	return true;
}

template<typename T>
bool queue<T>::Iterator::operator!=(Iterator other) {		//оператор !=
	return !(*this == other);		
}