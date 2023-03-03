// 경사로
#include <iostream>

#define MAX 101
using namespace std;

int map[MAX][MAX];
int rowVisited[MAX][MAX] = {false,};
int columnVisited[MAX][MAX] = {false,};
bool canGoCheck = false;
bool canPutCheck = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, l;
    int answer = 0;

    cin >> n >> l;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        // 행
        canGoCheck = true;
        int cur = map[i][1];
        int count = 1;
        // 왼쪽 -> 오른쪽
        for (int j = 2; j <= n; j++) {
            if (map[i][j] == cur) count++;
            else if (map[i][j] - cur == 1) {
                if (count < l) {
                    canGoCheck = false;
                    break;
                }
                // 초기에 지날 때는 경사로가 있는지 확인할 필요 없음
                for (int t = 1; t <= l; t++) rowVisited[i][j - t] = true;   // 경사로를 놓은 곳 표시
                cur = map[i][j];
                count = 1;
            } else if (map[i][j] - cur < 0) {
                cur = map[i][j];
                count = 1;
            } else if(map[i][j] - cur > 1) {
                canGoCheck = false;
                break;
            }
        }
        // 오른쪽 -> 왼쪽
        if (canGoCheck) {
            canPutCheck = true;
            cur = map[i][n];
            count = 1;
            for (int j = n - 1; j >= 1; j--) {
                if (map[i][j] == cur) count++;
                else if (map[i][j] - cur == 1) {
                    if (count < l) {
                        canGoCheck = false;
                        break;
                    }
                    // 경사로를 놓기전 겹치는 부분이 있는지 확인
                    for (int t = 1; t <= l; t++) {
                        if (rowVisited[i][j + t]) {
                            canPutCheck = false;
                            break;
                        }
                    }
                    if (canPutCheck) {
                        for (int t = 1; t <= l; t++) rowVisited[i][j + t] = true;   // 경사로를 놓은 곳 표시
                        cur = map[i][j];
                        count = 1;
                    } else {
                        canGoCheck = false;
                        break;
                    }
                } else if (map[i][j] - cur < 0) {
                    cur = map[i][j];
                    count = 1;
                } else if (map[i][j] - cur > 1) {
                    canGoCheck = false;
                    break;
                }
            }
            if (canGoCheck) answer++;
        }

        // 열
        // 위 -> 아래
        canGoCheck = true;
        canPutCheck = true;
        cur = map[1][i];
        count = 1;
        for (int j = 2; j <= n; j++) {
            if (map[j][i] == cur) count++;
            else if (map[j][i] - cur == 1) {
                if (count < l) {
                    canGoCheck = false;
                    break;
                }
                // 초기에 지날 때는 경사로가 있는지 확인할 필요 없음
                for (int t = 1; t <= l; t++) columnVisited[j - t][i] = true;   // 경사로를 높은 곳 표시
                cur = map[j][i];
                count = 1;
            } else if (map[j][i] - cur < 0) {
                cur = map[j][i];
                count = 1;
            } else if (map[j][i] - cur > 1) {
                canGoCheck = false;
                break;
            }
        }

        if (canGoCheck) {
            canPutCheck = true;
            cur = map[n][i];
            count = 1;
            for (int j = n - 1; j >= 1; j--) {
                if (map[j][i] == cur) count++;
                else if (map[j][i] - cur == 1) {
                    if (count < l) {
                        canGoCheck = false;
                        break;
                    }
                    for (int t = 1; t <= l; t++) {
                        if (columnVisited[j + t][i]) {
                            canPutCheck = false;
                            break;
                        }
                    }
                    if (canPutCheck) {
                        for (int t = 1; t <= l; t++) columnVisited[j + t][i] = true;
                        cur = map[j][i];
                        count = 1;
                    } else {
                        canGoCheck = false;
                        break;
                    }
                } else if (map[j][i] - cur < 0) {
                    cur = map[j][i];
                    count = 1;
                } else if (map[j][i] - cur > 1) {
                    canGoCheck = false;
                    break;
                }
            }
            if (canGoCheck) answer++;
        }
    }

    cout << answer;

    return 0;

}
