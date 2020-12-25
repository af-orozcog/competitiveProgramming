#include<bits/stdc++.h>
using namespace std;

int dp[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin >> a >> b;
    for(int i = 0; i < a.size();++i){
        for(int j = 1000; j > -1;--j){
            if(i+j < a.size())
                dp[j] = max(dp[j] + (a[i+j] == b[i]),(j > 0? dp[j-1]:0));
        }
    }
    int ma = 0;
    for(int i = 0; i < 1001;++i)
        ma = max(ma,dp[i]);
    if(ma*100 >= (int)a.size()*99)
        puts("Long lost brothers D:");
    else puts("Not brothers :(");
    return 0;
}
