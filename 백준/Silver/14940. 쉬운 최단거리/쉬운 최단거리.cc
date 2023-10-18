// 쉬운 최단거리
#include <iostream>
#include <queue>

#define MAX 1001
using namespace std;

struct pos {
    int x;
    int y;
    int dist;

    pos(int X, int Y, int DIST) : x(X), y(Y), dist(DIST) {}
};

int map[MAX][MAX];
int N, M;
int answer[MAX][MAX];
bool visited[MAX][MAX];

void bfs(int x, int y) {
    int dirs[4][2] = {{-1, 0},
                      {1,  0},
                      {0,  -1},
                      {0,  1}};   // 상,하,좌,우
    queue<pos> q;
    q.push(pos(x, y, 0));
    visited[x][y] = true;
    while (!q.empty()) {
        pos curPos = q.front();
        int curX = curPos.x;
        int curY = curPos.y;
        int curDist = curPos.dist;
        q.pop();
        answer[curX][curY] = curDist;   // 목적지에서 해당 지점까지의 거리

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dirs[i][0];
            int nextY = curY + dirs[i][1];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
            if (map[nextX][nextY] == 0) continue;   // 갈 수 없는 땅인 경우 지나가지 않음
            if (visited[nextX][nextY]) continue;
            q.push(pos(nextX, nextY, curDist + 1));
            visited[nextX][nextY] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int startX, startY;

    int num;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> num;
            map[i][j] = num;
            if (map[i][j] == 2) {
                startX = i;
                startY = j;
            }
        }
    }

    bfs(startX, startY);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                if (map[i][j] == 0) answer[i][j] = 0;
                else answer[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
