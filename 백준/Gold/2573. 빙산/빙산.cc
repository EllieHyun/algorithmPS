// 빙산
#include <iostream>
#include <queue>

#define MAX 301
using namespace std;

int iceberg[MAX][MAX];
int n, m;
int xDir[4] = {-1, 1, 0, 0};   // 상, 하, 좌, 우
int yDir[4] = {0, 0, -1, 1};   // 상, 하, 좌, 우

void melting() {
    int adjCnt[MAX][MAX] = {0,};
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (iceberg[i][j] > 0) {
                for (int k = 0; k < 4; k++) {
                    int adjX = i + xDir[k];
                    int adjY = j + yDir[k];
                    if (iceberg[adjX][adjY] == 0) {
                        // 인접한 곳 중 녹은 곳이 있다면 1 감소
                        adjCnt[i][j]++;
                    }
                }
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            iceberg[i][j] -= adjCnt[i][j];
            if (iceberg[i][j] < 0) iceberg[i][j] = 0;
        }
    }
}

int chkSeparateOrAllMelted() {
    int startX = -1;
    int startY = -1;
    queue<pair<int, int> > q;
    bool visited[MAX][MAX] = {false,};
    bool find = false;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (iceberg[i][j] != 0) {
                startX = i;
                startY = j;
                find = true;
                break;
            }
        }
        if (find) break;
    }
    if (startX == -1 && startY == -1) {
        return -1;   // 모두 녹은 것
    }
    // 분리되어있는지 확인
    q.push(make_pair(startX, startY));
    visited[startX][startY] = true;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int curX = cur.first;
        int curY = cur.second;
        for (int i = 0; i < 4; i++) {
            int nextX = curX + xDir[i];
            int nextY = curY + yDir[i];
            if (nextX > 0 && nextX < n && nextY > 0 && nextY < m && !visited[nextX][nextY] &&
                iceberg[nextX][nextY] != 0) {
                visited[nextX][nextY] = true;
                q.push(make_pair(nextX, nextY));
            }
        }
    }


    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (iceberg[i][j] != 0 && visited[i][j] != 1) {
                // 빙하가 아직 다 녹지 않았는데 방문을 안했다 -> 분리된 곳이 있다는 것
                return 2;
            }
        }
    }
    return 1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> iceberg[i][j];
        }
    }

    int year = 0;
    while (1) {
        year++;
        melting();   // 녹음
        int chk = chkSeparateOrAllMelted();
        if (chk == -1) {
            cout << 0 << "\n";
            break;
        } else if (chk == 2) {
            cout << year << "\n";
            break;
        } else {
            continue;
        }
    }

    return 0;
}
