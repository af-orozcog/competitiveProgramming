#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int main(){
    string see;
    while(getline(cin,see)){
        for(int i = 0; i < see.size();++i){
            dp[i][i] = 0;
            if(i != (int)see.size())
                dp[i][i+1] = (see[i] != see[i+1]);
        }
        for(int i = 2; i <= (int)see.size()-1;++i){
            for(int j = 0; j < (int)see.size();++j){
                if(j+i == (int)see.size())break;
                if(see[j] == see[j+i])
                    dp[j][j+i] = dp[j+1][j+i-1];
                else
                    dp[j][j+i] = min(dp[j+1][j+i],dp[j][j+i-1])+1;
                //cout << dp[j][j+i] << " " << j << " " << j+i << "\n";
            }
        }
        cout << dp[0][(int)see.size()-1] << " ";
        vector<char> ans((int)see.size()+dp[0][(int)see.size()-1]);
        int i = 0,j = (int)see.size()-1;
        int l = 0, r = (int)ans.size()-1;
        while(i <= j){
            if(see[i] == see[j]){
                ans[l] = ans[r] = see[i];
                ++i,++l,--r,--j;
            }
            else if(dp[i+1][j] < dp[i][j-1]){
                ans[l] = ans[r] = see[i];
                ++i,++l,--r;
            }
            else{
                ans[l] = ans[r] = see[j];
                ++l,--j,--r;
            }
        }
        for(auto va:ans)
            cout << va;
        cout << "\n";
    }
    return 0;
}
