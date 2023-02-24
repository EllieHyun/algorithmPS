// dp
// 등굣길
#include <string>
#include <vector>
#include <iostream>
#define MAX 101
using namespace std;

vector<vector<int>> dp(MAX, vector<int>(MAX, 0));   // 최단경로 수 저장

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(auto p : puddles) {
        dp[p[1]][p[0]] = -1;   // 물이 있는 곳
    }

    dp[1][1] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(i == 1 && j == 1) continue;
            else if(dp[i][j] == -1) dp[i][j] = 0;   // 물 웅덩이가 있는 곳은 지나갈 수 없음
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
        }
    }

    return dp[n][m];
}

int main() {
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = {{2, 2}};
    int result = solution(m, n, puddles);

    cout << "result : " << result << "\n";

    return 0;
}
