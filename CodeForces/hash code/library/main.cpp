#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

struct library{
    int regTime, amoun, di;
    vector<pi> sco;
};

int scores[1000000];

bool comp(struct library &a, struct library &b){
    return a.regTime <= b.regTime;
}

int main(){
    freopen("1.in","r",stdin);
    int b,l,d;
    scanf(" %d %d %d",&b,&l,&d);
    for(int i = 0; i < b;++i) scanf(" %d",&scores[i]);
    vector<library> lib;
    for(int i = 0; i < l;++i){
        struct library add;
        add.di = i;
        int n; scanf(" %d",&n);
        scanf(" %d",&add.regTime);
        int m; scanf(" %d",&add.amoun);
        int tot = 0;
        for(int j = 0; j < n;++j){
            int id;scanf(" %d",&id);
            add.sco.push_back({-scores[id],id});
        }
        sort(add.sco.begin(),add.sco.end());
        lib.push_back(add);
    }
    sort(lib.begin(),lib.end(),comp);
    vector<int> used(b,-1);
    int temp = 0;
    for(int i = 0; i < l;++i){
        int daysLeft = d - temp - lib[i].regTime;
        if(daysLeft <= 0) break;
        for(int j = 0; j < min(daysLeft*lib[i].amoun,(int)lib[i].sco.size());++j)
            used[lib[i].sco[j].second] = lib[i].di;
        temp += lib[i].regTime;
    }
    unordered_map<int,vector<int>> machete;
    for(int i = 0; i < used.size();++i){
        if(used[i] != -1)
            machete[used[i]].push_back(i);
    }
    printf("%d\n",(int)machete.size());
    for(auto &va: machete){
        printf("%d %d\n",va.first,va.second.size());
        for(auto ve: va.second) printf("%d " ,ve);
        puts("");
    }
    return 0;
}
