#pragma once
#include <iostream>
#include <iomanip>
#include "Node.h"

template <typename T>
class stack             //стек
{
private:
    nodeS<T>* Top;      //Указатель на вершину стека
    int size;
public:
    stack() {           //конструктор по умолчанию    
        Top = nullptr;
        size = 0;
    }

    ~stack() {          //деструктор
        if (!isEmpty()) {		//если не пусто
            do {
                Pop();				//удаление элементов
            } while (Top);				//пока не пусто
        }
        Top = nullptr;
    }

    int getSize();          //получить кол-во элементов в стеке
    void Push(T& obj);      //добавить элемент
    void Pop(T& obj);       //удалить с возвратом значения
    void Pop();             //удалить
    bool isEmpty();         //пусто?
 };

template <typename T>
int stack<T>::getSize() {       //получить кол-во элементов
    return size;
};

template <typename T>
bool stack<T>::isEmpty() {      //пусто?
    if (size)
        return false;
    return true;
}

template <typename T>
void stack<T>::Push(T& value) {         //добавить элемент
    nodeS<T>* newNode = new nodeS<T>;
    newNode->inform = value;
    if (!Top) {             //если стек пустой
        Top = newNode;      
    }
    else {
        newNode->nx = Top;          //заносим в вершину
        Top = newNode;
    }
    size++;

};

template <typename T>
void stack<T>::Pop(T& value) {          //удалить с возвратом
    if (!isEmpty()) {           //не пустой
        value = Top->inform;        //запоминаем значение
        nodeS<T>* delNode = Top;        
        if (Top->nx)
            Top = Top->nx;      
        delete delNode;         //удаляем узел
        size--;
        if (!size)
            Top = nullptr;      //если после удалени пустой стек
    }
};


template <typename T>
void stack<T>::Pop() {          //удалить элемент
    if (!isEmpty()) {
        nodeS<T>* delNode = Top;
        if (Top->nx)
            Top = Top->nx;
        delete delNode;         //удаляем узел
        size--;
        if (!size)
            Top = nullptr;      //если после удалени пустой стек
    }
}