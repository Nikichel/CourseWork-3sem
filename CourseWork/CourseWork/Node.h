#pragma once

template <typename T>
struct nodeQ {		//узел очереди
	T inform;		//информация
	nodeQ* nx;		//указатель на следующий
	nodeQ* pr;		//указатель на предыдущий элемент

	nodeQ() {
		nx = pr = nullptr;
	}

	~nodeQ() {};
};

template <typename T>
struct nodeS		//узел стека
{
	T inform;		//элемент стека
	nodeS* nx;		//указатель на следующий элемент

	nodeS() {
		nx = nullptr;
	}

	~nodeS() {};
};
