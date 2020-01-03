#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    set<pair<int,int>> fr;
    set<int> used;
    for(int i = 0; i < n;++i){
        int va; scanf(" %d",&va);
        used.insert(va);
        if(!used.count(va-1))
            fr.insert({1,va-1});
        if(!used.count(va+1))
            fr.insert({1,va+1});
        fr.erase({1,va});
    }
    int ans[m];
    ll dist = 0;
    for(int i = 0; i < m;++i){
        pair<int,int> va = *(fr.begin());
        fr.erase(fr.begin());
        if(used.count(va.second)){--i;continue;}
        ans[i] = va.second;
        dist += (ll)va.first;
        used.insert(va.second);
        if(!used.count(va.second-1))
            fr.insert({va.first+1,va.second-1});
        if(!used.count(va.second+1))
            fr.insert({va.first+1,va.second+1});
    }
    cout << dist << endl;
    for(int i = 0; i < m;++i)
        printf("%d ",ans[i]);
    puts("");
    return 0;
}
