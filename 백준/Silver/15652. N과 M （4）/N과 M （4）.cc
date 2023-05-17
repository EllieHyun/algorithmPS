// n과 m (4)
#include <iostream>
#include <vector>
#define MAX 9
using namespace std;

bool visited[MAX];
int num[MAX];
int result[MAX];
int n, m;

void dfs(int start, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << result[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = start; i <= n; i++) {
        result[cnt] = num[i];
        dfs(i, cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) num[i] = i;

    dfs(1, 0);

    return 0;
}
