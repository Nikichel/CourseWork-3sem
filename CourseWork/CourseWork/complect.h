#pragma once
#include "Queue.cpp"
#include "place.h"

template <typename T>
struct complect {
	char nameSector;		//название сектора
	int count;			//количетсво мест
	place* places;		//массив мест
	queue<T> q;			//очередь транспорта
public:
	complect(char nameSector, int count, place* places, queue<T>& q) {		//с параметрами
		this->count = count;
		this->places = new place[count];
		for (int i = 0; i < count; i++) {
			this->places[i] = places[i];
		}
		this->nameSector = nameSector;
		this->q = q;
	}

	complect(complect& other) {				//копирования
		this->nameSector = other.nameSector;
		this->count = other.count;
		this->q = other.q;
		for (int i = 0; i < count; i++)
			this->places[i] = other.places[i];
	}

	queue<T>& getQueue() {		//получить очередь
		return q;
	}

	place* getPLaces() {		//получить места
		return places;
	}

	int getCount() {			//получить кол-во мест
		return count;
	}

	~complect() {				//деструктор
		delete[] places;
	}
};