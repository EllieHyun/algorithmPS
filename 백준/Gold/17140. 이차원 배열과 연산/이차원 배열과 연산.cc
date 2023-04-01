// 이차원 배열과 연산
#include <iostream>
#include <queue>
#include <vector>

#define MAX 101
using namespace std;

int arr[MAX][MAX] = {0,};
int r, c, k;
int ans = -1;
int curRow = 3, curCol = 3;   // 현재 행과 열의 수(index)

struct num {
    int n;
    int cnt;

    num() {
        n = 0;
        cnt = 0;
    }

    bool operator<(const num &NUM) const {
        if(cnt == NUM.cnt) {
            return n > NUM.n;
        } else {
            return cnt > NUM.cnt;
        }
    }

};

//void printArr() {
//    cout << "=====arr=====\n";
//    cout << "curRow : " << curRow << ", curCol : " << curCol << "\n";
//    for (int i = 1; i <= 10; i++) {
//        for (int j = 1; j <= 10; j++) {
//            cout << arr[i][j] << " ";
//        }
//        cout << "\n";
//    }
//}

void doRowSort() {
    int maxCol = -1;
    for (int i = 1; i <= curRow; i++) {
        num numCnt[MAX];   // 어떤 수가 몇번 나왔는지
        priority_queue<num> pq;
        for (int j = 1; j <= curCol; j++) {
            int index = arr[i][j];
            if (numCnt[index].n == 0) {
                numCnt[index].n = arr[i][j];
            }
            numCnt[index].cnt++;
            arr[i][j] = 0;
        }
        for (int index = 1; index < MAX; index++) {
            if (numCnt[index].n != 0)
                pq.push(numCnt[index]);
        }
        if ((int) (pq.size() * 2) > maxCol)
            maxCol = pq.size() * 2;
        int idx = 1;
        while (!pq.empty()) {
            num curNum = pq.top();
            pq.pop();
            arr[i][idx++] = curNum.n;
            arr[i][idx++] = curNum.cnt;
        }
    }
    if (maxCol > 100) curCol = 100;
    else curCol = maxCol;
//    printArr();
}

void doColSort() {
    int maxRow = -1;
    for (int i = 1; i <= curCol; i++) {
        num numCnt[MAX];
        priority_queue<num> pq;
        for (int j = 1; j <= curRow; j++) {
            int index = arr[j][i];
            if (numCnt[index].n == 0) {
                numCnt[index].n = arr[j][i];
            }
            numCnt[index].cnt++;
            arr[j][i] = 0;
        }
        for (int index = 1; index < MAX; index++) {
            if (numCnt[index].n != 0)
                pq.push(numCnt[index]);

        }
        if ((int) (pq.size() * 2) > maxRow)
            maxRow = pq.size() * 2;
        int idx = 1;
        while (!pq.empty()) {
            num curNum = pq.top();
            pq.pop();
            arr[idx++][i] = curNum.n;
            arr[idx++][i] = curNum.cnt;
            arr[idx][i] = 0;
        }
    }
    if (maxRow > 100) curRow = 100;
    else curRow = maxRow;
//    printArr();
}

void doSort() {
    if (curRow >= curCol) {
        doRowSort();
    } else {
        doColSort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c >> k;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> arr[i][j];
        }
    }

//    printArr();

    if (arr[r][c] == k) cout << 0;
    else {
        for (int i = 1; i <= 100; i++) {
            doSort();
            if (arr[r][c] == k) {
                ans = i;
                break;
            }
        }
        cout << ans;
    }

    return 0;
}
