// n과 m (1)
#include <iostream>

#define MAX 9
using namespace std;

bool visited[MAX];
int num[MAX];
int result[MAX];
int n, m;

void dfs(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << result[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
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

    for (int i = 1; i <= n; i++) num[i] = i;

    dfs(0);

    return 0;
}
