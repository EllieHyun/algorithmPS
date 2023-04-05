// 연산자 끼워넣기
#include <iostream>
#define MAX 11
using namespace std;

int nums[MAX];
int opers[MAX];   // 연산자들이 들어갈 순열
int opersPermutation[MAX];
bool visited[MAX] = {false, };
int oper[4];
int maxAns = -2e9;
int minAns = 2e9;

int calc(int n, int curOpers[]) {
    int result = nums[0];
    for(int i=0; i<n-1; i++) {
        if(curOpers[i] == 0) {
            result += nums[i+1];
        } else if(curOpers[i] == 1) {
            result -= nums[i+1];
        } else if(curOpers[i] == 2) {
            result *= nums[i+1];
        } else if(curOpers[i] == 3) {
            result /= nums[i+1];
        }
    }
    if(result > maxAns) maxAns = result;
    if(result < minAns) minAns = result;
    return result;
}

void calcPermutation(int depth, int n) {
    if(depth == n-1) {
        calc(n, opersPermutation);
    }

    for(int i=0; i<n-1; i++) {
        if(!visited[i]) {
            visited[i] = true;
            opersPermutation[depth] = opers[i];
            calcPermutation(depth+1, n);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    int idx = 0;
    for(int i=0; i<4; i++) {
        cin >> oper[i];
        for(int j=0; j<oper[i]; j++) {
            opers[idx++] = i;
        }
    }

    calcPermutation(0, n);

    cout << maxAns << "\n" << minAns << "\n";

    cout << "\n";
}
