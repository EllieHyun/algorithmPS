// RGB거리
#include <iostream>

#define MAX 1001
using namespace std;

int dp[MAX][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, minAns = 1e9;
    int red, green, blue;
    cin >> n;

    // dp[i][0] : i번째 집을 빨간색으로 칠하기 위한 최소비용
    // dp[i][1] : i번째 집을 초록색으로 칠하기 위한 최소비용
    // dp[i][2] : i번재 집을 파란색으로 칠하기 위한 최소비용
    for (int i = 1; i <= n; i++) {
        cin >> red >> green >> blue;
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + red;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + green;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + blue;
    }

    for (int i = 0; i < 3; i++) if (minAns > dp[n][i]) minAns = dp[n][i];

    cout << minAns;

    return 0;
}
