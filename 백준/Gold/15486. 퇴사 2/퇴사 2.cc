// 퇴사2
#include <iostream>

#define MAX 1500001
using namespace std;

int perTime[MAX];
int perPay[MAX];
int dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, maxAns = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> perTime[i] >> perPay[i];
    }

    int curMax = 0;
    for (int i = 1; i <= n + 1; i++) {
        curMax = max(curMax, dp[i]);
        if (i + perTime[i] > n + 1) continue;
        dp[i + perTime[i]] = max(dp[i + perTime[i]], curMax + perPay[i]);   // i번째 날짜지 일을 했을 때
    }

    for (int i = 1; i <= n + 1; i++) if (maxAns < dp[i]) maxAns = dp[i];
        
    cout << maxAns;

    return 0;

}
