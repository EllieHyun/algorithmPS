// BFS와 DFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
vector<bool> visited;
vector<vector<int>> map;

void dfs(int start) {
    cout << start << " ";
    visited[start] = true;
    vector<int> adj = map[start];
    int len = adj.size();
    for(int i=0; i<len; i++) {
        int next = adj[i];
        if(!visited[next]) dfs(next);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
     visited[start] = true;

    while(!q.empty()) {
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        vector<int> adj = map[cur];
        int len = adj.size();
        for(int i=0; i<len; i++) {
            int next = adj[i];
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

void initVisited() {
    for(int i=0; i<=n; i++) {
        visited[i] = false;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int start, end;

    cin >> n >> m >> v;

    visited.resize(n+1);   // 방문 여부를 확인할 노드의 갯수
    map.resize(n+1);   // 인접 노드


    for(int i=0; i<m; i++) {
        cin >> start >> end;
        map[start].push_back(end);
        map[end].push_back(start);
    }

    for(int i=1; i<=n; i++) {
        sort(map[i].begin(), map[i].end());
    }

    dfs(v);
    initVisited();
    cout << "\n";
    bfs(v);

    return 0;
}
