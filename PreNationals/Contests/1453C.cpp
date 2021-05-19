#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef vector<vector<char>> mm;

void calc(vector<int> &miR,vector<int> &maR, vector<int> &miC, vector<int> &maC, mm &matrix){
    int n = matrix.size();
    for(int i = 0; i < n;++i){
        for(int j = 0; j < n;++j){
            int va = matrix[i][j]-'0';
            miR[va] = min(miR[va],i);
            maR[va] = max(maR[va],i);
            maC[va] = max(maC[va],j);
            miC[va] = min(miC[va],j);
        }
    }
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        vector<int> miR(10,INT_MAX),maR(10,INT_MIN),miC(10,INT_MAX),maC(10,INT_MIN);
        mm matrix(n,vector<char>(n));
        for(int i = 0; i < n;++i){
            for(int j = 0; j < n;++j)
                scanf(" %c",&matrix[i][j]);
        }
        calc(miR,maR,miC,maC,matrix);
        vector<int> ans(10,0);
        for(int i = 0; i < n;++i){
            for(int j = 0; j < n;++j){
                int d = matrix[i][j] -'0';
                ans[d] = max(ans[d],max(max(n-i-1,i)*max(abs(miC[d]-j),abs(maC[d]-j)),max(n-j-1,j)*max(abs(maR[d]-i),abs(miR[d]-i))));
            }
        }
        for(auto va: ans) printf("%d ",va);
        puts("");
    }
    return 0;
}
