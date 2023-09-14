// 가운데를 말해요
#include <iostream>
#include <queue>

#define MAX
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    // max heap의 크기는 min heap의 크기보다 1 크거나 같아야 한다
    // max heap의 top은 min heap의 top보다 작거나 같아야 한다
    // 만약 만족하지 않을 경우 두 heap의 top을 swap한다
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (maxHeap.empty()) {
            maxHeap.push(num);
        } else if (maxHeap.size() == minHeap.size()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        if (!maxHeap.empty() && !minHeap.empty() && (maxHeap.top() > minHeap.top())) {
            int maxTop = maxHeap.top();
            int minTop = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(minTop);
        }
        cout << maxHeap.top() << "\n";
    }
    return 0;
}
