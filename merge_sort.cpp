// merge sorted ±¸Çö
#include <iostream>
using namespace std;

int sorted[9] = {0, };

void merge(int *arr, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = start;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
            sorted[k] = arr[i++];
		}
		else {
            sorted[k] = arr[j++];
		}
		k++;
	}
	if (i > mid) {
		for (int t = j; t <= end; t++) {
            sorted[k++] = arr[t];
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
            sorted[k++] = arr[t];
		}
	}

	for (int t = start; t <= end; t++) arr[t] = sorted[t];
}

void merge_sort(int* arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int main() {

	int arr[9] = { 1, 9, 3, 7, 5, 2, 4, 6, 9 };

	cout << "origin\n";
	for (int i = 0; i < 9; i++) cout << arr[i] << " ";
	merge_sort(arr, 0, 8);
	cout << "\nsorted\n";
	for (int i = 0; i < 9; i++) cout << sorted[i] << " ";

	return 0;
	
}