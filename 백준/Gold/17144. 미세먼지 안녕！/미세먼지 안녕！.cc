// 미세먼지 안녕
#include <iostream>
#include <vector>

#define MAX 50
using namespace std;

int house[MAX][MAX];
int diff[MAX][MAX];
int xDir[4] = {-1, 0, 1, 0};   // 북 동 남 서
int yDir[4] = {0, 1, 0, -1};   // 북 동 남 서
vector<int> cleaner;
int r, c, t;
int ans = 0;

bool canGo(int x, int y) {
    if (x < 0 || x >= r || y < 0 || y >= c || house[x][y] == -1) return false;
    return true;
}

void initDiff() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            diff[i][j] = 0;
        }
    }
}

void diffusion() {
    // 확산
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (house[i][j] != 0 && house[i][j] != -1) {
                // 공기청정기가 없고 먼지가 있는 곳
                int cnt = 0;   // 확산시킨 칸의 개수
                int dust = house[i][j] / 5;   // 확산될 먼지의 양
                for (int k = 0; k < 4; k++) {
                    int nextX = i + xDir[k];
                    int nextY = j + yDir[k];
                    if (canGo(nextX, nextY)) {
                        diff[nextX][nextY] += dust;
                        cnt++;
                    }
                }
                diff[i][j] -= (dust * cnt);
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            house[i][j] += diff[i][j];
        }
    }
}

void clean() {
    int upCleaner = cleaner[0];
    for (int i = upCleaner - 1; i >= 1; i--) house[i][0] = house[i - 1][0];
    for (int i = 0; i < c - 1; i++) house[0][i] = house[0][i + 1];
    for (int i = 0; i <= upCleaner - 1; i++) house[i][c - 1] = house[i + 1][c - 1];
    for (int i = c - 1; i >= 2; i--) house[upCleaner][i] = house[upCleaner][i - 1];
    house[upCleaner][1] = 0;   // 이 자리는 무조건 먼지가 없어야함 -> 일단 밀려감

    int downCleaner = cleaner[1];
    for (int i = downCleaner + 1; i < r - 1; i++) house[i][0] = house[i + 1][0];
    for (int i = 0; i < c - 1; i++) house[r - 1][i] = house[r - 1][i + 1];
    for (int i = r - 1; i > downCleaner; i--) house[i][c - 1] = house[i - 1][c - 1];
    for (int i = c - 1; i >= 2; i--) house[downCleaner][i] = house[downCleaner][i - 1];
    house[downCleaner][1] = 0;   // 이 자리는 무조건 먼지가 없어야 함
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c >> t;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> house[i][j];
            if (house[i][j] == -1) cleaner.push_back(i);   // 공기청정기가 있는 행의 위치
        }
    }

    for (int i = 0; i < t; i++) {
        initDiff();
        diffusion();
        clean();
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (house[i][j] != -1) ans += house[i][j];
        }
    }

    cout << ans;

    return 0;
}
