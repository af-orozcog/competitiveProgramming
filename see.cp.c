#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,ll> pi;

ll dp[(2000*2000)+2];

int main(){
    int n;
    scanf(" %d",&n);
    pi nums[n];
    int tim = 0;
    for(int i = 0; i < n;++i){
        scanf(" %d %lld",&nums[i].first,&nums[i].second);
        tim += nums[i].first;
    }
}
