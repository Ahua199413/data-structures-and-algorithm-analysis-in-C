/*
	Author: Eajack Lau
	Date: 2020/6/24
	Function:
		8�������㷨

	1. �㷨���Ӷȣ�Ĭ������
		ð������ƽ��O(N ^ 2)�����O(N), ���O(N ^ 2)
		ѡ������ƽ��O(N ^ 2)�����O(N ^ 2), ���O(N ^ 2)
		��������ƽ��O(N ^ 2)�����O(N), ���O(N ^ 2)
		ϣ������ƽ��O((NlogN)^2)�����O(N), ���O((NlogN)^2)
		������ƽ��O(NlogN)�����O(NlogN), ���O(NlogN)
		�鲢����ƽ��O(NlogN)�����O(NlogN), ���O(NlogN)
		��������ƽ��O(NlogN)�����O(NlogN), ���O(N^2)
		Ͱ����ƽ��O(N+K)�����O(N+K), ���O(N^2)
	2. �ȶ�����&���ȶ�����
		2.1 �ȶ���������֤2��������������ԭ����˳�򲻱�
		2.2 ����
			��1���ȶ���ð�����򡢲������򡢹鲢����Ͱ����
			��2�����ȶ���ѡ�����򡢿�������ϣ�����򡢶�����
			ֻ�ü�ס�ȶ��ļ��ɣ�ð�����򡢲������򡢹鲢����Ͱ����
*/

#pragma once
#include <vector>
#include <algorithm>
#include "HeapEL.h"

// ð������ƽ��O(N ^ 2)�����O(N), ���O(N ^ 2)
void bubbleSort(std::vector<int>& nums);
// ѡ������ƽ��O(N ^ 2)�����O(N ^ 2), ���O(N ^ 2)
void selectionSort(std::vector<int>& nums);
// ��������ƽ��O(N ^ 2)�����O(N), ���O(N ^ 2)
void insertSort(std::vector<int>& nums);
// ϣ������ƽ��O((NlogN)^2)�����O(N), ���O((NlogN)^2)
void shellSort(std::vector<int>& nums);
// ������ƽ��O(NlogN)�����O(NlogN), ���O(NlogN)
void heapSort(std::vector<int>& nums);
// �鲢����ƽ��O(NlogN)�����O(NlogN), ���O(NlogN)
void mergeSortHelper(vector<int> &nums, int low, int high);
void merge(vector<int> &nums, int low, int mid, int high);
void mergeSort(std::vector<int>& nums);
// ��������ƽ��O(NlogN)�����O(NlogN), ���O(N^2)
int paritition(vector<int>& nums, int low, int high);
void quickSortHelper(vector<int>& nums, int low, int high);
void quickSort(std::vector<int>& nums);
// Ͱ����ƽ��O(N+K)�����O(N+K), ���O(N^2)
void bucketSort(std::vector<int>& nums, int MAX);