// 감시
#include <iostream>
#include <vector>

#define MAX 8
using namespace std;

struct cctv {
    int num;
    int x;
    int y;

    cctv(int NUM, int X, int Y) : x(X), y(Y), num(NUM) {}
};

int n, m;
vector<cctv> cctvs;
int map[MAX][MAX];
int minAns = 100;

void goUp(int x, int y) {
    x--;
    while (map[x][y] != 6 && x >= 0) {
        map[x][y] = -1;
        x--;
    }
}

void goRight(int x, int y) {
    y++;
    while (map[x][y] != 6 && y < m) {
        map[x][y] = -1;
        y++;
    }
}

void goDown(int x, int y) {
    x++;
    while (map[x][y] != 6 && x < n) {
        map[x][y] = -1;
        x++;
    }
}

void goLeft(int x, int y) {
    y--;
    while (map[x][y] != 6 && y >= 0) {
        map[x][y] = -1;
        y--;
    }
}

void check(int index) {
    if (index == cctvs.size()) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) cnt++;
            }
        }
        if (cnt < minAns)
            minAns = cnt;
        return;
    }
    int temp[MAX][MAX];
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            temp[i][j] = map[i][j];   // 기존 map 저장
        }
    }
    cctv &cctv = cctvs[index];
    if (cctv.num == 1) {
        for (int i = 0; i < 4; i++) {
            // 4가지 방향
            if (i == 0) goUp(cctv.x, cctv.y);
            else if (i == 1) goRight(cctv.x, cctv.y);
            else if (i == 2) goDown(cctv.x, cctv.y);
            else if (i == 3) goLeft(cctv.x, cctv.y);
            check(index + 1);
            for (int k = 0; k < MAX; k++) {
                for (int j = 0; j < MAX; j++) {
                    map[k][j] = temp[k][j];   // 기존 map 다시 가져오기
                }
            }
        }
    } else if (cctv.num == 2) {
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                goUp(cctv.x, cctv.y);
                goDown(cctv.x, cctv.y);
            } else if (i == 1) {
                goRight(cctv.x, cctv.y);
                goLeft(cctv.x, cctv.y);
            }
            check(index + 1);
            for (int k = 0; k < MAX; k++) {
                for (int j = 0; j < MAX; j++) {
                    map[k][j] = temp[k][j];   // 기존 map 다시 가져오기
                }
            }
        }
    } else if (cctv.num == 3) {
        for (int i = 0; i < 4; i++) {
            if (i == 0) {
                goUp(cctv.x, cctv.y);
                goRight(cctv.x, cctv.y);
            } else if (i == 1) {
                goRight(cctv.x, cctv.y);
                goDown(cctv.x, cctv.y);
            } else if (i == 2) {
                goDown(cctv.x, cctv.y);
                goLeft(cctv.x, cctv.y);
            } else if (i == 3) {
                goLeft(cctv.x, cctv.y);
                goUp(cctv.x, cctv.y);
            }
            check(index + 1);
            for (int k = 0; k < MAX; k++) {
                for (int j = 0; j < MAX; j++) {
                    map[k][j] = temp[k][j];   // 기존 map 다시 가져오기
                }
            }
        }

    } else if (cctv.num == 4) {
        for (int i = 0; i < 4; i++) {
            if (i == 0) {
                goLeft(cctv.x, cctv.y);
                goUp(cctv.x, cctv.y);
                goRight(cctv.x, cctv.y);
            } else if (i == 1) {
                goUp(cctv.x, cctv.y);
                goRight(cctv.x, cctv.y);
                goDown(cctv.x, cctv.y);
            } else if (i == 2) {
                goRight(cctv.x, cctv.y);
                goDown(cctv.x, cctv.y);
                goLeft(cctv.x, cctv.y);
            } else if (i == 3) {
                goDown(cctv.x, cctv.y);
                goLeft(cctv.x, cctv.y);
                goUp(cctv.x, cctv.y);
            }
            check(index + 1);
            for (int k = 0; k < MAX; k++) {
                for (int j = 0; j < MAX; j++) {
                    map[k][j] = temp[k][j];   // 기존 map 다시 가져오기
                }
            }
        }
    } else if (cctv.num == 5) {
        goUp(cctv.x, cctv.y);
        goRight(cctv.x, cctv.y);
        goDown(cctv.x, cctv.y);
        goLeft(cctv.x, cctv.y);
        check(index + 1);
        for (int k = 0; k < MAX; k++) {
            for (int j = 0; j < MAX; j++) {
                map[k][j] = temp[k][j];   // 기존 map 다시 가져오기
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 5) {
                cctvs.push_back(cctv(map[i][j], i, j));
            }
        }
    }

    check(0);
    cout << minAns;

    return 0;
}
