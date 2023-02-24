// 퇴사
#include <iostream>
#define MAX 1001
using namespace std;

int totalTime[MAX];
int totalPay[MAX];
int answer = -1;

void dfs(int curDay, int curPay, int n, bool doWork) {
    if(doWork) {
        // 일을 하려고 했으나 퇴사날이 지나서 일을 할 수 없을 경우
        if(curDay > n || (curDay + totalTime[curDay] - 1) > n) {
            if(answer < curPay)
                answer = curPay;
            return;
        }
    } else {
        // 일을 하지 않을 에정인데 오늘이 퇴사날일 경우
        if(curDay == n) {
            if(answer < curPay) answer = curPay;
            return;
        }
    }


    if(doWork) {
        // curDay 일을 할거야
        curPay += totalPay[curDay];
        dfs(curDay + totalTime[curDay], curPay, n, true);
        dfs(curDay + totalTime[curDay], curPay, n, false);
    }
    else {
        for(int i=curDay+1; i<=n; i++) {
            dfs(i, curPay, n, true);
            dfs(i, curPay, n, false);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> totalTime[i];
        cin >> totalPay[i];
    }

    dfs(1, 0, n, true);
    dfs(1, 0, n, false);

    cout << answer;

    return 0;
}
