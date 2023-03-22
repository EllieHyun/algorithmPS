// 아기 상어
#include <iostream>
#include <queue>
#define MAX 20
using namespace std;

struct position {
    int x;
    int y;
    int dist;
    position(int X, int Y, int DIST) : x(X), y(Y), dist(DIST) {}
};

int map[MAX][MAX];
bool visited[MAX][MAX];
int xDir[4] = {-1, 0, 1, 0};   // 북 서 남 동
int yDir[4] = {0, -1, 0, 1};   // 북 서 남 동
int n;
int ans = 0;
int curSize = 2;   // 아기 상어의 사이즈
int eatCnt = 0;
int sharkX, sharkY;
int minDist = 500;

void initVisited() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
}

bool canGo(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || map[x][y] > curSize) return false;
    return true;
}

bool bfs(int x, int y) {
    int minX = -1, minY = -1;
    minDist = 500;
    queue<position> q;
    q.push(position(x, y, 0));
    visited[x][y] = true;
    bool eat;
    while (!q.empty()) {
        int curX = q.front().x;
        int curY = q.front().y;
        int curDist = q.front().dist;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = curX + xDir[i];
            int nextY = curY + yDir[i];
            if (canGo(nextX, nextY)) {
                // 지나갈 수 있는 길일 떄
                if (map[nextX][nextY] == 0 || map[nextX][nextY] == curSize) {
                    visited[nextX][nextY] = true;   // 큐에 넣을 때 방문처리
                    q.push(position(nextX, nextY, curDist + 1));
                }
                else {
                    // 지나가다가 나보다 크기가 작은 물고기를 찾으면 먹어야함
                    visited[nextX][nextY] = true;
                    if (minDist > curDist + 1) {
                        // 거리가 더 가까운 물고기 발견
                        minX = nextX;
                        minY = nextY;
                        minDist = curDist + 1;   // 거리의 최솟값 갱신
                    } else if (minDist == curDist + 1) {
                        // 거리가 같은 물고기가 있을 때 더 위에 있는 물고기
                        if (nextX < minX) {
                            minX = nextX;
                            minY = nextY;
                        } else if (nextX == minX) {
                            // 거리가 같은 물고기가 있을 때 더 왼쪽에 있는 물고기
                            if (nextY < minY) {
                                minX = nextY;
                                minY = nextY;
                            }
                        }
                    }
                }
            }
        }
    }
    if (minX == -1) {
        // 잡아먹을 물고기가 없을 때
        eat = false;
    } else {
        // 잡아먹을 물고기가 있을 때
        eat = true;
        map[sharkX][sharkY] = 0;
        map[minX][minY] = -1;
        sharkX = minX;
        sharkY = minY;
        eatCnt++;
        if (eatCnt == curSize) {
            eatCnt = 0;
            curSize++;
        }
    }
    return eat;
}

void hunt(int x, int y) {
    // 먹을 수 있는 물고기 있는지 확인
    if (bfs(sharkX, sharkY)) {
        ans += minDist;
        initVisited();
        hunt(sharkX, sharkY);
    } else {
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                // 처음 상어가 있는 곳 저장
                map[i][j] = -1;
                sharkX = i;
                sharkY = j;
            }
        }
    }

    hunt(sharkX, sharkY);

    cout << ans;

    return 0;
}
