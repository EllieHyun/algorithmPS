// dfs & bfs
// 여행경로
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> answer;
vector<bool> visited(10001, false);   // i번째 경로를 방문했는지 저장하기 위한 변수
bool check = false;   // 경로가 완성되었는지 확인하기 위한 변수

void dfs(string dep, vector<vector<string>>& tickets, int count) {
    if(count == tickets.size()) {
        check = true;
    }
    answer.push_back(dep);   // 현재 출발지 넣기

    for(int i=0; i<tickets.size(); i++) {
        if(!visited[i] && tickets[i][0].compare(dep) == 0) {
            visited[i] = true;   // i번째 경로 사용
            dfs(tickets[i][1], tickets, count+1);

            if(!check) {
                answer.pop_back();
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());   // 알파벳 순으로 방문하기 위해 정렬

    dfs("ICN", tickets, 0);

    return answer;
}

int main() {
    vector<vector<string>> tickets = {
            {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}
    };

    solution(tickets);

    for(auto a : answer) cout << a << " ";
    return 0;
}
