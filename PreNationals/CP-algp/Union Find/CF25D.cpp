#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
vector<int> UF;

int search(int x){
    return UF[x] == x ? x:(UF[x] = search(UF[x]));
}

bool connected(int x, int y){
    return search(x) == search(y);
}

void connect(int x, int y){
    int dadX = search(x), dadY = search(y);
    if(dadX != dadY)
        UF[dadX] = dadY;
}

int main(){
    int n;
    scanf(" %d",&n);
    UF.resize(n);
    for(int i = 0; i < n;++i) UF[i] = i;
    vector<pi> edges;
    for(int i = 0; i < n-1;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        if(connected(a,b)) edges.push_back({a,b});
        else connect(a,b);
    }
    set<int> dads;
    for(int i = 0; i < n;++i) dads.insert(search(i));
    vector<int> posi;
    for(auto &va:dads) posi.push_back(va);
    vector<pair<pi,pi>> answer;
    for(int i = 0; i < edges.size();++i)
        answer.push_back({{edges[i].first,edges[i].second},{posi[0],posi[i+1]}});

    printf("%d\n",(int)answer.size());
    for(auto &ans:answer)
        printf("%d %d %d %d\n",ans.first.first+1,ans.first.second+1,ans.second.first+1,ans.second.second+1);
    return 0;
}
