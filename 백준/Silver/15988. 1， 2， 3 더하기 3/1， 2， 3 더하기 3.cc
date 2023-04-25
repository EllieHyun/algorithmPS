// 1, 2, 3 더하기
#include <iostream>

#define MAX 1000001
using namespace std;

long long dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testCase;
    int n;
    cin >> testCase;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 1000000; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
    }

    for (int i = 0; i < testCase; i++) {
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}
