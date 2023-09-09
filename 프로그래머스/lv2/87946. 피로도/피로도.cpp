#include <string>
#include <vector>
#include <iostream>
#define MAX 9
using namespace std;

int maxAns = -1;

void permutation(int count, vector<int>& result, vector<int>& dungeonsIndex, vector<bool>& visited, vector<vector<int>>& dungeons, int k) {
    if(count == dungeonsIndex.size()) {
        int curStat = k;   // 현재 피로도
        int canExplore = 0;
        for(auto r : result) {
            vector<int> d = dungeons[r];   // 피로도 정보
            if(curStat < d[0]) {
                break;   // 최소 필요 피로도가 없을 경우
            } else {
                curStat -= d[1];   // 소모 필요도 사용
                canExplore++;
            }
        }
        if(canExplore > maxAns) {
            maxAns = canExplore;
        }
        return;
    }
    
    for(int i=0; i<dungeonsIndex.size(); i++) {
        if(visited[i]) continue;
        visited[i] = true;
        result[count] = dungeonsIndex[i];
        permutation(count+1, result, dungeonsIndex, visited, dungeons, k);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> dungeonsIndex;
    for(int i=0; i<dungeons.size(); i++) {
        dungeonsIndex.push_back(i);
    }
    
    vector<int> result(dungeons.size(), 0);
    vector<bool> visited(dungeons.size(), false);
    
    permutation(0, result, dungeonsIndex, visited, dungeons, k);
    
    
    return maxAns;
}