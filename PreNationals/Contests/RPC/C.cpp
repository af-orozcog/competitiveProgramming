#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int m,n;
    while(scanf(" %d %d",&m,&n) == 2){

        unordered_set<int> fi,se;
        for(int i = 0; i < m;++i){
            int re;scanf(" %d",&re);
            fi.insert(re);
        }
        for(int i = 0; i < n;++i){
            int re;scanf(" %d",&re);
            se.insert(re);
        }
        int ans1 = m,ans2 = 0,ans3 = n,ans4 = n+m;
        for(auto &va:se){
            if(fi.count(va)) --ans1,--ans3,--ans4,++ans2;
        }
        printf("%d %d %d %d\n",ans1,ans2,ans3,ans4);
    }
    return 0;
}
