// merge sort ±¸Çö
#include <iostream>
using namespace std;

int arr[9] = { 1, 9, 3, 7, 5, 2, 4, 6, 9 };
int sort[9] = { 0, };

void merge(int *arr, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = start;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			sort[k] = arr[i++];
		}
		else {
			sort[k] = arr[j++];
		}
		k++;
	}
	if (i > mid) {
		for (int t = j; t <= end; t++) {
			sort[k++] = arr[t];
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sort[k++] = arr[t];
		}
	}

	for (int t = start; t <= end; t++) arr[t] = sort[t];
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
	for (int i = 0; i < 9; i++) cout << arr[i] << " ";

	return 0;
	
}