#include <iostream>
#include <set>
using namespace std;

int numbers[1000000];
int lis[1000000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) lis[idx++] = numbers[i];
		else if (lis[idx - 1] < numbers[i]) lis[idx++] = numbers[i];
		else {
			lis[lower_bound(lis, lis + idx, numbers[i]) - lis] = numbers[i];   // i번째 수 이상이 처음 나타나는 위치
		}
	}

	cout << idx;

	return 0;
	
}