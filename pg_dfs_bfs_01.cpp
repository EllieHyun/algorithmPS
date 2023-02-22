// dfs & bfs
// 단어 변환
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct word {
    string thisWord;
    int thisCount;
    word(string THISWORD, int THISCOUNT) : thisWord(THISWORD), thisCount(THISCOUNT) {}
};

bool canChange(string begin, string word) {
    int length = begin.size();
    int diff = 0;
    for(int i=0; i<length; i++) {
        if(begin[i] != word[i]) diff++;
        if(diff >= 2) return false;   // 서로 다른 문자가 두개 이상이면 바꿀 수 없음
    }
    if(diff == 1) return true;   // 서로 다른 문자가 하나일때 바꿀 수 있음
    return false;   // 서로 다른 문자가 없다면 바꿀 필요 없음
}

int solution(string begin, string target, vector<string> words) {
    // 완성하려는 단어가 words에 없다면 0 반환
    if(find(words.begin(), words.end(), target) == words.end()) return 0;

    int answer = 0;
    queue<word> q;
    vector<bool> visited(50, false);   // 해당 단어를 사용했냐 확인

    for(int i=0; i<words.size(); i++) {
        if(canChange(begin, words[i])) {
            // 바꿀 수 있는 첫번째 문자를 찾음
            q.push(word(words[i], 1));
            visited[i] = true;   // 해당 문자 방문
        }
    }

    while(!q.empty()) {
        word cur = q.front();
        q.pop();
        string curWord = cur.thisWord;
        int curCount = cur.thisCount;
        if(!curWord.compare(target)) {
            answer = curCount;
            break;
        }
        for(int i=0; i<words.size(); i++) {
            if(!visited[i] && canChange(curWord, words[i])) {
                q.push(word(words[i], curCount+1));
            }
        }
    }

    return answer;
}