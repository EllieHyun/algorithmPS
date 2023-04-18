// 마법사 상어와 비바라기
#include <iostream>
#include <vector>

#define MAX 51
using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];   // 구름이 사라진 칸을 저장
int xDir[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int yDir[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
vector<pair<int, int>> curPos;   // 이동 전 구름이 저장된 위치
int n, m;

void initVisited() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[i][j] = false;
        }
    }
}

pair<int, int> movePos(int x, int y, int d, int s) {
    int newX = x, newY = y;
    for (int i = 0; i < s; i++) {
        newX += xDir[d];
        newY += yDir[d];
        if (newX == n + 1) newX = 1;
        else if (newX == 0) newX = n;
        if (newY == n + 1) newY = 1;
        else if (newY == 0) newY = n;
    }
    return make_pair(newX, newY);
}

bool canGo(int x, int y) {
    if (x <= 0 || x > n || y <= 0 || y > n) return false;
    return true;
}

void waterCopy(int x, int y) {
    for (int d = 2; d <= 8; d += 2) {
        int newX = x + xDir[d];
        int newY = y + yDir[d];
        if (canGo(newX, newY) && map[newX][newY] > 0) map[x][y]++;
    }
}

void cloud(int d, int s) {
    vector<pair<int, int>> afterPos;
    vector<pair<int, int>> newCloudPos;
    for (auto c: curPos) {
        pair<int, int> newPos = movePos(c.first, c.second, d, s);
        newCloudPos.push_back(newPos);
        int newX = newPos.first;
        int newY = newPos.second;
        map[newX][newY]++;   // 비가 내려 물의 양이 1 증가하고
        visited[newX][newY] = true;   // 구름이 사라진 자리 표시
    }
    // 물복사
    for(auto c : newCloudPos) waterCopy(c.first, c.second);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] >= 2 && !visited[i][j]) {
                map[i][j] -= 2;
                afterPos.push_back(make_pair(i, j));
            }
        }
    }
    curPos.clear();
    for (auto a: afterPos) curPos.push_back(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int d, s;
    int a;
    int ans = 0;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a;
            map[i][j] = a;   // 물의 초기양 저장
        }
    }

    curPos.push_back(make_pair(n, 1));
    curPos.push_back(make_pair(n, 2));
    curPos.push_back(make_pair(n - 1, 1));
    curPos.push_back(make_pair(n - 1, 2));

    for (int i = 1; i <= m; i++) {
        cin >> d >> s;
        cloud(d, s);
        initVisited();   // 구름이 이동할 때마다 방문 위치 초기화
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += map[i][j];
        }
    }

    cout << ans;

    return 0;
}
