#include<bits/std++.h>
using namespace std;

int main(){
    string a,b;
    while(cin>> a >> b){
        int dp[(int)a.size()+1][(int)b.size()+1];
        for(int i = 0; i <= (int)a.size();++i) dp[i][0] = i;
        for(int i = 0; i <= (int)b.size();++i) dp[0][i] = i;
        for(int i = 1; i <= (int)a.size();++i){
            for(int j = 1; j <= (int)b.size();++j){
                dp[i][j] = dp[i][j-1] + (a[i-1] != b[j-1]);
                dp[i][j] = min(dp[i][j],dp[i-1][j]);
                dp[i][j] = min(dp[i][j],dp[i][j-1]);
            }
        }
        int i = a.size();
        int j = b.size();
        vector<string> delete;
        vector<int> position;
        vector<char> letter;
        while(i != 0 || j != 0){
            if(dp[i][j])
        }
    }
}
