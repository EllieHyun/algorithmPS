// n과 m (2)
#include <iostream>

#define MAX 9
using namespace std;

bool visited[MAX];
int result[MAX];
int n, m;

void dfs(int start, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << result[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = start; i <= n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        result[cnt] = i;
        dfs(i, cnt + 1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    dfs(1, 0);

    return 0;
}
