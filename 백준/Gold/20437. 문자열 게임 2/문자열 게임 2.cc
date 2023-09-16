#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
 
int main(){
    
    int T;
    cin >> T;
    
    vector<int> vecList[26];
 
    for(int test_case = 1; test_case <=T; test_case++){
        string W;
        int K;
        cin >> W >> K;
        
        int mini = 100000;
        int maxi = 0;
        for(int i = 0; i<26; i++) vecList[i].clear();
        for(int i = 0; i<W.length(); i++){
            int num = W[i] - 97;    // 's' = 18
            vecList[num].push_back(i);      //해당 문자의 인덱스를 넣음.
        }
       
        for(int i = 0; i<26; i++){
            int vsize = (int)vecList[i].size();
            if(vsize >= K){ //조건을 만족하는 후보 알파벳들만 고려해서 탐색함으로써 시간 초과 해결.
                for(int j = 0; j<=vsize - K; j++){  //최소 K개를 포함해야 하므로, 만약 vsize=5이고, K=3이면 j=0,1,2까지만 검사하면 됨.
                    mini = min(mini, vecList[i][j+K-1] - vecList[i][j] + 1);
                    maxi = max(maxi, vecList[i][j+K-1] - vecList[i][j] + 1);
                }
            }
        }
        
        if(mini == 100000 || maxi == 0) cout << -1 << "\n";
        else cout << mini << " " << maxi << "\n";
        
    }
    
    return 0;
}