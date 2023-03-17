// 사다리 조작
#include <iostream>
#include <vector>
#include <cmath>

#define MAX 101
using namespace std;

int map[MAX][MAX];
int xDir[4] = {1, 0, -1, 0};   // 동 북 서 남
int yDir[4] = {0, -1, 0, 1};   // 동, 북, 서, 남

int plusDir(int dir) {
    return (dir == 3) ? 0 : dir + 1;
}

void draw(int x, int y, int d, int g) {
    int index;
    vector<int> dirStack;
    map[y][x] = -1;   // 드래콘 커브의 시작점
    dirStack.push_back(d);
    x += xDir[d];
    y += yDir[d];
    map[y][x] = -1;
    for (int i = 0; i < g; i++) {
        int total = pow(2, i);
        index = dirStack.size() - 1;
        for (int j = 0; j < total; j++) {
            int nextDir = plusDir(dirStack[index--]);
            x += xDir[nextDir];
            y += yDir[nextDir];
            map[y][x] = -1;
            dirStack.push_back(nextDir);
        }
        index = dirStack.size() - 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int x, y, d, g;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        draw(x, y, d, g);

    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (map[i][j] == -1) {
                if (map[i][j + 1] == -1 && map[i + 1][j] == -1 && map[i + 1][j + 1] == -1) ans++;
            }
        }
    }

    cout << ans;

    return 0;
}