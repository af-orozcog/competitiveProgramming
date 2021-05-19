#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int n;
    scanf(" %d",&n);
    int mi = -1;
    int ma = INT_MAX;
    for(int i = 0; i < n;++i){
        int va;
        scanf(" %d",&va);
        mi = max(mi,va);
    }
    for(int i = 0; i < n;++i){
        int va; scanf(" %d",&va);
        ma = min(ma,va);
    }
    printf("%d\n",max(ma-mi+1,0));
    return 0;
}
