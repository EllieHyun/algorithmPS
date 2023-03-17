// 치킨거리
#include <iostream>
#include <vector>
#include <cmath>

#define MAX 51
using namespace std;

struct chicken {
    int id;
    int x;
    int y;

    chicken(int ID, int X, int Y) : id(ID), x(X), y(Y) {}
};

struct house {
    int x;
    int y;
    vector<int> dist;

    house(int X, int Y) : x(X), y(Y) {}
};

int map[MAX][MAX];
vector<chicken> chickens;
vector<house> houses;
vector<chicken> res;
int n, m;
int minAns = 1e9;

void combination(int start) {
    if (res.size() == m) {
        int total = 0;
        // 현재 선택된 치킨집의 번호
        for (auto &h: houses) {
            int min = 1e9;
            for (auto &r: res) {
                if (min > h.dist[r.id]) min = h.dist[r.id];
            }
            total += min;
        }
        if (minAns > total) minAns = total;
    }
    for (int i = start; i < chickens.size(); i++) {
        res.push_back(chickens[i]);
        combination(i + 1);
        res.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int id = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) chickens.push_back(chicken(id++, i, j));
            if (map[i][j] == 1) houses.push_back(house(i, j));
        }
    }

    for (auto &h: houses) {
        for (auto &c: chickens) {
            h.dist.push_back(abs(h.x - c.x) + abs(h.y - c.y));   // 각 치킨집까지의 치킨거리 계산
        }
    }

    combination(0);

    cout << minAns;

    return 0;
}