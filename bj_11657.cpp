// 타임머신
// 벨만포드
#include <iostream>
#include <vector>
#define MAX 501
#define INF 1e10
using namespace std;

long long dist[MAX];

struct edge {
	long long end, dist;
	edge(long long END, long long DIST) : end(END), dist(DIST) {}
};

vector<vector<edge>> edges;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int a, b, c;

	cin >> n >> m;
	edges.resize(n + 1);
	dist[1] = 0;
	for (int i = 2; i <= n; i++) dist[i] = INF;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges[a].push_back(edge(b, c));
	}

	// n-1�� ������ ���� �ִܰŸ�(��ü ����� ������ �ִ� n-1���� ������ ����ϹǷ�)
	for (int v = 0; v < n; v++) {
		// ��� ���� ����
		for (int now = 1; now <= n; now++) {
			// ������ ������ ���Ͽ� ������ ��ȸ
			int len = edges[now].size();
			for (int i = 0; i < len; i++) {
				edge next = edges[now][i];
				int nextVertex = next.end;
				int nextDist = next.dist;
				if (dist[now] != INF && dist[nextVertex] > dist[now] + nextDist) {
					if (v == n - 1) {
						cout << "-1\n";
						return 0;
					}
					dist[nextVertex] = dist[now] + nextDist;
				}
			}
		}
	}

	for (int i = 2; i <= n; i++) 
		(dist[i] == INF) ? cout << -1 << "\n" : cout << dist[i] << "\n";
	return 0;
	
}