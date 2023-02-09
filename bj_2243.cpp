// 사탕상자
// 인덱스트리
#include <iostream>
#define PIV (1<<20)
using namespace std;

int candy[2 * PIV] = { 0, };

void update(int b, int c) {
	b += PIV;
	while (b >0) {
		candy[b] += c;
		b /= 2;
	}
}
 
int query(int b) {
	// ������ b�� ����
	int idx = 1;
	while (idx < PIV) {
		// ������ ��尡 �� ������ ��� ������
		idx *= 2;
		if (candy[idx] < b) {
			b -= candy[idx];
			idx++;
		}
	}
	update(idx - PIV, -1);
	return idx - PIV;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int a, b, c;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			cout << query(b) << "\n";
		}
		else {
			cin >> b >> c;
			update(b, c);
		}
	}

	return 0;
}