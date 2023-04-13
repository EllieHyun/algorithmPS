// 가장 긴 증가하는 부 수열 4
#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;

int arr[MAX];
int result[MAX];
vector<int> realSeq;
int indexArr[MAX];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];

    int idx = 0;
    for(int i=0; i<n; i++) {
        if(i == 0 || result[idx-1] < arr[i]) {
            result[idx] = arr[i];
            indexArr[i] = idx;
            idx++;
        }
        else {
            int newIndex = lower_bound(result, result + idx, arr[i]) - result;
            result[newIndex] = arr[i];
            indexArr[i] = newIndex;
            result[lower_bound(result, result + idx, arr[i]) - result] = arr[i];   // 해당 수 이상이 처음 나타나는 위치
        }
    }

    cout << idx << "\n";
    idx--;
    for(int i=n-1; i>=0; i--) {
        if(indexArr[i] == idx) {
            realSeq.push_back(arr[i]);
            idx--;
        }
    }

    for(int i=realSeq.size()-1; i>=0; i--) cout << realSeq[i] << " ";

    return 0;

}
