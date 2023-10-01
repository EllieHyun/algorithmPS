// 새로운 게임2
#include <iostream>
#include <vector>
#include <deque>
#include <stack>

#define MAX 13
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;

struct horse {
    int x;
    int y;
    int dir;

    horse(int X, int Y, int DIR) : x(X), y(Y), dir(DIR) {}
};

struct chess {
    int x;
    int y;
    int color;
    deque<int> horses;
};

int xDir[5] = {0, 0, 0, -1, 1};   // -, 우, 좌, 상, 하
int yDir[5] = {0, 1, -1, 0, 0};   // -, 좌, 우, 상, 하

chess map[MAX][MAX];   // 말의 수
vector<horse> horses;
int n, k;

bool canGo(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n) return false;
    return true;
}

int changeDir(int curDir) {
    if (curDir == 1) {
        return 2;
    } else if (curDir == 2) {
        return 1;
    } else if (curDir == 3) {
        return 4;
    } else {
        return 3;
    }
}

int move(int i) {
    horse &horse = horses[i];   // 이동할 말의 번호
    int curX = horse.x;
    int curY = horse.y;
    int curDir = horse.dir;
    int nextX = curX + xDir[curDir];
    int nextY = curY + yDir[curDir];
    deque<int> &from = map[curX][curY].horses;   // 이동할 말들이 위치한 곳
    deque<int> &to = map[nextX][nextY].horses;   // 말들이 이동할 곳
    if (map[nextX][nextY].color == WHITE) {
        // 이동할 곳이 흰색인 경우 이동하려는 칸에 말을 그대로 올려놓음
        stack<int> stack;
        while (true) {
            int back = from.back();
            stack.push(back);
            from.pop_back();
            horses[back].x = nextX;
            horses[back].y = nextY;
            if (back == i) {
                break;
            }
        }
        while (!stack.empty()) {
            int top = stack.top();
            to.push_back(top);
            stack.pop();
        }
    } else if (map[nextX][nextY].color == RED) {
        // 이동할 곳이 빨간색인 경우 이동하려는 칸에 말을 반대 순서로 올려놓음
        while (true) {
            int back = from.back();
            to.push_back(back);
            from.pop_back();
            horses[back].x = nextX;
            horses[back].y = nextY;
            if (back == i) {
                break;
            }
        }
    }
    if (to.size() >= 4) return -1;
    else return 0;
}

int checkHorse(int i) {
    // i번째 말 이동
    horse &horse = horses[i];   // i번째 말
    int curX = horse.x;
    int curY = horse.y;
    int curDir = horse.dir;
    int nextX = curX + xDir[curDir];
    int nextY = curY + yDir[curDir];
    int result = 0;
    if (!canGo(nextX, nextY) || map[nextX][nextY].color == BLUE) {
        // 체스판 밖이거나 파란색으로 가려고 할 경우
        horse.dir = changeDir(curDir);
        curDir = horse.dir;
        int changedNextX = curX + xDir[curDir];   // 방향 바꾸고 이동할 칸
        int changedNextY = curY + yDir[curDir];
        if (canGo(changedNextX, changedNextY) && map[changedNextX][changedNextY].color != BLUE) {
            // 방향을 바꾼 곳이 이동할 수 있는 곳이고 파란색 칸이 아닌 경우에만 이동
            result = move(i);
        }
    } else if (map[nextX][nextY].color == WHITE) {
        result = move(i);
    } else {
        result = move(i);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int num;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num;
            map[i][j].x = i;
            map[i][j].y = j;
            map[i][j].color = num;
        }
    }

    int x, y, dir;
    for (int i = 0; i < k; i++) {
        cin >> x >> y >> dir;
        horses.push_back(horse(x, y, dir));
        map[x][y].horses.push_back(i);
    }

    int answer = 0;
    bool fin = false;
    while (true) {
        answer++;
        for (int i = 0; i < k; i++) {
            int result = checkHorse(i);   // i번째 말 확인
            if (result == -1) {
                fin = true;
            }
        }
        if (fin) break;
        if (answer >= 1001) {
            break;
        }
    }

    if (answer >= 1001) cout << "-1\n";
    else cout << answer << "\n";

    return 0;
}
