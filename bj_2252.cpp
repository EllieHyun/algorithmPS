// 줄세우기
// 위상정렬
#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;

int inDegree[MAX] = { 0, };
vector<vector<int>> adj;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b;
	queue<int> q;
	cin >> n >> m;

	adj.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		inDegree[b]++;   // ������ ���� ����
		adj[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);   // ������ ������ 0�� ����(��������) �ֱ�
	}

	for (int i = 0; i < n; i++) {

		if (q.empty()) return 0;   // ��� ������ ��ȸ�ϱ� ���� queue�� ����ٸ� ����Ŭ�� �߻��� ��

		int cur = q.front();
		cout << cur << " ";
		q.pop();


		int len = adj[cur].size();

		for (int j = 0; j < len; j++) {
			int next = adj[cur][j];
			inDegree[next]--;

			if (inDegree[next] == 0) q.push(next);
		}
	}

	return 0;
}