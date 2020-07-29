#include<bits/stdc++.h>
#define ll long long
using namespace std;

int memo[200];

void solve(vector<vector<char>> &ans,int col,int tama,int orr){
    int siz = (int)ans.size()-tama;
    siz>>=1;
    int j = siz;
    if(orr == -1) ans[j][col-1] = '-';
    else ans[j][col+1] = '-';
    ans[j][col] = '+';
    ++j;
    for(int i = 0; i < tama-2;++i,++j)
        ans[j][col] = '|';
    ans[j][col] = '+';
    if(orr == -1) ans[j][col-1] = '-';
    else ans[j][col+1] = '-';
}

int main(){
    int n;
    scanf(" %d",&n);
    vector<int> last;
    char see[n];
    int biggest = 0;
    for(int i = 0; i < n;++i){
        char va; scanf(" %c",&va);
        see[i] = va;
        if(va == '[') last.push_back(i);
        else{
            memo[last.back()] = (int)last.size()-1;
            memo[i] = memo[last.back()];
            last.pop_back();
            biggest = max(biggest,memo[i]);
        }
    }
    vector<vector<char>> ans(3+biggest*2,vector<char>(1000,' '));
    int special = 0;
    for(int i = 0,j = 0; i < n;++i,++j){
        int depth = biggest-memo[i];
        if(see[i] == '[')
            solve(ans,j,depth*2+3,1);
        else
            solve(ans,j,depth*2+3,-1);
        if(see[i] == '[' && i != n-1 && see[i+1] == ']' && biggest-memo[i+1] == depth)
            j+=3,++special;
    }
    for(int i = 0; i < ans.size();++i){
        for(int j = 0; j < n+special*3;++j)
            printf("%c",ans[i][j]);
        puts("");
    }
    return 0;
}
