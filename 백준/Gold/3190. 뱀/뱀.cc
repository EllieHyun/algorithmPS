// 뱀
#include <iostream>
#include <deque>
#include <vector>

#define MAX 101
using namespace std;

int map[MAX][MAX];
int xDir[4] = {-1, 1, 0, 0};   // 상, 하, 좌, 우
int yDir[4] = {0, 0, -1, 1};   // 상, 하, 좌, 우
int n, k, l;

int changeDir(int dir, char turn) {
    if (turn == 'L') {
        // 왼쪽 회전
        if (dir == 0) return 2;
        else if (dir == 1) return 3;
        else if (dir == 2) return 1;
        else if (dir == 3) return 0;
    } else {
        if (dir == 0) return 3;
        else if (dir == 1) return 2;
        else if (dir == 2) return 0;
        else if (dir == 3) return 1;
    }
}

bool canGo(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    deque<pair<int, int> > q;
    vector<pair<int, char> > directionChange;

    cin >> n >> k;
    int x, y;
    int move;
    char turn;
    map[1][1] = 2;   // 뱀이 있는 곳
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        map[x][y] = 1;   // 사과가 있는 곳
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> move >> turn;
        directionChange.push_back(make_pair(move, turn));
    }

    int curDir = 3;
    int curTime = 0;
    int index = 0;

    x = 1, y = 1;
    q.push_back(make_pair(1, 1));

    while (1) {

        curTime++;

        int nextX = x + xDir[curDir];
        int nextY = y + yDir[curDir];

        if (!canGo(nextX, nextY) || map[nextX][nextY] == 2) {
            // 벽을 만났거나 자기 자신의 몸을 만나면
            break;
        } else if (map[nextX][nextY] == 1) {
            // 사과가 있는 곳을 만나면
            map[nextX][nextY] = 2;
            q.push_front(make_pair(nextX, nextY));
        } else {
            // 사과가 없는 곳이면
            map[nextX][nextY] = 2;
            q.push_front(make_pair(nextX, nextY));
            map[q.back().first][q.back().second] = 0;   // 꼬리를 옮김
            q.pop_back();
        };

        if (index < directionChange.size() && curTime == directionChange[index].first) {
            curDir = changeDir(curDir, directionChange[index].second);
            index++;
        }
        x = nextX;
        y = nextY;
    }

    cout << curTime << "\n";

    return 0;

}