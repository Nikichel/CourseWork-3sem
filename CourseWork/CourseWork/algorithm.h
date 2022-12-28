#pragma once
#include "Queue.cpp"
#include "Queue.h"
template <typename T>
class algorithm		//класс алгоритмов
{
public:

	void sortAscendingOrder(queue<T>::template Iterator itBeg, queue<T>::template Iterator itEnd) {		//сортировка по возрастанию
		T objMin, objJ;			//объект min и j иттераторов
		objMin= objJ = (*itBeg).ChooseParams();		//выбор параметра
		queue<T>::template Iterator min;			//итератор на минимальный элемент
		queue<T>::template Iterator j;				//итератор от itBeg до конца
		do
		{
			min = itBeg;
			j = itBeg;		
			do
			{
				objMin.replace(*min);		
				objJ.replace(*j);			//замещаем на новые параметры
				if (objJ > objMin)		//сравниваем
					min = j;			
				j++;
			} while (j != itEnd);		//пока не конец
			if (min != itBeg)
			{
				T tmp = *min;		
				*min = *itBeg;
				*itBeg = tmp;			//меняем местами
			}
			itBeg++;
		} while (itBeg != itEnd);		//пока не конец
	};

	void sortDescendingOrder(queue<T>::template Iterator itBeg, queue<T>::template Iterator itEnd) {		//сортировка по	убыванию
		T objMin, objJ;			//объект min и j иттераторов
		objMin = objJ = (*itBeg).ChooseParams();		//выбор параметра
		queue<T>::template Iterator min;			//итератор на минимальный элемент
		queue<T>::template Iterator j;				//итератор от itBeg до конца
		do
		{
			min = itBeg;
			j = itBeg;
			do
			{
				objMin.replace(*min);
				objJ.replace(*j);			//замещаем на новые параметры
				if (objMin > objJ)		//сравниваем
					min = j;
				j++;
			} while (j != itEnd);		//пока не конец
			if (min != itBeg)
			{
				T tmp = *min;
				*min = *itBeg;
				*itBeg = tmp;			//меняем местами
			}
			itBeg++;
		} while (itBeg != itEnd);		//пока не конец
	};


	template <typename T>
	queue<T>::template Iterator searchObj(queue<T>::template Iterator itBeg, queue<T>::template Iterator itEnd,T obj) {					//поиск элемента
		for (; itBeg != itEnd; itBeg++) {		//пока не конец
			if (*itBeg == obj)		//нашли объект
				return itBeg;
		}
		return itBeg;
	}

	template <typename T>
	queue<T> searchQueue(queue<T>::template Iterator itBeg, queue<T>::template Iterator itEnd, T obj) {		//поиск очереди
		queue<T> find;
		do {
			itBeg = searchObj(itBeg, itEnd, obj);		//поиск элемента
			if (itBeg != itEnd) {
				find.put(*itBeg);		//занесение в очереди
				itBeg++;
			}
		} while (itBeg != itEnd);
		return find;
	}
};

