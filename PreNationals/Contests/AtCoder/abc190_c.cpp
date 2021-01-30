#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int count(pi conditions[],int m, int vals[]){
    int ans = 0;
    for(int i = 0; i < m;++i){
        int check = (vals[conditions[i].first-1]>0) + (vals[conditions[i].second-1]>0);
        ans += (check==2);
    }
    return ans;
}


int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    pi conditions[m];
    for(int i = 0; i < m;++i) scanf(" %d %d",&conditions[i].first,&conditions[i].second);
    int k;
    scanf(" %d",&k);
    pi where[k];
    for(int i = 0; i < k;++i) scanf(" %d %d",&where[i].first,&where[i].second);
    int vals[n];
    memset(vals,0,sizeof(vals));
    int ans = 0;
    for(int i = 0; i < (1<<k);++i){
        for(int j = 0, temp = i; j < k;++j){
            if(temp&1)
                ++vals[where[j].second-1];
            else
                ++vals[where[j].first-1];
            temp >>= 1;
        }
        ans = max(ans,count(conditions,m,vals));
        memset(vals,0,sizeof(vals));
    }
    printf("%d\n",ans);
    return 0;
}
