// 문자열 교환
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int minAns = 2e9;

    cin >> s;
    int aCnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') aCnt++;   // 연속으로 있어야 할 a의 갯수
    }

    for (int i = 0; i < s.size(); i++) {
        int perACnt = aCnt;   // 각 경우에 대해서 a의 갯수
        int exchangeCnt = 0;   // 교환해야 할 갯수
        for (int j = i; i < i + s.size(); j++) {
            if (perACnt == 0) break;
            if (s[j % s.size()] == 'b') {
                exchangeCnt++;   // 교환횟수 증가
                perACnt--;
            } else perACnt--;   // a이면 a를 찾은 것이므로 남은 a의 갯수 감소
        }
        minAns = min(exchangeCnt, minAns);
    }

    cout << minAns;

    return 0;
}
