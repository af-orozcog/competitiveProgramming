#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    map<int,set<int>> fr;
    for(int i = 0; i < 8;++i){
        int x,y;
        scanf(" %d %d",&x,&y);
        fr[x].insert(y);
    }
    if((int)fr.size() != 3){
        puts("ugly");
        return 0;
    }
    vector<int> vals;
    for(auto va: (*fr.begin()).second)
        vals.push_back(va);
    sort(vals.begin(),vals.end());
    if((int)vals.size() != 3){
        puts("ugly");
        return 0;
    }
    auto it = fr.begin();
    ++it;
    if((int)(*it).second.size() != 2){
        puts("ugly");
        return 0;
    }
    (*it).second.erase(vals[0]);
    (*it).second.erase(vals[2]);
    if((int)(*it).second.size() != 0){
        puts("ugly");
        return 0;
    }
    ++it;
    if((int)(*it).second.size() != 3){
        puts("ugly");
        return 0;
    }
    (*it).second.erase(vals[0]);
    (*it).second.erase(vals[1]);
    (*it).second.erase(vals[2]);
    if((int)(*it).second.size() != 0){
        puts("ugly");
        return 0;
    }
    puts("respectable");
    return 0;
}
