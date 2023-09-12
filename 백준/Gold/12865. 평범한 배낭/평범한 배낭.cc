// 평범한 배날
#include <iostream>

#define CNT_MAX 101
#define WEIGHT_MAX 100001
using namespace std;

int weight[CNT_MAX];
int worth[CNT_MAX];
int dp[CNT_MAX][WEIGHT_MAX];

int main() {
    int n, k;

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> worth[i];
    }

    // dp[i][j] = i번째 물건까지 넣을 수 있을 때, 배낭의 최대 무게가 j일 때의 최대 가지
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int wi = weight[i];
            int vi = worth[i];
            if (wi <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wi] + vi);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][k] << "\n";
    return 0;
}