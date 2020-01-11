#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    while(scanf(" %d",&n) == 1 && n){
        unordered_set<string> no;
        for(int i = 0; i < n;++i){
            string temp;cin >> temp;
            no.insert(temp);
        }
        cin.ignore();
        while(1){
            string line;
            getline(cin,line);
            if(line.compare("LAST CASE") == 0) break;
            stringstream ss(line);
            string check; ss >> check;
            vector<vector<int>> let(26);
            for(int i = 0; i < check.size();++i)
                let[check[i]-'A'].push_back(i);
            vector<string> useful;
            string temp;
            while(ss >> temp){
                if(no.count(temp)) continue;
                useful.push_back(temp);
            }
            ll dp[useful.size()][check.size()];
            memset(dp,0,sizeof(dp));
            for(int j = 0; j < useful.size();++j){
                temp = useful[j];
                for(int i = 0; i < temp.size();++i){
                    for(auto va:let[temp[i]-'a']){
                        if(va == 0) ++dp[j][0];
                        else{
                            if(j == 0 || va-1 > j)
                                dp[j][va] += dp[j][va-1];
                            if(j != 0) dp[j][va] += dp[j-1][va-1];
                        }
                    }
                }
            }
            ll ans = dp[useful.size()-1][check.size()-1];
            if(ans == 0) cout << check << " is not a valid abbreviation\n";
            else
                cout << check << " can be formed in " << ans << " ways\n";
        }
    }
    return 0;
}
