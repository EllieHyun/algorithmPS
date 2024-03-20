// 빗물
#include <iostream>
#include <vector>
using namespace std;

#define MAX 501
int world[MAX];   // 2차원 세계의 높이(index = 왼쪽 위치)
int h, w;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;
    int heightSum = 0;
    int total = 0;

    int num;
    for(int i=0; i<w; i++) {
        cin >> world[i];   // 각 위치의 높이
        heightSum += world[i];   // 높이의 총합 -> 나중에 뺼 것
    }

    // 왼쪽
    int leftPos = 0;
    int leftHeight = world[0];

    for(int i=0; i<w; i++) {
        if(leftHeight <= world[i]) {
            total += (i-leftPos) * leftHeight;
            leftHeight = world[i];
            leftPos = i;
        }
    }

    // 오른쪽
    int rightPos = w-1;
    int rightHeight = world[w-1];

    for(int i=w-1; i>=0; i--) {
        if(rightHeight < world[i]) {
            total += (rightPos - i) * rightHeight;
            rightHeight = world[i];
            rightPos = i;
        }
    }

    cout << leftHeight + total - heightSum << "\n";
}
