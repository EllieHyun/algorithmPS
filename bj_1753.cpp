// 최단경로
// 다익스트라
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 20001
using namespace std;

struct edge {
	int end, dist;
	edge(int END, int DIST) : end(END), dist(DIST) {}
	
	bool operator<(const edge& e) const {
		return dist > e.dist;
	}
};

int dist[MAX];
vector<vector<edge>> edges;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, k;
	int a, b, c;
	priority_queue<edge> pq;
	
	cin >> v >> e >> k;

	edges.resize(v + 1);

	for (int i = 1; i <= v; i++) dist[i] = (i == k) ? 0 : INF;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		edges[a].push_back(edge(b, c));
	}

	pq.push(edge(k, 0));

	while (!pq.empty()) {
		edge cur = pq.top();
		pq.pop();

		int curVertex = cur.end;
		int curDist = cur.dist;

		int len = edges[curVertex].size();
		for (int i = 0; i < len; i++) {
			edge next = edges[curVertex][i];
			int nextVertex = next.end;
			int nextDist = next.dist;
			if (dist[nextVertex] > curDist + nextDist) {
				dist[nextVertex] = curDist + nextDist;
				pq.push(edge(nextVertex, dist[nextVertex]));
			}
		}
	}

	for (int i = 1; i <= v; i++) (dist[i] == INF) ? cout << "INF " : cout << dist[i] << " ";
	return 0;
}
