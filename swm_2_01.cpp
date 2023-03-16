// 소마 2차 1번 문제 풀이
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(string str) {
    vector<vector<int>> answer;
    vector<int> temp;
    int count;
    for (int i = 0; i < str.length(); i++) {
        count = 0;
        temp.clear();
        if (str[i] == '<') {
            // 왼쪽 화살표 또는 양쪽 화살표
            i++;
            while (str[i] == '-') {
                count++;
                i++;
            }
            if (str[i] == '>') {
                // 양쪽 화살표
                temp.push_back(0);
                temp.push_back(count);
                answer.push_back(temp);
            } else {
                // 왼쪽 화살표
                temp.push_back(-1);
                temp.push_back(count);
                answer.push_back(temp);
            }
            i--;
        } else if (str[i] == '-') {
            // 오른쪽 화살표
            i++;
            while (str[i] == '-') {
                count++;
                i++;
            }
            if (str[i] == '>') {
                temp.push_back(1);
                temp.push_back(count);
                answer.push_back(temp);
            }
            i--;
        }
    }
    return answer;
}

int main() {
    string str = "<----<-->--->";

    vector<vector<int>> answer = solution(str);

    cout << "[";
    for (auto a: answer) {
        cout << "[" << a[0] << ", " << a[1] << "]";
    }
    cout << "]";

    return 0;
}
