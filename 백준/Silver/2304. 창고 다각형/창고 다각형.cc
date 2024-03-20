// 창고다각형
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1001
int n;
vector<pair<int, int>> v;

bool cmp(pair<int, int>& a, pair<int, int> &b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int l, h;
    int answer = 0;

    for(int i=0; i<n; i++) {
        cin >> l >> h;
        v.push_back(make_pair(l, h));
    }

    sort(v.begin(), v.end(), cmp);

    // 왼쪽 넓이 구하기
    int leftPos = v.front().first;
    int leftHeight = v.front().second;

    for(auto p : v) {
        if(leftHeight <= p.second) {
            // 더 높이가 높은 기둥을 발견했을 떄
            answer += (p.first - leftPos) * leftHeight;   // 면적 더하기
            leftPos = p.first;   // 기준 위치 변경
            leftHeight = p.second;   // 기준 높이 변경
        }
    }

    // 오른쪽 넓이 구하기
    int rightPos = v.back().first;
    int rightHeight = v.back().second;

    for(int i=v.size() -1; i>=0; i--) {
        if(rightHeight < v[i].second) {
            answer += (rightPos - v[i].first) * rightHeight;
            rightPos = v[i].first;
            rightHeight = v[i].second;
        }
    }

    cout << answer + leftHeight << "\n";

    return 0;
}
