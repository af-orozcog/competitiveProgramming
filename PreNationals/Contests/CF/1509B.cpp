#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        char see[n+1];
        scanf(" %s",see);
        vector<int> pos;
        bool posi = 1;
        for(int i = 0; i < n;++i){
            if(see[i] != 'M') pos.push_back(i);
        }

        reverse(pos.begin(),pos.end());
        for(int i = 0; i < n && posi;++i){
            if(see[i] == 'M'){
                if(!pos.size() || pos.back() > i) posi = 0;
                else pos.pop_back();
            }
        }

        reverse(pos.begin(),pos.end());
        for(int i = n-1; i > -1 && posi;--i){
            if(see[i] == 'M'){
                if(!pos.size() || pos.back() < i) posi = 0;
                else pos.pop_back();
            }
        }
        if(posi && !pos.size()) puts("YES");
        else puts("NO");
    }
    return 0;
}
