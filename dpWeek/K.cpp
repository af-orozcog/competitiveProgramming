#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#define ll long long
using namespace std;

ll dp[20][50];
int ne[20][50];
vector<char> let;

ll solve(int p, int l, map<char,int> &fr){
    if(p == 12 && l == let.size()) return 0;
    if(l != let.size() && p == 12) return 10000000000000ll;
    if(dp[p][l] != -1) return dp[p][l];
    ll add = 0;
    ll sum = 10000000000000ll;
    int who;
    for(ll i = l,j = 1; i < let.size();++i,++j){
        add += fr[let[i]]*j;
        if(add + solve(p+1,i+1,fr) < sum){
            sum = add + solve(p+1,i+1,fr);
            who = i+1;
        }
    }
    dp[p][l] = sum;
    ne[p][l] = who;
    return dp[p][l];
}

vector<char> ans;

int main(){
    int t;
    scanf(" %d",&t);
    for(int i = 0; i < 26;++i)
        let.push_back('a'+i);
    let.push_back('+');
    let.push_back('*');
    let.push_back('/');
    let.push_back('?');
    while(t--){
        memset(dp,-1,sizeof(dp));
        int m; scanf(" %d",&m);
        map<char,int> fr;
        while(m--){
            char re[32];
            scanf(" %s",re);
            for(int i = 0; re[i] != '\0';++i)
                ++fr[re[i]];
        }
        int mi = solve(0,0,fr);
        ans.clear();
        int i = ne[0][0], j = 0;
        while(j < 12){
            ans.push_back(let[i]);
            ++j;
            i = ne[j][i];
        }
        for(int i = 0; i < ans.size();++i) printf("%c",ans[i]);
        puts("");
    }
}
