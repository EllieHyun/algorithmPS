#include <iostream>
#include <stack>
using namespace std;

#define MAX 500001

stack<int> topStack;
int tops[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> tops[i];   // 탑의 높이 입력
        while(!topStack.empty() && tops[i] > tops[topStack.top()]) {
            topStack.pop();   // 현재 탑의 높이보다 작은 높이들은 다 pop
        }

        if(topStack.empty()) cout << 0 << " ";   // stack이 비어있다는 것은 해당 탑을 막을 탑이 없다는 것
        else cout << topStack.top() + 1 << " ";
        topStack.push(i);   // 현재 탑도 스택에 추가
    }

    return 0;
}