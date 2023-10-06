// 맥주 마시면서 걸어가기
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool comp(pair<int, int> &p1, pair<int, int> &p2) {
    // x순, y순 차례대로 정렬
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    } else {
        return p1.first < p2.first;
    }
}

int dist(int fromX, int fromY, int toX, int toY) {
    int sumX = (fromX > toX) ? fromX - toX : toX - fromX;
    int sumY = (fromY > toY) ? fromY - toY : toY - fromY;
    return sumX + sumY;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test, n;
    int x, y;
    cin >> test;
    for (int i = 0; i < test; i++) {
        cin >> n;
        vector<pair<int, int> > pos;
        vector<vector<int> > adj;
        adj.resize(n + 2);
        for (int j = 0; j < n + 2; j++) {
            cin >> x >> y;
            pos.push_back(make_pair(x, y));
        }
        for (int j = 0; j < n + 2; j++) {
            for (int k = j + 1; k < n + 2; k++) {
                if (dist(pos[j].first, pos[j].second, pos[k].first, pos[k].second) <= 1000) {
                    // 두 노ㄷ 사이의 거리가 1000 이하라면 두 노드 연결
                    adj[j].push_back(k);
                    adj[k].push_back(j);
                }
            }
        }
        queue<int> q;
        vector<bool> visited(n + 3, false);

        q.push(0);
        visited[0] = true;
        bool find = false;
        while (!q.empty()) {
            int cur = q.front();
            if (cur == n + 1) {
                cout << "happy\n";
                find = true;
                break;
            }
            q.pop();
            vector<int> adjVec = adj[cur];
            int len = adjVec.size();
            for (int j = 0; j < len; j++) {
                int next = adjVec[j];
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        if (!find) {
            cout << "sad\n";
        }
    }

    return 0;

}
