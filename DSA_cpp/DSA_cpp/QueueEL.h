/*
	Author: Eajack Lau
	Date: 2020.6.19
	Function:
		������ʵ��
*/

#pragma once
#include "ListEL.h"

class Queue
{
public:
	Queue();
	Queue(int val);
	~Queue();

	//1 �ж��Ƿ�գ�O(1)
	bool empty();
	//2 ��ȡ����size��O(1)
	int size();
	//3 β����ӣ�O(1)
	void enqueue(int x);
	//4 ͷ�����ӣ�O(1)
	int dequeue();
	//5 ��գ�O(N)
	void clear();
	//6 ��ӡ��O(N)
	void print();

private:
	// ͷβָ��ͬʱά��
	QueueNode * queueFront;
	QueueNode* queueBack;
};


