// dp
// N으로 표현
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#define MAX 9
using namespace std;

vector<unordered_set<int>> dp(9);

int calCont(int n, int length) {
    // 연속적으로 붙어있는 n이 있을 때의 값 계산
    int num = n;
    for(int i=1; i<length; i++) {
        num = num * 10 + n;
    }
    return num;
}

int solution(int N, int number) {
    int answer = -1;
    if(N == number) return 1;   // 두 수가 같다면 하나로 만들 수 있음
    // 아닐 경우
    dp[1].insert(N);
    for(int i=2; i<=8; i++) {
        dp[i].insert(calCont(N, i));   // 해당 길이만큼 N을 이어 붙였을 때 나오는 숫자
        for(int j=1; j<=i-1; j++) {
            unordered_set<int> first = dp[j];
            unordered_set<int> second = dp[i-j];
            int cal = 0;
            for(auto f : first) {
                for(auto s : second) {
                    cal = f + s;
                    if(cal > 0) dp[i].insert(cal);
                    cal = f - s;
                    if(cal > 0) dp[i].insert(cal);
                    cal = f / s;
                    if(cal > 0) dp[i].insert(cal);
                    cal = f * s;
                    if(cal > 0) dp[i].insert(cal);
                }
            }
        }
        if(dp[i].find(number) != dp[i].end()) {
            answer = i;
            break;
        }
    }

    return answer;
}

int main() {
    int N  = 5;
    int number = 12;
    int result = solution(5, 12);

    cout << "result : " << result << "\n";

    return 0;
}
