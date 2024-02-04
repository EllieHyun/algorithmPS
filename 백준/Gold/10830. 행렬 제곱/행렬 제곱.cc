// 행렬 제곱
#include <iostream>
#include <vector>

using namespace std;

#define MAX 6
typedef long long ll;
typedef vector<vector<ll>> matrix;

int n;   // 행렬의 크기
ll b;

matrix operation(matrix &first, matrix &second) {
    int len = first.size();   // 행렬의 크기
    matrix result(len, vector<ll>(len));   // 곱셈의 결과로 나올 새로운 행렬

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            // i : 행 번호, J : 열 번호
            for (int k = 0; k < len; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
            result[i][j] %= 1000;   // 1000으로 나눈 나머지
        }
    }

    return result;
}

matrix power(matrix a, ll num) {
    int len = a.size();
    matrix result(len, vector<ll>(len));

    for (int i = 0; i < len; i++) {
        result[i][i] = 1;   // 단위행렬
    }

    while (num > 0) {
        if (num % 2 == 1) {
            // b가 홀수일 때는 하나를 뺴고 결과에 곱함
            num--;
            result = operation(result, a);   // 결과에 미리 뺴둔 행렬 하나를 곱함
        } else {
            a = operation(a, a);   // 두 행렬을 곱하고 b를 2로 나눔
            num /= 2;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> b;

    matrix initMatrix(n, vector<ll>(n));   // 초기 정방 행렬

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> initMatrix[i][j];
        }
    }

    matrix result = power(initMatrix, b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
