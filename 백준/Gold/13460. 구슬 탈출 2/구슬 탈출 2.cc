// 구슬 탈출 2
#include <iostream>

#define MAX 11
using namespace std;

int n, m;
int xDir[4] = {-1, 1, 0, 0};   // 상, 하, 좌, 우
int yDir[4] = {0, 0, -1, 1};   // 상, 하, 좌, 우
int map[MAX][MAX];
int minAns = 2e9;

void moveRedFirst(int &nextRedX, int &nextRedY, int &nextBlueX, int &nextBlueY, int dir) {
    int moveX = xDir[dir];
    int moveY = yDir[dir];
    while (map[nextRedX + moveX][nextRedY + moveY] != -1 && map[nextRedX][nextRedY] != 0) {
        nextRedX += moveX;
        nextRedY += moveY;
    }
    while (map[nextBlueX + moveX][nextBlueY + moveY] != -1 && map[nextBlueX][nextBlueY] != 0) {
        nextBlueX += moveX;
        nextBlueY += moveY;
    }
    if (map[nextRedX][nextRedY] == 0 && map[nextBlueX][nextBlueY] == 0) return;
    if (nextRedX == nextBlueX && nextRedY == nextBlueY) {
        if (dir == 0) nextBlueX++;
        else if (dir == 1) nextBlueX--;
        else if (dir == 2) nextBlueY++;
        else nextBlueY--;
    }
}

void moveBlueFirst(int &nextRedX, int &nextRedY, int &nextBlueX, int &nextBlueY, int dir) {
    int moveX = xDir[dir];
    int moveY = yDir[dir];
    while (map[nextBlueX + moveX][nextBlueY + moveY] != -1 && map[nextBlueX][nextBlueY] != 0) {
        nextBlueX += moveX;
        nextBlueY += moveY;
    }
    while (map[nextRedX + moveX][nextRedY + moveY] != -1 && map[nextRedX][nextRedY] != 0) {
        nextRedX += moveX;
        nextRedY += moveY;
    }
    if (map[nextRedX][nextRedY] == 0 && map[nextBlueX][nextBlueY] == 0) return;
    else if (nextRedX == nextBlueX && nextRedY == nextBlueY) {
        if (dir == 0) nextRedX++;
        else if (dir == 1) nextRedX--;
        else if (dir == 2) nextRedY++;
        else nextRedY--;
    }
}


void dfs(int redX, int redY, int blueX, int blueY, int cnt) {
    if (cnt > 10) return;
    if (map[redX][redY] == 0) {
        if (map[blueX][blueY] == 0) {
            return;
        } else {
            if (minAns > cnt) {
                minAns = cnt;
                return;
            }
        }
    } else if (map[blueX][blueY] == 0) return;

    for (int i = 0; i < 4; i++) {
        int nextRedX = redX;
        int nextRedY = redY;
        int nextBlueX = blueX;
        int nextBlueY = blueY;
        if (i == 0) {
            if (nextRedX < nextBlueX) moveRedFirst(nextRedX, nextRedY, nextBlueX, nextBlueY, i);
            else moveBlueFirst(nextRedX, nextRedY, nextBlueX, nextBlueY, i);
        } else if (i == 1) {
            if (nextRedX > nextBlueX) moveRedFirst(nextRedX, nextRedY, nextBlueX, nextBlueY, i);
            else moveBlueFirst(nextRedX, nextRedY, nextBlueX, nextBlueY, i);
        } else if (i == 2) {
            if (nextRedY < nextBlueY) moveRedFirst(nextRedX, nextRedY, nextBlueX, nextBlueY, i);
            else moveBlueFirst(nextRedX, nextRedY, nextBlueX, nextBlueY, i);
        } else if (i == 3) {
            if (nextRedY > nextBlueY) moveRedFirst(nextRedX, nextRedY, nextBlueX, nextBlueY, i);
            else moveBlueFirst(nextRedX, nextRedY, nextBlueX, nextBlueY, i);
        }
        dfs(nextRedX, nextRedY, nextBlueX, nextBlueY, cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int redX, redY;
    int blueX, blueY;
    char c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c == '#') map[i][j] = -1;
            else if (c == '.') map[i][j] = 1;
            else if (c == 'O') map[i][j] = 0;
            else if (c == 'R') {
                redX = i;
                redY = j;
                map[i][j] = 1;
            } else if (c == 'B') {
                blueX = i;
                blueY = j;
                map[i][j] = 1;
            }
        }
    }

    dfs(redX, redY, blueX, blueY, 0);

    if (minAns == 2e9) cout << "-1" << "\n";
    else cout << minAns << "\n";

    return 0;
}
