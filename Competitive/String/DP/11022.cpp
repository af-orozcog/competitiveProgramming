#include<bits/stdc++.h>
using namespace std;

int dp[90][90];
int kmp[100];
string line;

int specialFactoring(int l, int r){
    kmp[l] = 0;
    int border = 0;
    for(int i = l+1; i <= r;++i){
        while(border > 0 && line[i] != line[border+l])
            border = kmp[l+border-1];
        if(line[l+border] == line[i])
            ++border;
        else border = 0;
        kmp[i] = border;
    }
    int check = r-l+1-kmp[r];
    if((r-l+1)%check == 0)
        return check;
    else return r-l+1;
}
int main(){
    while(getline(cin,line)){
        if(line[0] == '*')break;
        for(int i = 0; i < (int)line.size();++i)
            dp[i][i] = 1;
        for(int i = 1; i <= (int)line.size()-1;++i){
            for(int j = 0; j + i < (int)line.size();++j){
                dp[j][j+i] = specialFactoring(j,j+i);
                if(dp[j][j+i] < i+1)
                    dp[j][j+i] = min(dp[j][j+i],dp[j][j+dp[j][j+i]-1]);
                for(int k = j; k < j+i;++k){
                    dp[j][j+i] = min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]);
                }
            }
        }
        printf("%d\n",dp[0][(int)line.size()-1]);
    }
    return 0;
}

