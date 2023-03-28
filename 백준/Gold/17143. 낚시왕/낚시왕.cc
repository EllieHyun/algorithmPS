// 낚시왕
#include <iostream>
#include <vector>

#define MAX 101
using namespace std;

struct shark {
    int x;
    int y;
    int dir;
    int speed;
    int size;

    shark() {
        x = 0;
        y = 0;
        dir = 0;
        speed = 0;
        size = 0;
    }

    bool operator<(const shark &s) const {
        return x < s.x;
    }
};

shark map[MAX][MAX];   // 각 맵에 저장되어 있는 상어
int xDir[5] = {0, -1, 1, 0, 0};   // - 위 아래 오른쪽 왼쪽
int yDir[5] = {0, 0, 0, 1, -1};   // - 위 아래 오른쪽 왼쪽
int closest[MAX];
int r, c, m;

void printMap() {
    cout << "=====map=====\n";
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << "(" << map[i][j].speed << "," << map[i][j].size << ")\t";
        }
        cout << "\n";
    }
}

void printClosest() {
    for (int i = 1; i <= c; i++) cout << closest[i] << " ";
    cout << "\n";
}

void initClosest() {
    for (int i = 1; i <= c; i++) closest[i] = 200;
}

bool outOfBorder(int x, int y) {
    if (x < 1 || x > r || y < 1 | y > c) return true;
    return false;
}

int changeDir(int dir) {
    if (dir == 1) return 2;
    if (dir == 2) return 1;
    if (dir == 3) return 4;
    if (dir == 4) return 3;
}

int eat(int col) {
    int row = closest[col];   // 각 열에서 가장 가까운 상어가 저장된 행
    if (row == 200) return 0;   // 해당 열에 상어가 아무도 없다면 잡은 상어가 없음
    else return row;  // 각 열에서 가장 가까운 상어의 size 반환
}

void swim() {
    // 각 칸에 있는 상어들의 수영
    shark diff[MAX][MAX];
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            shark &curShark = map[i][j];
            int curX = curShark.x;   // 상어의 x 좌표
            int curY = curShark.y;   // 상어의 y 좌표
            if (curX == 0) continue;   // 상어가 없는 곳은 확인할 필요 없음
            // 이동 후 최종 좌표가 어디인지 결정
            if (curShark.dir == 1) {
                // 위
                if (curShark.speed < curX) {
                    // 이동하면서 방향 전환을 할 필요가 없음
                    curX += (curShark.speed * xDir[1]);
                } else {
                    int curSpeed = curShark.speed;
                    curSpeed -= (curX - 1);   // 우선 맨 위로 이동
                    curShark.dir = changeDir(curShark.dir);   // 끝에 간 다음 방향 한번 바뀜 -> 아래
                    int share = curSpeed / (r - 1);   // 방향을 몇번 바꿨는지 확인
                    int remainder = curSpeed % (r - 1);   // 바뀐 방향으로 얼마나 이동해야 하는지 확인
                    if (share % 2 == 0) {
                        // 방향은 그대로 -> 아래
                        curX = 1 + remainder;
                    } else {
                        // 방향 바뀜 -> 위
                        curShark.dir = changeDir(curShark.dir);   // 방향 바꿈
                        curX = r - remainder;
                    }
                }
            } else if (curShark.dir == 2) {
                // 아래
                if (curShark.speed < (r - curX)) {
                    // 이동하면서 방향 전환을 할 필요가 없음
                    curX += (curShark.speed * xDir[2]);
                } else {
                    int curSpeed = curShark.speed;
                    curSpeed -= (r - curX);
                    curShark.dir = changeDir(curShark.dir);   // 끝에 간 다음 방향 한번 바꿈 -> 위
                    int share = curSpeed / (r - 1);
                    int remainder = curSpeed % (r - 1);
                    if (share % 2 == 0) {
                        // 방향 그대로 -> 위
                        curX = r - remainder;
                    } else {
                        // 방향 바뀜 -> 아래
                        curShark.dir = changeDir(curShark.dir);
                        curX = 1 + remainder;
                    }
                }
            } else if (curShark.dir == 3) {
                // 오른쪽
                if (curShark.speed < (c - curY)) {
                    // 이동하면서 방향 전환을 할 필요가 없음
                    curY += (curShark.speed * yDir[3]);
                } else {
                    int curSpeed = curShark.speed;
                    curSpeed -= (c - curY);
                    curShark.dir = changeDir(curShark.dir);   // 끝에 간 다음 방향 한번 바꿈 -> 왼쪽
                    int share = curSpeed / (c - 1);
                    int remainder = curSpeed % (c - 1);
                    if (share % 2 == 0) {
                        // 방향 그대로 -> 왼쪽
                        curY = c - remainder;
                    } else {
                        // 방향 바꿈 -> 오른쪽
                        curShark.dir = changeDir(curShark.dir);
                        curY = 1 + remainder;
                    }
                }
            } else if (curShark.dir == 4) {
                // 왼쪽
                if (curShark.speed < curY) {
                    // 이동하면서 방향 전환을 할 필요가 없음
                    curY += (curShark.speed * yDir[4]);
                } else {
                    int curSpeed = curShark.speed;
                    curSpeed -= (curY - 1);
                    curShark.dir = changeDir(curShark.dir);   // 끝에 간 다음 방향 한번 바꿈 -> 오른쪽
                    int share = curSpeed / (c - 1);
                    int remainder = curSpeed % (c - 1);
                    if (share % 2 == 0) {
                        // 방향 그대로 -> 오른쪽
                        curY = 1 + remainder;
                    } else {
                        // 방향 바꿈 -> 왼쪽
                        curShark.dir = changeDir(curShark.dir);
                        curY = c - remainder;
                    }
                }
            }
            if (diff[curX][curY].size < curShark.size) {
                // 현재 (i, j)에 있는 상어가 1초 후 어디로, 어떤 방향을 가지고 이동할 지 저장
                diff[curX][curY].x = curX;
                diff[curX][curY].y = curY;
                diff[curX][curY].dir = curShark.dir;
                diff[curX][curY].size = curShark.size;
                diff[curX][curY].speed = curShark.speed;
            }

            if (closest[curY] > curX) {
                closest[curY] = curX;   // 가장 가까이 있는 상어 갱신
            }
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            map[i][j].x = diff[i][j].x;
            map[i][j].y = diff[i][j].y;
            map[i][j].dir = diff[i][j].dir;
            map[i][j].speed = diff[i][j].speed;
            map[i][j].size = diff[i][j].size;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y, s, d, z;
    int ans = 0;
    cin >> r >> c >> m;

    initClosest();

    for (int i = 0; i < m; i++) {
        cin >> x >> y >> s >> d >> z;
        map[x][y].x = x;
        map[x][y].y = y;
        map[x][y].speed = s;
        map[x][y].dir = d;
        map[x][y].size = z;
        if (closest[y] > x) closest[y] = x;
    }

//    printMap();
//    printClosest();

    for (int i = 1; i <= c; i++) {
        int row = eat(i);   // i번째 열에 있는 상어를 먹음
        if (row != 0) {
            ans += map[row][i].size;   // 잡아먹은 크기 더함
            map[row][i].x = 0;
            map[row][i].y = 0;
            map[row][i].dir = 0;
            map[row][i].speed = 0;
            map[row][i].size = 0;   // 잡아먹었으므로 해당 자리에서 상어는 사라짐
        }
        initClosest();
        swim();
//        printMap();
//        printClosest();
    }

    cout << ans;

    return 0;
}
