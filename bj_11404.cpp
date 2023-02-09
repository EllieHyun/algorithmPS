// 플로이드
#include <iostream>
#include <vector>
#define MAX 101
#define INF 987654321
using namespace std;

struct edge {
	int end, dist;
	edge(int END, int DIST) : end(END), dist(DIST) {}
};

int dist[MAX][MAX] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int a, b, c;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = (i == j) ? 0 : INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (dist[a][b] == 0) dist[a][b] = c;
		else dist[a][b] = min(dist[a][b], c);
	}

	// ��� �������� ���Ͽ�
	for (int now = 1; now <= n; now++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if(dist[i][now] != INF && dist[now][j] != INF)
					dist[i][j] = min(dist[i][j], dist[i][now] + dist[now][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] == INF ? cout << 0 << " " : cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}