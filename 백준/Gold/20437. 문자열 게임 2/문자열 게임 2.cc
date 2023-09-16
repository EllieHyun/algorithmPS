// 문자열 게임2
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> arr[26];   // 각 알파벳이 시작한 위치를 저장할 위치

    int t, k;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string w;
        cin >> w >> k;
        int minAns = 2e9;
        int maxAns = -1;
        for(int j=0; j<26; j++) {
            arr[j].clear();
        }
        for (int j = 0; j < w.size(); j++) {
            arr[w[j] - 'a'].push_back(j);
        }
        for (int m = 0; m < 26; m++) {
            if (arr[m].size() >= k) {
                // 최소 k개 이상을 가지고 있는 알파벳들
                for (int a = 0; a <= arr[m].size() - k; a++) {
                    minAns = min(minAns, arr[m][a + k - 1] - arr[m][a] + 1);
                    maxAns = max(maxAns, arr[m][a + k - 1] - arr[m][a] + 1);
                }
            }
        }
        if (minAns == 2e9 && maxAns == -1) cout << -1 << "\n";
        else cout << minAns << " " << maxAns << "\n";
    }

    return 0;
}
