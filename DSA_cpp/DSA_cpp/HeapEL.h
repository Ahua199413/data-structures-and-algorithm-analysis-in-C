/*
	Author: Eajack Lau
	Date: 2020/6/22
	Function:
	�ѣ����ȶ���,PriorityQueue,PQ��
		1- ����ѡ������ѡ�������ʵ�֡���ӦC++��׼������ȶ���Priority Queue
		2- ��ʽ�ѡ����ڶ���ѣ���С/���ѣ�����ʵ�֡�����������ӵ�Npl���ڵ����Һ��ӵ�Npl
			����ѣ�����ƽ����
*/

#pragma once

#include <vector>
#include <algorithm>


//1 �����
enum HEAP_TYPE {
	MAX=INT_MAX,
	MIN=INT_MIN
};

struct HeapBinary
{
	// heapArray���鳤��/����Ϊ��capacity + 1���������Ѷ�heapArray[0]
	int capacity;
	// size����Ŀǰ��������Ԫ�ظ���
	int size;
	// heapArray[0]Ĭ��ΪINT_MIN����С�ѣ�,���������������flag������С/���
	int *heapArray;

	//
	HeapBinary(enum HEAP_TYPE flag = MIN) :capacity(1), size(0) {
		heapArray = new int[1];
		heapArray[0] = flag;
	}
	HeapBinary(int capacity, enum HEAP_TYPE flag = MIN) :capacity(capacity), size(0) {
		heapArray = new int[capacity];
		heapArray[0] = flag;
	}
	HeapBinary(int capacity, int size, enum HEAP_TYPE flag = MIN) :capacity(capacity), size(size) {
		heapArray = new int[capacity];
		heapArray[0] = flag;
	}
};

class Heap
{
public:
	Heap();
	Heap(std::vector<int> vals, enum HEAP_TYPE flag=MIN);
	~Heap();

	//1 ��ӣ�������1��ֵ��O(logN)
	void enqueue(int val);
	//2 ���ӣ���ɾ���Ѷ��������µ����ѣ�O(logN)
	int dequeue();
	//3 ��ȡ��O(1)
	int getSize();
	int getHeapTop();
	//4 ��գ�O(1)
	void clear();
	//5 �����Ӧ��1��������/��ȡTopK��ֵ��O(NlogN)
	std::vector<int> heapSort();

private:
	HeapBinary * heap;
};

//2 ��ʽ�ѣ�ֻʵ����С�Ѱ汾
struct TreeNodeHeapLeft
{
	int val;
	TreeNodeHeapLeft* left;
	TreeNodeHeapLeft* right;
	//��ʽ�����ڵ���������Npl
	//	Npl�� null path length ����д��
	//	ָ���ǴӸý�㵽��һ��û���������ӵĽ�����̾��루һ�����ӵĽ�����Ҷ�ӣ���
	//	һ�㶨��NULL��NplΪ-1��ʹ������
	int Npl;

	TreeNodeHeapLeft() :val(0), left(nullptr), right(nullptr), Npl(-1) {};
	TreeNodeHeapLeft(int val) :val(val), left(nullptr), right(nullptr), Npl(0) {};
};

class HeapLeft
{
public:
	HeapLeft();
	HeapLeft(std::vector<int> vals);
	~HeapLeft();

	//1 merge�ϲ���O(logN)
	TreeNodeHeapLeft* merge(TreeNodeHeapLeft* h1, TreeNodeHeapLeft* h2);
	//2 ��ӣ�������1��ֵ��O(logN)
	void enqueue(int val);
	//3 ���ӣ���ɾ���Ѷ��������µ����ѣ�O(logN)
	int dequeue();
	//3 ��ȡ��O(1)
	int getHeapTop();
private:
	TreeNodeHeapLeft * root;
};
