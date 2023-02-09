// quick sort 구현
#include <iostream>
using namespace std;

int arr[10] = { 3, 7, 8, 1, 5, 9, 6, 10, 2, 4 };

void quick_sort(int start, int end) {
	if (start >= end) return;   // 원소가 하나일 때 종료

	int pivot = start;   // pivot은 첫번째 원소
	int left = start + 1;   // left는 pivot 다음
	int right = end;   // right는 맨 마지막

	while (left <= right) {   // 엇갈릴 때까지 반복
		while (left <= end && arr[left] <= arr[pivot]) {   // 피봇보다 큰 값을 찾을 때까지
			left++;
		}
		while (right > start && arr[right] >= arr[pivot]) {   // 피봇보다 작은 값을 찾을 때까지
			right--;
		}
		if (left < right) {
			swap(arr[left], arr[right]);
		}
		else {
			swap(arr[pivot], arr[right]);   // 작은 값과 pivot을 바꿈
		}
	}
	quick_sort(start, right - 1);
	quick_sort(right + 1, end);
}

int main() {
	cout << "origin\n";
	for (int i = 0; i < 10; i++) cout << arr[i] << " ";
	cout << "\nsort\n";
	quick_sort(0, 9);
	for (int i = 0; i < 10; i++) cout << arr[i] << " ";
	return 0;
}