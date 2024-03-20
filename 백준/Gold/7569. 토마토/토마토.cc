// 토마토
#include <iostream>
#include <queue>

#define MAX 101
using namespace std;

int arr[MAX][MAX][MAX];   // m, n, h
bool visited[MAX][MAX][MAX];   // m, n, h
int m, n, h;
int dirs[6][3] = {
        {0,  0,  -1},   // 위
        {0,  0,  1},   // 아래
        {-1, 0,  0},   // 왼쪽
        {1,  0,  0},   // 오른쪽
        {0,  1,  0},   // 앞
        {0,  -1, 0}   // 뒤
};

struct tomato {
    int m;
    int n;
    int h;
    int days;   // 몇일이 지났을 때 익은 토마토인지
    tomato(int M, int N, int H, int DAYS) : m(M), n(N), h(H), days(DAYS) {}
};

bool allRipens() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (arr[k][j][i] == 0) return false;   // 익지않은 토마토가 존재한다는 것
            }
        }
    }
    return true;
}

bool canGo(int curM, int curN, int curH) {
    if (curM < 0 || curM >= m || curN < 0 || curN >= n || curH < 0 || curH >= h) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> h;
    int answer = -1;
    queue<tomato> q;   // 익은 토마토의 좌표가 들어있는 큐

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> arr[k][j][i];   // m, n, h 순서대로 넣기
                if (arr[k][j][i] == 1) {
                    q.push(tomato(k, j, i, 0));   // 익은 토마토 push
                    visited[k][j][i] = true;   // 더이상 queue에 담지 않아도됨
                }
            }
        }
    }

    while (!q.empty()) {
        // 모든 토마토가 익었는지 검증
        tomato cur = q.front();
        q.pop();

        int curM = cur.m;
        int curN = cur.n;
        int curH = cur.h;
        int curDays = cur.days;

        if (allRipens()) {
            // 모든 토마토가 익었을 경우 더이상 확인할 필요 없음
            if(q.empty()) answer = curDays;
            else {
                while(!q.empty()) {
                    answer = q.front().days;
                    q.pop();
                }
            }
            break;
        }

        // 6가지 방향에 대해 익도록 함
        for (int i = 0; i < 6; i++) {
            int nextM = curM + dirs[i][0];
            int nextN = curN + dirs[i][1];
            int nextH = curH + dirs[i][2];
            if (canGo(nextM, nextN, nextH) && !visited[nextM][nextN][nextH]) {
                if (arr[nextM][nextN][nextH] == 0) {
                    // 익지않은 토마토가 있는 곳
                    q.push(tomato(nextM, nextN, nextH, curDays + 1));
                    visited[nextM][nextN][nextH] = true;
                    arr[nextM][nextN][nextH] = 1;   // 해당 토마토는 이제 익었음
                }
            }
        }
    }

//    if(q.empty() && !allRipens()) cout << -1 << "\n";   // 모든 곳을 순회했지만 토마토가 전부 다 익지 않았을 경우
    if (!allRipens()) cout << -1 << "\n";
    else cout << answer << "\n";

    return 0;

}
