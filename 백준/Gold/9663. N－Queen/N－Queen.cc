// N-Queen
#include <iostream>

#define MAX 16
using namespace std;

int n;
int answer = 0;
int col[MAX];

bool canGo(int index) {
    for (int i = 0; i < index; i++) {
        if (col[index] == col[i] || abs(index - i) == abs(col[index] - col[i])) {
            return false;
        }
    }
    return true;
}

void dfs(int index) {
    if (index == n) {
        answer++;
        return;
    }
    for (int i = 0; i < n; i++) {
        col[index] = i;
        if (canGo(index)) {
            dfs(index + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    dfs(0);

    cout << answer << "\n";
    return 0;
}
