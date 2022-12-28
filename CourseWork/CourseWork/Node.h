#pragma once

template <typename T>
struct nodeQ {		//���� �������
	T inform;		//����������
	nodeQ* nx;		//��������� �� ���������
	nodeQ* pr;		//��������� �� ���������� �������

	nodeQ() {
		nx = pr = nullptr;
	}

	~nodeQ() {};
};

template <typename T>
struct nodeS		//���� �����
{
	T inform;		//������� �����
	nodeS* nx;		//��������� �� ��������� �������

	nodeS() {
		nx = nullptr;
	}

	~nodeS() {};
};
