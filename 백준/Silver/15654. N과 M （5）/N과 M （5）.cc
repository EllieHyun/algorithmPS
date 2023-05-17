// n과 m (5)
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 9
using namespace std;

bool visited[MAX];
int result[MAX];
vector<int> num;
int n, m;

void dfs(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << result[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        result[cnt] = num[i];
        dfs(cnt + 1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int temp;

    for(int i=1; i<=n; i++) {
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());

    dfs(0);

    return 0;
}
