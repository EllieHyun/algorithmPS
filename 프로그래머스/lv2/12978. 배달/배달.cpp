#include <iostream>
#include <vector>
#include <queue>
#define MAX 51
#define INF 1e9
using namespace std;

struct edge {
    int end;
    int dist;
    
    edge(int END, int DIST) : end(END), dist(DIST) {}
    
    bool operator<(const edge& e) const {
        return dist > e.dist;
    }
};

int dist[MAX];
vector<vector<edge>> edges;
priority_queue<edge> pq;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    edges.resize(N + 1);   // 마을의 개수만큼 edge 배열 크기 설정

    for(int i=1; i<=N; i++) {
        (i == 1) ? dist[i] = 0 : dist[i] = INF;   // 거리 배열 초기화
    }
    
    for(auto r : road) {
        int start = r[0];
        int end = r[1];
        int dist = r[2];
        edges[start].push_back(edge(end, dist));
        edges[end].push_back(edge(start, dist));
    }
    
    pq.push(edge(1, 0));   // 시작 노드를 넣음
    
    while(!pq.empty()) {
        edge curEdge = pq.top();
        pq.pop();
        int curEnd = curEdge.end;
        int curDist = curEdge.dist;
        int len = edges[curEnd].size();
        for(int i=0; i<len; i++) {
            edge next = edges[curEnd][i];
            if(dist[next.end] > curDist + next.dist) {
                dist[next.end] = curDist + next.dist;
                pq.push(edge(next.end, dist[next.end]));
            }
        }
    }
    for(int i=1; i<=N; i++) if(dist[i] <= K) answer++;
    return answer;
}