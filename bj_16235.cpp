// 나무 재테크
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define MAX 11
using namespace std;

struct block {
    deque<int> trees;   // 작은 나이를 가진 나무부터 들어가도록
};

block ground[MAX][MAX];
int energy[MAX][MAX];   // 각 땅에 있는 양분
int robot[MAX][MAX];   // 로봇이 각 칸에 줄 수 있는 양분
vector<pair<int, int>> adj = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
};

bool canGo(int x, int y, int n) {
    if (x < 1 || x > n || y < 1 || y > n) return false;
    return true;
}

void breeding(int x, int y, int n) {
    for (auto &i: adj) {
        if (canGo(x + i.first, y + i.second, n)) ground[x + i.first][y + i.second].trees.push_front(1);
    }
}

void springAndSummer(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ground[i][j].trees.empty()) continue;
            deque<int> &trees = ground[i][j].trees;
            sort(trees.begin(), trees.end());   // 각 땅에 있는 나무 나이순으로 정렬
            int idx = 0;
            while (idx < trees.size() && energy[i][j] >= trees[idx]) {
                energy[i][j] -= trees[idx];   // 양분을 먹고
                trees[idx]++;   // 나이를 한 살 먹음
                idx++;
            }
            for (int k = trees.size() - 1; k >= idx; k--) {
                energy[i][j] += (trees[k] / 2);   // 여름에 죽은 나무만큼 양분을 더함
                trees.pop_back();
            }
        }
    }
}

void fallAndWinter(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            deque<int> &trees = ground[i][j].trees;
            for (auto &t: trees) {
                if (t % 5 == 0) {
                    breeding(i, j, n);   // 번식
                }
            }
            energy[i][j] += robot[i][j];   // 겨울에 에너지를 더함
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    int x, y, age;
    int ans = 0;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> robot[i][j];   // 로봇이 각 칸에 줄 수 있는 양분
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            energy[i][j] = 5;   // 초기 양분
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y >> age;
        ground[x][y].trees.push_back(age);   // 각 나무의 나이 저장
    }

    for (int i = 0; i < k; i++) {
        // k번의 계절
        // 봄, 여름
        springAndSummer(n);
        // 가을, 겨울
        fallAndWinter(n);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            ans += (int) ground[i][j].trees.size();
        }
    }

    cout << ans;

    return 0;
}
