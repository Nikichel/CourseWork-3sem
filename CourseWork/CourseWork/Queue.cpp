#pragma once
#include "Queue.h"

template <typename T>
void queue<T>::put(T& value) {			//добавить элемент
	nodeQ<T>* newq = new nodeQ<T>;
	newq->inform = value;				//объ€вление нового элемента
	if (head && tail) {				//если очередь есть
		newq->nx = tail;
		tail->pr = newq;
		tail = newq;				//занести элемент в хвост
	}
	else {				//если очереди нет
		head = tail = newq;					//голова = хвост = элемент
	}
	this->size++;
}

template <typename T>
void queue<T>::show() {			//вывод на экран очереди с хвоста
	if (!isEmpty()) {
		nodeQ<T>* tmpq = tail;
		do {
			cout << tmpq->inform << endl;				//вывод информации
			tmpq = tmpq->nx;
		} while (tmpq);
	}
}

template <typename T>
void queue<T>::del() {				//удалить с головы
	if (!isEmpty()) {
		if (tail == head) {				//если 1 элемент
			delete head;				//удалить
			head = tail = nullptr;
		}
		else {
			nodeQ<T>* tmphead = head->pr;
			delete head;
			tmphead->nx = nullptr;
			head = tmphead;					//удалить голову и переместить на предыдущий за головой
		}
		size--;
	}
}

template <typename T>
void queue<T>::del(T del_value) {			//удалить по объекту
	nodeQ<T>* tmp = tail;
	if (!isEmpty()) {
		while (tmp) {
			if (tmp->inform == del_value) {
				if (tail == head) {				//если удал€ем голову=хвост
					delete head;
					head = tail = nullptr;
					tmp = nullptr;
					this->size--;
					break;
				}
				else if (tmp == tail) {			//удал€ем хвост
					tail = tail->nx;
					delete tmp;
					tail->pr = nullptr;
					tmp = tail;
				}
				else if (tmp == head) {			//удал€ем голову
					head = head->pr;
					delete tmp;
					head->nx = nullptr;
					tmp = head;
				}
				else {							//удал€ем другой элемент
					nodeQ<T>* tmpdel = tmp;
					tmp->pr->nx = tmp->nx;
					tmp->nx->pr = tmp->pr;
					tmp = tmp->nx;
					delete tmpdel;
				}
				this->size--;
			}
			tmp = tmp->nx;
		}
	}
}

template <typename T>
void queue<T>::del_any(queue<T> other) {
	nodeQ<T>* tmp = tail;
	nodeQ<T>* del = other.tail;
	for (del; del; del = del->nx) {			//цикл по элементам очереди которые нужно удалить
		for (tmp = this->tail; tmp; tmp = tmp->nx) {			//цикл по основной очереди
			if (tmp->inform == del->inform) {
				if (tail == head) {				//если удал€ем голову=хвост
					delete head;
					head = tail = nullptr;
					tmp = nullptr;
					this->size--;
					break;
				}
				else if (tmp == tail) {			//удал€ем хвост
					tail = tail->nx;
					delete tmp;
					tail->pr = nullptr;
					tmp = tail;
				}
				else if (tmp == head) {			//удал€ем голову
					head = head->pr;
					delete tmp;
					head->nx = nullptr;
					tmp = head;
				}
				else {							//удал€ем другой элемент
					nodeQ<T>* tmpdel = tmp;
					tmp->pr->nx = tmp->nx;
					tmp->nx->pr = tmp->pr;
					tmp = tmp->nx;
					delete tmpdel;
				}
				this->size--;			//уменьшаем размер
			}
		}
	}
}

template <typename T>
void queue<T>::clear() {
	if (!isEmpty()) {		//если не пусто
		do {
			del();				//удаление элементов
		} while (head && tail);				//пока не пусто
	}
	head = tail = nullptr;
}

template <typename T>
bool queue<T>::isEmpty() {			//пуста ли очередь
	if (size)
		return false;
	return true;
}

template <typename T>
int queue<T>::getSize() {
	return this->size;
};

template <typename T>
queue<T> queue<T>::operator=(const queue<T>& other) {					//опретор =
	while (this->size) {
		this->del();			//удаление старой информации
	}
	nodeQ<T>* tmp = other.head;
	while (tmp) {
		this->put(tmp->inform);
		tmp = tmp->pr;				//занесение в очередь элементов 
	}
	return *this;
}

template <typename T>
queue<T> queue<T>::operator+(const queue<T>& other) {				//оператор +
	nodeQ<T>* tmp = other.head;
	while (tmp) {
		this->put(tmp->inform);
		tmp = tmp->pr;				//занемение элементов в очередь
	}
	return *this;
}
