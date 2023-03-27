#include <string>
#include <vector>

using namespace std;

int dfs(int index, int num, vector<int> numbers, int target) {
    if(index == numbers.size()) {
        if(num == target) return 1;
        else return 0;
    }
    
    int tempNum1 = num + numbers[index];
    int tempNum2 = num - numbers[index];
    int tempNum = 0;
    tempNum += dfs(index+1, tempNum1, numbers, target);
    tempNum += dfs(index+1, tempNum2, numbers, target);
    
    return tempNum; 
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer += dfs(1, numbers[0], numbers, target);
    answer += dfs(1, -numbers[0], numbers, target);
    return answer;
}