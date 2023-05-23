// n과 m (6)
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;

vector<int> num;
int result[MAX];
int visited[MAX];
int n, m;

void dfs(int start, int cnt) {
    if(cnt == m) {
        for(int i=0; i<cnt; i++) cout << result[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=start; i<n; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        result[cnt] = num[i];
        dfs(i+1, cnt+1);
        visited[i] = false;
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
}
