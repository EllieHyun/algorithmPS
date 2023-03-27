#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool canGo(int n, int m, int x, int y) {
    if(x < 0 || x > n || y < 0 || y > m) return false;
    else return true;
}

int solution(vector<vector<int> > maps)
{
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    vector<vector<int>> dist(maps.size(), vector<int>(maps[0].size(), 0));
    int n = maps.size()-1;
    int m = maps[0].size()-1;
    int posX[4] = {0, -1, 0, +1};
    int posY[4] = {-1, 0, +1, 0};
    visited[0][0] = true;
    q.push(make_pair(0, 0));
    dist[0][0] = 1;
    while(!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nextX = curX + posX[i];
            int nextY = curY + posY[i];
            if(!canGo(n, m, nextX, nextY)) continue;   // map의 범위를 벗어나는 곳
            else if(maps[nextX][nextY] == 0) continue;   // map에서 막혀있는 곳
            q.push(make_pair(nextX, nextY));
            maps[nextX][nextY] = 0;
            dist[nextX][nextY] = dist[curX][curY] + 1;
        }
    }
    if(dist[n][m] == 0) return -1;
    else return dist[n][m];
}