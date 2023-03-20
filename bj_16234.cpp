// 인구 이동
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#define MAX 50
using namespace std;

struct country {
    int x;
    int y;
    int people;

    country(int X, int Y, int PEOPLE) : x(X), y(Y), people(PEOPLE) {}
};

int world[MAX][MAX];
int visited[MAX][MAX] = {false,};
int xDir[4] = {-1, 0, 1, 0};   // 북, 동, 남, 서
int yDir[4] = {0, 1, 0, -1};   // 북, 동, 남, 서
int n, l, r;

bool canGo(int x, int y) {
    if (visited[x][y] || x < 0 || x >= n || y < 0 || y >= n) return false;
    return true;
}

void initVisited() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
}

bool bfs(int startX, int startY) {
    int totalPeople = 0;
    int totalCountry = 0;
    queue<country> q;   // 국가 탐색을 위한 queue
    vector<country> v;   // 인구 이동이 일어날 국가의 좌표를 저장할 vector
    q.push(country(startX, startY, world[startX][startY]));
    visited[startX][startY] = true;
    while (!q.empty()) {
        country &curCountry = q.front();
        v.push_back(curCountry);
        int curX = curCountry.x;
        int curY = curCountry.y;
        int curPeople = curCountry.people;
        q.pop();
        totalPeople += curPeople;
        totalCountry++;
        for (int i = 0; i < 4; i++) {
            int nextX = curX + xDir[i];
            int nextY = curY + yDir[i];
            int diff = abs(world[curX][curY] - world[nextX][nextY]);
            if (canGo(nextX, nextY) && diff >= l && diff <= r) {
                q.push(country(nextX, nextY, world[nextX][nextY]));
                visited[nextX][nextY] = true;
            }
        }
    }
    for (auto &cur: v) {
        world[cur.x][cur.y] = totalPeople / totalCountry;   // 인구 이동이 일어나 평균값으로 인구 변화
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ans = 0;
    bool exist;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> world[i][j];
        }
    }

    while (true) {
        // 각 일자
        exist = false;
        initVisited();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    for(int k=0; k<4; k++) {
                        int nextX = i + xDir[k];
                        int nextY = j + yDir[k];
                        int diff = abs(world[i][j] - world[nextX][nextY]);
                        if(canGo(nextX, nextY) && diff >= l && diff <= r) {
                            exist = true;
                            bfs(i, j);
                            break;
                        }
                    }
                }
            }
        }
        if (!exist) break;
        ans++;
    }

    cout << ans;

    return 0;
}
