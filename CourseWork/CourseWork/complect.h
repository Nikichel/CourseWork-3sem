#pragma once
#include "Queue.cpp"
#include "place.h"

template <typename T>
struct complect {
	char nameSector;		//�������� �������
	int count;			//���������� ����
	place* places;		//������ ����
	queue<T> q;			//������� ����������
public:
	complect(char nameSector, int count, place* places, queue<T>& q) {		//� �����������
		this->count = count;
		this->places = new place[count];
		for (int i = 0; i < count; i++) {
			this->places[i] = places[i];
		}
		this->nameSector = nameSector;
		this->q = q;
	}

	complect(complect& other) {				//�����������
		this->nameSector = other.nameSector;
		this->count = other.count;
		this->q = other.q;
		for (int i = 0; i < count; i++)
			this->places[i] = other.places[i];
	}

	queue<T>& getQueue() {		//�������� �������
		return q;
	}

	place* getPLaces() {		//�������� �����
		return places;
	}

	int getCount() {			//�������� ���-�� ����
		return count;
	}

	~complect() {				//����������
		delete[] places;
	}
};