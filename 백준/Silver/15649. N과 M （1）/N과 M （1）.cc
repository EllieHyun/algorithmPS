// N과 M (1)
#include <iostream>
#include <vector>

#define MAX 9
using namespace std;

vector<bool> visited(MAX, false);
vector<int> vec(MAX);
int n, m;

void permutation(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << vec[i] << " ";
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        vec[cnt] = i;
        permutation(cnt + 1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    permutation(0);

    return 0;
}
