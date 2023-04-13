#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int start = 0;
    int end = 0;
    int sum = 0;
    int min = 1e9;
    vector<int> answer(2);
    while (start < sequence.size()) {
        if (sum == k) {
            if (end - start < min) {
                min = end - start;
                answer[0] = start;
                answer[1] = end - 1;
            }
            sum -= sequence[start];
            start++;
        } else if (sum > k || end >= sequence.size()) sum -= sequence[start++];
        else sum += sequence[end++];
    }
    return answer;
}