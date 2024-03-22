#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0; i<completion.size(); i++) {
        if(completion[i].compare(participant[i])) {
            return participant[i];
        }
    }
    return participant[participant.size() - 1];
}