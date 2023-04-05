#include <iostream>
#include <queue>
#define MAX 50
using namespace std;

int map[MAX][MAX] = {0, };
int visited[MAX][MAX] = {false, };
int xDir[4] = {-1, 0, 1, 0};   // 북, 동, 남, 서
int yDir[4] = {0, 1, 0, -1};   // 북, 동, 남, 서
int ans = 0;

struct robot {
    int x;
    int y;
    int dir;
    robot(int X, int Y, int DIR) : x(X), y(Y), dir(DIR) {}
};

int rotate(int curDir) {
    // 반시계 방향으로 회전
    if(curDir == 0) return 3;
    else return curDir-1;
}

bool canGo(int x, int y, int n, int m) {
    if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y]) return false;
    return true;
}

pair<int, int> canBack(int x, int y, int dir) {
    int backDir = 0;
    if(dir == 0) backDir = 2;
    else if(dir == 1) backDir = 3;
    else if(dir == 2) backDir = 0;
    else if(dir == 3) backDir = 1;
    int nextX = x + xDir[backDir];
    int nextY = y + yDir[backDir];
    if(map[nextX ][nextY] == 1) return make_pair(-1, -1);   // 후진했을 때 벽이면 뒤로 갈 수 없음
    return make_pair(nextX, nextY);
}

bool existUncleaned(int x, int y) {
    for(int i=0; i<4; i++) {
        int nextX = x + xDir[i];
        int nextY = y + yDir[i];
        if(map[nextX][nextY] == 0) return true;   // 주변 4칸 중 청소되지 않은 칸 존재
    }
    return false;   // 청소되지 않은 칸 없음(다 청소되어있음)
}

int bfs(int startX, int startY, int startDir, int n, int m) {
    queue<robot> q;
    q.push(robot(startX, startY, startDir));   // 로봇의 시작좌표 입력
    while(!q.empty()) {
        robot cur = q.front();
        q.pop();
        int curX = cur.x;
        int curY = cur.y;
        int curDir = cur.dir;
        if(map[curX][curY] == 0) {
            map[curX][curY] = -1;   // 청소 완료
            ans++;   // 현재 칸 청소, 청소한 칸의 수 증가
        }
        if(!existUncleaned(curX, curY)) {
            // 청소되지 않은 빈칸이 없는 경우
            const pair<int, int> &back = canBack(curX, curY, curDir);
            if(back.first == -1) {
                break;   // 후진을 할 수 없다면 작동을 종료
            } else {
                q.push(robot(back.first, back.second, curDir));   // 방향 그대로 후진만
            }
        } else {
            // 청소되지 않은 빈칸이 있는 경우
            int nextDir = rotate(curDir);   // 90도 반시계방향으로 회전
            int nextX = curX + xDir[nextDir];
            int nextY = curY + yDir[nextDir];
            if(map[nextX][nextY] == 0)
                q.push(robot(nextX, nextY, nextDir));   // 방향 바꾼 후 전진
            else
                q.push(robot(curX, curY, nextDir));   // 방향만 바꾸고 전진하지않음
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int robotX, robotY, robotDir;

    cin >> n >> m;
    cin >> robotX >> robotY >> robotDir;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    int answer = bfs(robotX, robotY, robotDir, n, m);

    cout << answer;

    return 0;
}
