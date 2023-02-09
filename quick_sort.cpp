// quick sort ����
#include <iostream>
using namespace std;

int arr[10] = { 3, 7, 8, 1, 5, 9, 6, 10, 2, 4 };

void quick_sort(int start, int end) {
	if (start >= end) return;   // ���Ұ� �ϳ��� �� ����

	int pivot = start;   // pivot�� ù��° ����
	int left = start + 1;   // left�� pivot ����
	int right = end;   // right�� �� ������

	while (left <= right) {   // ������ ������ �ݺ�
		while (left <= end && arr[left] <= arr[pivot]) {   // �Ǻ����� ū ���� ã�� ������
			left++;
		}
		while (right > start && arr[right] >= arr[pivot]) {   // �Ǻ����� ���� ���� ã�� ������
			right--;
		}
		if (left < right) {
			swap(arr[left], arr[right]);
		}
		else {
			swap(arr[pivot], arr[right]);   // ���� ���� pivot�� �ٲ�
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