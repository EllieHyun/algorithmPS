// 나이트의 이동
#include <iostream>
#include <queue>

#define MAX 300
using namespace std;

struct pos {
    int x;
    int y;
    int cnt;

    pos(int X, int Y, int CNT) : x(X), y(Y), cnt(CNT) {}
};

int map[MAX][MAX];
bool visited[MAX][MAX];
int xDir[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int yDir[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void init() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            map[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

bool canGo(int n, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y]) return false;
    return true;
}

int bfs(int n, int fromX, int fromY, int toX, int toY) {
    queue<pos> q;
    int curX, curY, curCnt;
    q.push(pos(fromX, fromY, 0));
    visited[fromX][fromY] = true;
    while (!q.empty()) {
        pos &curPos = q.front();
        curX = curPos.x;
        curY = curPos.y;
        curCnt = curPos.cnt;
        if (curX == toX && curY == toY) break;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nextX = curX + xDir[i];
            int nextY = curY + yDir[i];
            if (canGo(n, nextX, nextY)) {
                q.push(pos(nextX, nextY, curCnt + 1));
                visited[nextX][nextY] = true;
            }
        }
    }
    return curCnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    int n, fromX, fromY, toX, toY;
    cin >> test;
    for (int i = 0; i < test; i++) {
        init();
        cin >> n >> fromX >> fromY >> toX >> toY;
        int ans = bfs(n, fromX, fromY, toX, toY);
        cout << ans << "\n";
    }

    return 0;
}
