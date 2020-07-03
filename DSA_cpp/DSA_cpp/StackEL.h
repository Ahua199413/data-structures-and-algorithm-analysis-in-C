/*
	Author: Eajack Lau
	Date: 2020.6.19
	Function:
		ջ��ʵ��
*/

#pragma once

#include "ListEL.h"

class Stack
{
public:
	Stack();
	Stack(int val);
	~Stack();

	//1- ��ȡsize��O(1)
	int size();
	//2- �жϿգ�O(1)
	bool empty();
	//3- push��O(1)
	void push(int x);
	//4- pop��O(N)
	void pop();
	//5- top��O(N)
	int top();
	//6- ��գ�O(N)
	void clear();
	//7- ��ӡ��O(N)
	void print();

private:
	StackNode * stackBottom;
	StackNode * stackTop;
};