/*
	Author: Eajack Lau
	Date: 2020.6.19
	Function:
		������ʵ��
*/

#pragma once

struct SingleListNode
{
	int val;
	SingleListNode* next;
	SingleListNode(int val) : val(val), next(nullptr) {};
	SingleListNode() : val(0), next(nullptr) {};
};
typedef struct SingleListNode StackNode;
typedef struct SingleListNode QueueNode;
typedef struct SingleListNode HashNode1;

class SingleList
{
private:
	SingleListNode * head = nullptr;
public:
	SingleList(int val);
	SingleList();
	~SingleList();

	//1 ��ʼ������O(N)
	void produceList(const int A[], int size);
	//2 ��ȡ�����ȣ�O(N)
	int size();
	//3 ���ң�O(N)
	bool find(int x);
	//4 ɾ����index����0��ʼ����O(N)
	void delete_withIndex(int index);
	//5 ���루index����0��ʼ����O(N)
	void insert_x_beforeIndex(int x, int index);
	//6 �������O(N)
	void clear();
	//7 ��ӡ����O(N)
	void print();
};