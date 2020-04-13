#include<bits/stdc++.h>
using namespace std;
int A[100000],B[100000],dist[100000];
pair<int,int> who[100000];

int main(){
    int a,b,m;
    scanf(" %d %d %d",&a,&b,&m);
    int mi1 = 1000000000,mi2 = 1000000000;
    for(int i = 0; i < a;++i){scanf(" %d",&A[i]);mi1 = min(mi1,A[i]);}
    for(int i = 0; i < b;++i){scanf(" %d",&B[i]);mi2 = min(mi2,B[i]);}
    int ans = mi1+mi2;
    for(int i = 0; i < m;++i) {
        int ai,bi,ci;
        scanf(" %d %d %d",&ai,&bi,&ci);
        --ai,--bi;
        ans = min(ans,A[ai]+B[bi]-ci);
    }
    printf("%d\n",ans);
    return 0;
}
