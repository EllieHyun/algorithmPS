// 순열, 조합
#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<int> vec;
vector<int> permutationRes(5);
vector<int> combinationRes;
int permutationTotalCount = 0;
int combinationTotalCount = 0;

void permutation(int cnt) {
    if (cnt == vec.size()) {
        permutationTotalCount++;
        for (auto r: permutationRes) cout << r << " ";
        cout << "\n";
    }
    for (int i = 0; i < vec.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        permutationRes[cnt] = vec[i];
        permutation(cnt + 1);
        visited[i] = false;
    }
}

int combination(int start) {
    if (combinationRes.size() == 3) {
        combinationTotalCount++;
        for (auto c: combinationRes) cout << c << " ";
        cout << "\n";
    }
    for (int i = start; i < vec.size(); i++) {
        combinationRes.push_back(vec[i]);
        combination(i + 1);
        combinationRes.pop_back();
    }
}

void dfs(int index) {
    if(index == visited.size()) {
        for(auto v : visited) cout << v << " ";
        cout << "\n";
    }
    for(int i=index; i<visited.size(); i++) {
        visited[i] = true;
        dfs(index+1);
        visited[i] = false;
    }
}

int main() {

    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
        visited.push_back(false);
    }

    cout << "==========순열==========\n";
    permutation(0);
    cout << "순열의 총 수 : " << permutationTotalCount << "\n";

    cout << "==========조합==========\n";
    combination(0);
    cout << "조합의 총 수 : " << combinationTotalCount << "\n";

    return 0;
}
