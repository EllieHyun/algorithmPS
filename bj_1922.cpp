// 네트워크 연결
// 크루스칼
#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int parent[MAX];

struct edge {
	int start, end, dist;

	edge(int START, int END, int DIST) : start(START), end(END), dist(DIST) {}

	bool operator<(const edge& e) const {
		return dist > e.dist;
	}
};

void initFunc(int n) {
	for (int i = 1; i <= n; i++) parent[i] = i;
}

int findFunc(int a) {
	if (parent[a] == a) return a;
	return parent[a] = findFunc(parent[a]);
}

void unionFunc(int a, int b) {
	int aRoot = findFunc(a);
	int bRoot = findFunc(b);
	parent[bRoot] = aRoot;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int a, b, c;
	int ans = 0;
	priority_queue<edge> pq;
	cin >> n >> m;

	initFunc(n);

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		pq.push(edge(a, b, c));
	}

	while (!pq.empty()) {

		edge cur = pq.top();
		pq.pop();

		if (findFunc(cur.start) == findFunc(cur.end)) continue;   // �̹� ������ ����
		else {
			ans += cur.dist;
			unionFunc(cur.start, cur.end);
		}
	}

	cout << ans;
	return 0;
}