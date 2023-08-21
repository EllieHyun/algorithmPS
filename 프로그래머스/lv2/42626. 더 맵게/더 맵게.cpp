#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int newSco = -1;
    priority_queue<int, vector<int>, greater<int>> q;   // min heap
    
    for(int i=0; i<scoville.size(); i++)
        q.push(scoville[i]);
    
    while(q.top() < K) {
        newSco = q.top();
        q.pop();
        if(q.empty())return -1;
        newSco += (q.top() * 2);
        q.pop();
        q.push(newSco);
        answer++;
    }
    return answer;
    
}