// 스타트와 링크
#include <iostream>
#include <vector>
#define MAX 21
using namespace std;

int team[MAX][MAX];
bool check[MAX];
int minAns = 2e9;
int startScore = 0;
int linkScore = 0;

void combination(int count, int index, int n) {
    if(count == n/2) {
        startScore = 0;
        linkScore = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(check[i] && check[j]) startScore += team[i][j];
                if(!check[i] && !check[j]) linkScore += team[i][j];
            }
        }
        int diff = (startScore > linkScore) ? startScore - linkScore : linkScore - startScore;
        if(minAns > diff) minAns = diff;
    }
    for(int i=index; i <= n; i++) {
        check[i] = true;
        combination(count+1, i+1, n);
        check[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> team[i][j];
        }
    }

    combination(0, 1, n);

    cout << minAns;

    return 0;

}
