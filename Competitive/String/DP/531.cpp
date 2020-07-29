#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> a,b;
    string temp;
    while(getline(cin,temp)){
        a.clear();b.clear();
        string see;
        while(1){
            stringstream ss(temp);
            int keep = 1;
            while(ss >> see){
                if(see[0] == '#'){keep = 0;break;}
                a.push_back(see);
            }
            if(!keep)break;
            getline(cin,temp);
        }
        getline(cin,temp);
        while(1){
            stringstream ss(temp);
            int keep = 1;
            while(ss >> see){
                if(see[0] == '#'){keep = 0;break;}
                b.push_back(see);
            }
            if(!keep)break;
            getline(cin,temp);
        }
        int dp[(int)a.size()+1][(int)b.size()+1];
        for(int i = 0; i <= (int)a.size();++i) dp[i][0] = 0;
        for(int i = 0; i <= (int)b.size();++i) dp[0][i] = 0;
        for(int i = 1; i <= (int)a.size();++i){
            for(int j = 1; j <= (int)b.size();++j){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(a[i-1] == b[j-1])
                    dp[i][j] = max(1 + dp[i-1][j-1],dp[i][j]);
            }
        }
        vector<string> ans;
        int i = a.size(),j = b.size();
        while(i != 0 || j != 0){
            int next = -1;
            int neI = i, neJ = j;
            int seen = 0;
            if(i && j && a[i-1] == b[j-1] && dp[i-1][j-1] > next){
                ans.push_back(a[i-1]);
                seen = 1;
                next = dp[i-1][j-1];
                neI = i -1, neJ = j-1;
            }
            if(i && dp[i-1][j] > next){
                if(seen) ans.pop_back();
                seen = 0;
                next = dp[i-1][j];
                neI = i-1, neJ = j;
            }
            if(j && dp[i][j-1] > next){
                if(seen) ans.pop_back();
                seen = 0;
                next = dp[i][j-1];
                neJ = j-1, neI = i;
            }
            i = neI,j = neJ;
        }
        reverse(ans.begin(),ans.end());
        for(int i = 0; i < ans.size();++i){
            if(i) cout << " ";
            cout << ans[i];
        }
        cout <<"\n";
    }
    return 0;
}
