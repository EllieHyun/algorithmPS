#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0;
    long long sum2 = 0;
    int answer = 0;
    queue<int> q1;
    queue<int> q2;
    for (auto q: queue1) {
        q1.push(q);
        sum1 += q;
    }
    for (auto q: queue2) {
        sum2 += q;
        q2.push(q);
    }
    int limit = q1.size();
    while (1) {
        if (sum1 > sum2) {
            int f1 = q1.front();
            q1.pop();
            q2.push(f1);
            sum1 -= f1;
            sum2 += f1;
        } else if (sum1 < sum2) {
            int f2 = q2.front();
            q2.pop();
            q1.push(f2);
            sum1 += f2;
            sum2 -= f2;
        } else if (sum2 == sum1)
            break;
        if (answer == limit * 3) {
            answer = -1;
            break;
        }
        answer++;
    }
    return answer;
}