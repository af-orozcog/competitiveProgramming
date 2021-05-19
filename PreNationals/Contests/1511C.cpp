#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    vector<int> seen(51,INT_MAX);
    int n,q;
    scanf(" %d %d",&n,&q);
    for(int i = 1; i <= n;++i){
        int va;
        scanf(" %d",&va);
        seen[va] = min(seen[va],i);
    }
    int add = 0;
    while(q--){
        int va; scanf(" %d",&va);
        for(int i = 0; i < 51;++i)
            if(seen[va] > seen[i]) ++seen[i];
        printf("%d ",seen[va]);
        seen[va] = 1;
    }
    puts("");
    return 0;
}
