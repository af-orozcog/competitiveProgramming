#include<bits/stdc++.h>
#define ll long long
using namespace std;

int K = 25;

int lg2[1000000];

int main(){
    lg2[1] = 0;
    for(int i = 2; i < 1000000;++i)
        lg2[i] = lg2[i>>1] + 1;
    int n,m,a;
    scanf(" %d %d %d",&n,&m,&a);
    int st[m][n][K+1];
    for(int i = 0; i < n;++i){
        for(int j = 0; j < m;++j)
            scanf(" %d",&st[j][i][0]);
    }
    for(int i = 1; i <= K;++i){
        for(int j = 0; (j+(1<<i)) <= n;++j){
            for(int z = 0; z < m;++z){
                st[z][j][i] = max(st[z][j][i-1],st[z][j+(1<<(i-1))][i-1]);
            }
        }
    }
    vector<int> show(m,0);
    vector<int> each(m,0);
    int lo = 1, hi = n, ans = 0;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        int imp = lg2[mid];
        bool found = 0;
        for(int i = 0; i <= n-mid && !found;++i){
            ll sum = 0;
            int second = (i+mid-(1<<imp));
            for(int j = 0; j < m;++j){
                each[j] = max(st[j][i][imp],st[j][second][imp]);
                sum += (ll)max(st[j][i][imp],st[j][second][imp]);
            }
            if(sum <= (ll)a) found = 1;
        }
        if(found){
            ans = mid;
            show = each;
            lo = mid +1;
        }
        else
            hi = mid -1;
    }
    for(auto va:show)
        printf("%d ",va);
    puts("");
    return 0;
}
