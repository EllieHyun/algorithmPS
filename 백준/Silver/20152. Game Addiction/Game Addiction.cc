#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int H, N;
	cin >> H >> N;
	long long arr[31][31]={0,};
	for(int i=0;i<31;i++) arr[0][i] = 1;
	for(int i=1;i<31;i++){
		for(int j=i;j<31;j++){
			arr[i][j] = arr[i-1][j] + arr[i][j-1];
		}
	}
	
	int k = abs(H-N);
	cout << arr[k][k];
	return 0;
}