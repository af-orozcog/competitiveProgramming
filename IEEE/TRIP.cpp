#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
string a,b;
set<string> weirdDP[100][100];


int main(){
    int t;
    cin >> t;
    bool fi = 0;
    while(t--){
        if(fi) cout << "\n";
        fi = 1;
        cin >> a >> b;
        for(int i = 0; i <= (int)a.size();++i) {dp[i][0] = 0; weirdDP[i][0].insert("");}
        for(int i = 0; i <= (int)b.size();++i){dp[0][i] = 0;weirdDP[i][0].insert("");}
        for(int i = 1; i <= (int)a.size();++i){
            for(int j = 1; j <= (int)b.size();++j){
                weirdDP[i][j].clear();
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                    set<string> add;
                    for(string ve:weirdDP[i-1][j-1]){
                        string ins = ve;
                        ins += a[i-1];
                        add.insert(ins);
                    }
                    weirdDP[i][j] = add;
                }
                else{
                    if(dp[i-1][j] > dp[i][j-1]){
                        set<string> add;
                        for(string ve:weirdDP[i-1][j])
                            add.insert(ve);
                        weirdDP[i][j] = add;
                    }
                    else if(dp[i][j-1] > dp[i-1][j]){
                        set<string> add;
                        for(string ve:weirdDP[i][j-1])
                            add.insert(ve);
                        weirdDP[i][j] = add;
                    }
                    else{
                        set<string> add;
                        for(string ve:weirdDP[i-1][j])
                            add.insert(ve);
                        for(string ve:weirdDP[i][j-1])
                            add.insert(ve);
                        weirdDP[i][j] = add;
                    }
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        for(string va: weirdDP[(int)a.size()][(int)b.size()])
            cout << va << "\n";
    }
    return 0;
}
