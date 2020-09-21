#include<bits/stdc++.h>
#define ld long double
using namespace std;
typedef pair<int,int> pi;
#define EPS 1e-8

int n,m;

int answer(ld x1,ld y1,ld x2, ld y2, pair<int,pi> fences[]){
    int ans = 0;
    for(int i = 0; i < m;++i){
        ld dist1 = (x1-(ld)fences[i].second.first)*(x1-(ld)fences[i].second.first) + (y1-(ld)fences[i].second.second)*(y1-(ld)fences[i].second.second);
        ld dist2 = (x2-(ld)fences[i].second.first)*(x2-(ld)fences[i].second.first) + (y2-(ld)fences[i].second.second)*(y2-(ld)fences[i].second.second);
        dist1 = sqrt(dist1);
        dist2 = sqrt(dist2);
        bool f1 = 0,f2 = 0;
        if(dist1-(ld)fences[i].first > EPS)
            f1 = 1;
        if(dist2-(ld)fences[i].first > EPS)
            f2 = 1;
        if(f1 != f2) ++ans;
    }
    return ans;
}

int main(){
    int k;
    scanf(" %d %d %d",&n,&m,&k);
    pi control[n];
    for(int i = 0; i < n;++i)
        scanf(" %d %d",&control[i].first,&control[i].second);
    pair<int,pi> fences[m];
    for(int i = 0; i < m;++i)
        scanf(" %d %d %d",&fences[i].first,&fences[i].second.first,&fences[i].second.second);
    while(k--){
        int f,t;
        scanf(" %d %d",&f,&t);
        --f,--t;
        if(f == t){puts("0");continue;}
        printf("%d\n",answer(control[f].first,control[f].second,control[t].first,control[t].second,fences));
    }
    return 0;
}
