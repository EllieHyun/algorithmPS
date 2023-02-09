// 구간합 구하기
// 인덱스트리
#include <iostream>
#define PIV (1<<20)
using namespace std;

long long tree[2 * PIV] = { 0, };

void update(long long b, long long c) {
	long long n = PIV + b;
	long long diff = c - tree[n];
	while (n > 0) {
		tree[n] += diff;
		n /= 2;
	}
}

long long query(long long b, long long c) {
	long long left = PIV + b;
	long long right = PIV + c;
	long long sum = 0;
	while (left < right) {
		if (left % 2 != 0) sum += tree[left++];
		if (right % 2 == 0) sum += tree[right--];
		left /= 2;
		right /= 2;
	}
	if(left == right) sum += tree[left];
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n, m, k;
	long long a, b, c;
	cin >> n >> m >> k;

	for (long long i = 1; i <= n; i++) {
		cin >> tree[PIV + i];
	}

	for (long long i = PIV - 1; i >= 1; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}

	for (long long i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c);   // �� �ٲٱ�
		}
		else {
			cout << query(b, c) << "\n";   // ���� �� ����ϱ�
		}
	}

	return 0;

}