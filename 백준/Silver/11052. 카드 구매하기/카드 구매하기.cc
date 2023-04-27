// 카드 구매하기
#include <iostream>

#define MAX 1001
using namespace std;

int pay[MAX];
int dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> pay[i];

    dp[1] = pay[1];
    dp[2] = max(pay[2], dp[1] + dp[1]);

    for(int i=3; i<=n; i++) {
        int max = -1;
        int initValue = dp[1] * i;
        if(max < initValue) max = initValue;
        for(int j=1; j<=i/2; j++) {
            if(max < (dp[j] + dp[i-j])) max = dp[j] + dp[i-j];
        }
        if(max < pay[i]) max = pay[i];
        dp[i] = max;
    }

    cout << dp[n];

    return 0;

}
