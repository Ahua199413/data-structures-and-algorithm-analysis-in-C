#pragma once

struct ListNode;

class ListEL
{
private:
	ListNode* head;
public:
	ListEL() {
		head = nullptr;
	}
	~ListEL() {
		delete_L();
	}

	//���ܺ���
	//�ع����ޱ�ͷ��
	//1- ���ɵ�����,�ֳƳ�ʼ����O(N)
	void produceList(const int A[], int N);
	//2- �ж�L�Ƿ�Ϊ�յ�����O(1)
	bool isEmptyList() { return head == nullptr; };
	//3- ������������ֵ����ͷ����Ϊ0��O(N)
	int find_index(int index);
	//4- ��������ɾ���ڵ㣬��ͷ����Ϊ0��O(N)
	void delete_index(int index);
	//5- ��ȡ�����ȡ�O(N)
	int getListLength();
	//6- �ڵ�����L�У�����valֵǰһ�ڵ�λ�ã����Ա�������һ�������Ľڵ㣩��O(N)
	ListNode * findPrevious(int val);
	//7- �ڵ�����L�У�ɾ��xֵ��Ӧ�Ľڵ㣨���Ա�������һ�������Ľڵ㣩��
	//	O(1)��������findPrevious�Ӻ������Ӷȣ�
	void delete_val(int val);
	//7- �������O(N)
	void delete_L();
	//8- ��ӡ����O(N)
	void printList();
	//9- insertԪ��x���������������x, ���ز���x��Ӧnode��ַ��O(1)
	void insert_val(int val, int index);

	//��������
	//3- ����L�Ƿ���valֵ��û�з���nullptr��O(N)
	ListNode * find_val(int val);
};

