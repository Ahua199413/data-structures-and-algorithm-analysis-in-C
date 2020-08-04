/*
	Author: Eajack Lau
	Date: 2020/6/22
	Function:
	�ѣ����ȶ���,PriorityQueue,PQ��
		1- ����ѣ������ѡ�������ʵ�֡���С�ѣ���С�´�/���ѣ��ϴ���С
		2- б��
		3- ��ʽ��
*/

#include "HeapEL.h"
using namespace std;

//1 �����
Heap::Heap()
{
	heap = new HeapBinary();
}

// ���ѣ�O(NlogN)
Heap::Heap(std::vector<int> vals, HEAP_TYPE flag)
{
	//1
	int _capacity = 2 * vals.size();
	heap = new HeapBinary(_capacity, 0, flag);
	//2
	for (int v : vals) {
		enqueue(v);
	}
}

Heap::~Heap()
{
}

// ��ӣ�������1��ֵ��O(logN)
void Heap::enqueue(int val)
{
	if (heap->size == heap->capacity) {
		return;
	}

	//key code
	int i = (++heap->size);
	if (heap->heapArray[0] == INT_MIN) {
		//��С�ѣ���С�´� => h->heapArray[i/2] > val
		for (; heap->heapArray[i / 2] > val; i /= 2)	// ++size;
		{
			heap->heapArray[i] = heap->heapArray[i / 2];
		}
	}
	else {
		//���ѣ��ϴ���С => h->heap_array[i/2] < val; 
		for (; heap->heapArray[i / 2] < val; i /= 2)	// ++size;
		{
			heap->heapArray[i] = heap->heapArray[i / 2];
		}
	}
	heap->heapArray[i] = val;
}

// ���ӣ���ɾ���Ѷ��������µ����ѣ�O(logN)
int Heap::dequeue()
{
	if (heap->size == 0) {
		return INT_MIN;
	}

	int i, child;
	int minValue = heap->heapArray[1];
	int lastValue = heap->heapArray[heap->size--];//size--, delete 1 value

	for (i = 1; i * 2 <= heap->size; i = child) {
		//�ҵ���һ��ڵ���С��ֵ
		child = i * 2;
		if (child != heap->size && heap->heapArray[child + 1] < heap->heapArray[child]) {
			child++;
		}

		//����
		if (lastValue > heap->heapArray[child]) {
			heap->heapArray[i] = heap->heapArray[child];
		}
		else {
			break;
		}
	}
	heap->heapArray[i] = lastValue;

	return minValue;
}


int Heap::getSize()
{
	if (!heap) {
		return 0;
	}
	return heap->size;
}

int Heap::getHeapTop()
{
	if (!heap) {
		return 0;
	}
	return heap->heapArray[1];
}

void Heap::clear()
{
	if (!heap) {
		heap->capacity = 0;
		heap->size = 0;
		int* temp = heap->heapArray;
		delete temp;
		heap->heapArray = nullptr;
	}
}

// ������O(NlogN)
//	��С�� => �������� => ����
vector<int> Heap::heapSort()
{
	vector<int> ans;
	while (getSize() > 0) {
		ans.push_back(dequeue());
	}
	return ans;
}

HeapLeft::HeapLeft()
{
	root = new TreeNodeHeapLeft();
}

HeapLeft::HeapLeft(vector<int> vals)
{
	if (vals.empty()) {
		HeapLeft();
	}

	//1
	root = new TreeNodeHeapLeft(vals[0]);
	for (int v : vals) {
		enqueue(v);
	}
}

HeapLeft::~HeapLeft()
{
}

// ��ʽ�ѻ���������merge
//	Step1��������������Ѷ��ǿյģ�����նѣ�����һ�����ǿյģ��򷵻طǿյĶ�
//	Step2���������ѷǿ�ʱ���Ƚ��������ڵ�Ĵ�С����h1Ϊ���ڵ�ֵ��С�Ķѣ�����Ϊ��
//		�Ѹ��ڵ㣺h1���ڵ�
//		��������h1->left
//		��������merge(h1->right, h2)
//	Step3���жϸ��ڵ�ġ���ڵ�Npl�� < ���ҽڵ�Npl�������ǣ��򻥻�
TreeNodeHeapLeft * HeapLeft::merge(TreeNodeHeapLeft * h1, TreeNodeHeapLeft * h2)
{
	//Step 1
	if (!h1) {
		return h2;
	}
	if (!h2) {
		return h1;
	}

	//Step 2
	if (h1->val > h2->val) {
		swap(h1, h2);
	}
	//h1ֻ��������
	if (h1->left == NULL) {
		h1->left = h2;
	}
	else {
		//��������merge(h1->right, h2)
		h1->right = merge(h1->right, h2);

		//step 3
		if (h1->left->Npl < h1->right->Npl) {
			TreeNodeHeapLeft* left_buffer = h1->left;
			h1->left = h1->right;
			h1->right = left_buffer;
		}
		h1->Npl = h1->right->Npl + 1;
	}
	return h1;
}


void HeapLeft::enqueue(int val)
{
	//1
	if (!root) {
		root = new TreeNodeHeapLeft(val);
		return;
	}

	//2
	TreeNodeHeapLeft* node = new TreeNodeHeapLeft(val);
	root = merge(node, root);
}

int HeapLeft::dequeue()
{
	if (!root) {
		return INT_MIN;
	}

	int ans = root->val;
	TreeNodeHeapLeft *left = root->left, *right = root->right;
	delete root;
	root = merge(left, right);
}

int HeapLeft::getHeapTop()
{
	return root->val;
}
