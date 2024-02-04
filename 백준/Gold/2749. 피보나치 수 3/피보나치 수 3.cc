// 피보나치 수 3
#include <iostream>

using namespace std;

typedef long long ll;

#define INF 1000000

ll n;
ll arr[1500050];

void fibonacci() {
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 0; i < 1500000; i++) {
        arr[i + 2] = (arr[i+1] + arr[i]) % INF;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    fibonacci();

    cout << arr[n % 1500000] << "\n";

    return 0;
}

