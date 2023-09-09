#include <string>
#include <vector>
#define MAX 201
using namespace std;

bool visited[MAX];

void dfs(int start, vector<vector<int>>& computers) {
    vector<int> computer = computers[start];
    for(int i=0; i<computer.size(); i++) {
        int isConnected = computer[i];
        if(isConnected == 1 && !visited[i] && i != start) {
            visited[i] = true;
            dfs(i, computers);
        }
    }
    
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<computers.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i, computers);
            answer++;
        }
    }
    
    return answer;
}