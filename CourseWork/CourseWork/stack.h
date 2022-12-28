#pragma once
#include <iostream>
#include <iomanip>
#include "Node.h"

template <typename T>
class stack             //����
{
private:
    nodeS<T>* Top;      //��������� �� ������� �����
    int size;
public:
    stack() {           //����������� �� ���������    
        Top = nullptr;
        size = 0;
    }

    ~stack() {          //����������
        if (!isEmpty()) {		//���� �� �����
            do {
                Pop();				//�������� ���������
            } while (Top);				//���� �� �����
        }
        Top = nullptr;
    }

    int getSize();          //�������� ���-�� ��������� � �����
    void Push(T& obj);      //�������� �������
    void Pop(T& obj);       //������� � ��������� ��������
    void Pop();             //�������
    bool isEmpty();         //�����?
 };

template <typename T>
int stack<T>::getSize() {       //�������� ���-�� ���������
    return size;
};

template <typename T>
bool stack<T>::isEmpty() {      //�����?
    if (size)
        return false;
    return true;
}

template <typename T>
void stack<T>::Push(T& value) {         //�������� �������
    nodeS<T>* newNode = new nodeS<T>;
    newNode->inform = value;
    if (!Top) {             //���� ���� ������
        Top = newNode;      
    }
    else {
        newNode->nx = Top;          //������� � �������
        Top = newNode;
    }
    size++;

};

template <typename T>
void stack<T>::Pop(T& value) {          //������� � ���������
    if (!isEmpty()) {           //�� ������
        value = Top->inform;        //���������� ��������
        nodeS<T>* delNode = Top;        
        if (Top->nx)
            Top = Top->nx;      
        delete delNode;         //������� ����
        size--;
        if (!size)
            Top = nullptr;      //���� ����� ������� ������ ����
    }
};


template <typename T>
void stack<T>::Pop() {          //������� �������
    if (!isEmpty()) {
        nodeS<T>* delNode = Top;
        if (Top->nx)
            Top = Top->nx;
        delete delNode;         //������� ����
        size--;
        if (!size)
            Top = nullptr;      //���� ����� ������� ������ ����
    }
}