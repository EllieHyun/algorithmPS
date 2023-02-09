// 부분합
// 슬라이딩 왼도우
#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;

int numbers[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s;
	int sum = 0, ans = 100001;
	queue<int> q;
	
	cin >> n >> s;

	for (int i = 0; i < n; i++) cin >> numbers[i];

	for (int i = 0; i < n; i++) {
		sum += numbers[i];
		q.push(numbers[i]);
		if (sum >= s) {
			while (!q.empty()) {
				int front = q.front();
				sum -= front;
				if (sum < s) {
					ans = min(int(q.size()), ans);
					q.pop();
					break;
				}
				q.pop();
			}
		}
	}

	if (ans == 100001) cout << 0;
	else cout << ans;
	return 0;
}