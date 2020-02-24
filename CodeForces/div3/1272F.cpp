#include<bits/stdc++.h>
using namespace std;

int dp[202][202][402];
string a,b;

int solve(int p, int q, int pl){
    if(pl > 400) return 1000000000;
    if(p == a.size() && q == b.size()) return dp[p][q][pl] = pl;
    if(dp[p][q][pl] != -1) return dp[p][q][pl];
    int neP = p, neQ = q;
    int ans = 1000000000;
    if(p!= a.size() && a[p] == '(') ++neP;
    if(q != b.size() && b[q] == '(') ++neQ;
    ans = min(ans,solve(neP,neQ,pl+1)+1);
    neP = p,neQ = q;
    if(p != a.size() && a[p] == ')') ++neP;
    if(q != b.size() && b[q] == ')') ++neQ;
    if(pl-1 >= 0)
        ans = min(ans,solve(neP,neQ,pl-1)+1);
    return dp[p][q][pl] = ans;
}

string ans = "";
int movX[] = {0,1,0,1};
int movY[] = {0,0,1,1};
int wt[] = {1,-1};

void answer(int p, int q, int pl, int tar){
    if(p == a.size() && b.size() == q){
        for(int i = 0; i < pl;++i) ans += ')';
        return;
    }
    int anss = 1000000000;
    int who;
    int toP,toQ,toPl;
    for(int i = 0; i < 2;++i){
        int nePl = pl + wt[i];
        if(nePl < 0) continue;
        for(int j = 0; j < 4;++j){
            int neP = p + movX[j], neQ = q + movY[j];
            if(neP > a.size() || neQ > b.size()) continue;
            if(dp[neP][neQ][nePl] == tar-1){
                toP = neP, toQ = neQ, toPl = nePl;
                who = i;
                break;
            }
        }
    }
    if(!who) ans += '(';
    else ans += ')';
    answer(toP,toQ,toPl,tar-1);
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> a >> b;
    //printf("%d\n",solve(0,0,0));
    int anss = solve(0,0,0);
    answer(0,0,0,anss);
    cout << ans << "\n";
    return 0;
}
