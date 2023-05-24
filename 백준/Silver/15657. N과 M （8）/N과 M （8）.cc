// n과 m (8)
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;

int result[MAX];
vector<int> num;
int n, m;

void dfs(int start, int cnt) {
    if(cnt == m) {
        for(int i=0; i<m; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=start; i<n; i++) {
        result[cnt] = num[i];
        dfs(i, cnt+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int temp;
    for(int i=0; i<n; i++) {
        cin >> temp;
        num.push_back(temp);
    }

    sort(num.begin(), num.end());

    dfs(0, 0);

    return 0;
}

