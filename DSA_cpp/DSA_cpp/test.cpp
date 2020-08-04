#include "SortFunctionsEL.h"
#include <vector>
#include <iostream>

using namespace std;

void print(vector<int>& nums) {
	for (int n : nums) {
		cout << n << " ";
	}
	cout << endl;
}

int main() {
	vector<int> nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// ð������ƽ��O(N ^ 2)�����O(N), ���O(N ^ 2)
	bubbleSort(nums);
	print(nums);

	nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// ѡ������ƽ��O(N ^ 2)�����O(N ^ 2), ���O(N ^ 2)
	selectionSort(nums);
	print(nums);

	nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// ��������ƽ��O(N ^ 2)�����O(N), ���O(N ^ 2)
	insertSort(nums);
	print(nums);

	nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// ϣ������ƽ��O((NlogN)^2)�����O(N), ���O((NlogN)^2)
	shellSort(nums);
	print(nums);


	nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// ������ƽ��O(NlogN)�����O(NlogN), ���O(NlogN)
	heapSort(nums);
	print(nums);
	

	nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// �鲢����ƽ��O(NlogN)�����O(NlogN), ���O(NlogN)
	mergeSort(nums);
	print(nums);

	nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// ��������ƽ��O(NlogN)�����O(NlogN), ���O(N^2)
	quickSort(nums);
	print(nums);

	nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// Ͱ����ƽ��O(N+K)�����O(N+K), ���O(N^2)
	bucketSort(nums, 10000);
	print(nums);
}