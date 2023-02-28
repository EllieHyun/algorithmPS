// 연구소
#include <iostream>
#include <vector>
#define MAX 9
using namespace std;

int map[MAX][MAX] = {0, };
bool visited[MAX][MAX] = {false, };
vector<pair<int, int>> virus;
vector<int> positionNum;
vector<int> selectNums;
vector<pair<int, int>> selectPos(3);
int maxAns = -1;

int xDir[4] = {-1, 0, 1, 0};   // 북, 동, 남, 서(시계방향)
int yDir[4] = {0, 1, 0, -1};   // 북, 동, 남, 서(시계방향)

void convertNumToPos(int m);

bool canGo(int curX, int curY, int n, int m) {
    if(curX < 1 || curX > n || curY < 1 || curY > m || visited[curX][curY]) return false;
    return true;
}

void dfs(int curX, int curY, int n, int m, int tempMap[][MAX]) {
    if(tempMap[curX][curY] == 1) return;

    visited[curX][curY] = true;   // 해당 정점 방문
    tempMap[curX][curY] = 2;   // 바이러스 퍼짐

    for(int i=0; i<4; i++) {
        int nextX = curX + xDir[i];
        int nextY = curY + yDir[i];
        if(canGo(nextX, nextY, n, m)) {
            dfs(nextX, nextY, n, m, tempMap);
        }
    }
}

int countSafe(int n, int m, int tempMap[][MAX]) {
    int count = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(tempMap[i][j] == 0) count++;
        }
    }
    return count;
}

void combination(int start, int count, int n, int m) {
    if(selectNums.size() == count) {
        int tempMap[MAX][MAX] = {0, };
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                tempMap[i][j] = map[i][j];
            }
        }   // 원래 맵 임시 복사
        convertNumToPos(m);   // 고른 3개의 숫자를 좌표로 변환
        for(auto p : selectPos) {
            tempMap[p.first][p.second] = 1;   // 선택된 3개의 좌표에 벽 세우기
        }

        // 바이러스 퍼지기
        for(int i=0; i<virus.size(); i++) {
            int x = virus[i].first;
            int y = virus[i].second;
            dfs(x, y, n, m, tempMap);
        }

        int safe = countSafe(n, m, tempMap);
        if(safe > maxAns) maxAns = safe;

        for(int i=0; i<MAX; i++) {
            for(int j=0; j<MAX; j++) {
                visited[i][j] = false;
            }
        }   // visited 배열 초기화

        return;
    }

    for(int i=start; i<positionNum.size(); i++) {
        selectNums.push_back(positionNum[i]);
        combination(i+1, count, n, m);
        selectNums.pop_back();
    }
}

void convertNumToPos(int m) {
    for(int i=0; i < selectNums.size(); i++) {
        int s = selectNums[i];
        int x;
        int y;
        if(s % m == 0) {
            x = s / m;
            y = m;
        } else {
            x = s / m + 1;
            y = s % m;
        }
        selectPos[i] = make_pair(x, y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> map[i][j];   // 지도 채우기
            if(map[i][j] == 2) {
                virus.push_back(make_pair(i, j));
            } else if(map[i][j] == 0) {
                // 벽이 없는 곳 = 벽이 생길 가능성이 있는 곳
                positionNum.push_back((i-1) * m + j);
            }
        }
    }

    combination(0, 3, n, m);

    cout << maxAns << "\n";

    return 0;

}