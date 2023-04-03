// 연구소3
#include <iostream>
#include <vector>
#include <queue>

#define MAX 50
using namespace std;

struct pos {
    int x;
    int y;
    int cnt;

    pos(int X, int Y, int CNT) : x(X), y(Y), cnt(CNT) {}
};

int map[MAX][MAX];
int totalTime[MAX][MAX];   // 각 칸에 바이러스가 퍼지기 까지 걸리는 시간(최소시간)
int xDir[4] = {-1, 0, 1, 0};   // 북 동 남 서
int yDir[4] = {0, 1, 0, -1};   // 북 동 남 서
vector<pos> virusPos;
vector<pos> resultPos;
int n, m;
int minAns = 1e9;

void initTotalTime() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            totalTime[i][j] = 1e9;   // 바이러스가 존재하는 곳 남겨두고 전부 init
        }
    }
    for (auto &v: virusPos) {
        totalTime[v.x][v.y] = -1;   // 바이러스가 있는 곳은 다시 -1로
    }
}

//void printTotalTime() {
//    cout << "=====total time=====\n";
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << totalTime[i][j] << "\t";
//        }
//        cout << "\n";
//    }
//}

bool canGo(int x, int y, bool visited[][MAX]) {
    if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || map[x][y] == 1)
        return false;   // 벽이 있는 경우, 비활성 바이러스가 있는 곳일 경우
    return true;
}

int findMaxTime() {
    int max = -1;
    bool checkAll = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (totalTime[i][j] == 1e9 && map[i][j] != 1) {
                // 벽도 아니고 비활성 바이러스도 아닌데 방문하지 않은 곳이 있을 때
                checkAll = false;
                break;
            }
            if (totalTime[i][j] != 1e9 && totalTime[i][j] > max) {
                // 벽을 제외하고 모든 칸 중에서 퍼지는데 가장 오래 걸린 칸
                max = totalTime[i][j];
            }
        }
    }
    if (!checkAll) return -1;
    else return max;
}

void combination(int start) {
    if (resultPos.size() == m) {
        initTotalTime();
//        cout << "======\t";
        for (auto &r: resultPos) {
            totalTime[r.x][r.y] = 0;
//            cout << "(" << r.x << ", " << r.y << ")\t";
        }
//        cout << "======\n";
        int perMax = -1;
        for (auto &r: resultPos) {
            bool perVisited[MAX][MAX] = {false,};
            queue<pos> q;
            q.push(r);
            totalTime[r.x][r.y] = 0;
            perVisited[r.x][r.y] = true;
            while (!q.empty()) {
                pos &curPos = q.front();
                int curX = curPos.x;
                int curY = curPos.y;
                int curCnt = curPos.cnt;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nextX = curX + xDir[i];
                    int nextY = curY + yDir[i];
                    if (canGo(nextX, nextY, perVisited)) {
                        perVisited[nextX][nextY] = true;
                        q.push(pos(nextX, nextY, curCnt + 1));
                        if (totalTime[nextX][nextY] > curCnt + 1) {
                            // 아직 바이러스가 퍼지지 않은 곳(200) 또는 기존보다 더 빨리 퍼질 수 있는 경우의 수
                            totalTime[nextX][nextY] = curCnt + 1;
                        }
                    }
                }
            }
        }
//        printTotalTime();
        int maxTime = findMaxTime();
        if (maxTime != -1 && maxTime < minAns) minAns = maxTime;
//        cout << "maxTime : " << maxTime << "\n";
    }

    for (int i = start; i < virusPos.size(); i++) {
        resultPos.push_back(virusPos[i]);
        combination(i + 1);
        resultPos.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) virusPos.push_back(pos(i, j, 0));   // 바이러스가 저장될 수 있는 위치
        }
    }

//    for (auto &v: virusPos) {
//        cout << "(" << v.x << ", " << v.y << ")\n";
//    }

    combination(0);

    if (minAns == 1e9) cout << -1;
    else cout << minAns;

    return 0;
}
