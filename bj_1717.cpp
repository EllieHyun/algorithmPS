// 집합의 표현
// union-find
#include <iostream>
#define MAX 1000001
using namespace std;

int parent[MAX] = { 0, };

void initFunc(int n) {
	for (int i = 0; i <= n; i++) parent[i] = i;
}

int findFunc(int a) {
	if (parent[a] == a) return a;
	return parent[a] = findFunc(parent[a]);   // �θ� ã�ư��� ���ÿ� �θ� ����
}

void unionFunc(int a, int b) {
	int aRoot = findFunc(a);
	int bRoot = findFunc(b);
	parent[aRoot] = bRoot;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int num, a, b;
	cin >> n >> m;

	initFunc(n);

	for (int i = 0; i < m; i++) {
		cin >> num >> a >> b;
		if (num == 0) {
			unionFunc(a, b);
		}
		else {
			if (findFunc(a) == findFunc(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	
	return 0;
}