#include<bits/stdc++.h>
#define ll long long
using namespace std;

int used[500];

int main(){
    int n;
    scanf(" %d",&n);
    ll matrix[n][n];
    for(int i = 0; i < n;++i){
        for(int j = 0; j < n;++j){
            scanf(" %lld",&matrix[i][j]);
            if(matrix[i][j] == 0) matrix[i][j] = 1000000000ll;
        }
        matrix[i][i] = 0ll;
    }
    int vals[n];
    for(int i = 0; i < n;++i) scanf(" %d",&vals[i]);
    ll ans[n];
    for(int k = n-1;k > -1;--k){
        used[vals[k]-1] = 1;
        ll sum = 0;
        for(int i = 0; i < n;++i){
            for(int j = 0; j < n;++j){
                matrix[i][j] = min(matrix[i][j], matrix[i][vals[k]-1] + matrix[vals[k]-1][j]);
                if(matrix[i][j] != 1000000000ll && used[i] && used[j])
                    sum += (ll)matrix[i][j];
            }
        }
        ans[k] = sum;
    }
    for(int i = 0; i < n;++i) printf("%d ",ans[i]);
    puts("");
    return 0;
}
