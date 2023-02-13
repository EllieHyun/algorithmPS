// 시험 감독
#include <iostream>
#include <vector>
using namespace std;

vector<int> stu;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a, b, c;
    long long ans = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a;
        stu.push_back(a);
    }

    cin >> b >> c;

    for(int i=0; i<n; i++) {
        if(stu[i] != 0) {
            if(stu[i] >= b) stu[i] -= b;
            else if(stu[i] < b) stu[i] = 0;
            ans++;
        }
    }

    for(int i=0; i<n; i++) {
        int temp = stu[i] / c;
        ans += temp;
        if(stu[i] % c != 0) ans++;
    }

    cout << ans;
    return 0;

}
