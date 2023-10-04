// 연결 요소의 개수
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
int n, m;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        vector<int> adjVec = adj[cur];
        int len = adjVec.size();
        for (int i = 0; i < len; i++) {
            int next = adjVec[i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), false);

    int answer = 0;
    int from, to;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            answer++;
            bfs(i);
        }
    }
    cout << answer << "\n";
    return 0;
}
