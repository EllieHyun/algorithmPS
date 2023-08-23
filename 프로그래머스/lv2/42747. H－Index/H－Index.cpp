#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<>());   // 내림차순 정렬
	
	int i = 0;

	while (i < citations.size()) {
		if (i >= citations[i]) {   // i는 index, citations[i]는 index의 값
			if (i == citations[i - 1])
				return citations[i - 1];
			else 
				return i;
		}
		i++;
	}
}