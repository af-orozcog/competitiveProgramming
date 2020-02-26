#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        int ar[n];
        for(int i = 0; i < n;++i) scanf(" %d",&ar[i]);
        set<int> moves;
        for(int i = 0; i < m;++i){
            int va;scanf(" %d",&va);
            --va;
            moves.insert(va);
        }
        bool posi = 1;
        for(int i = 1; i < n && posi;++i){
            int temp = i;
            while(temp > 0 && ar[temp] < ar[temp-1] && posi){
                if(moves.count(temp-1)){
                    swap(ar[temp],ar[temp-1]);
                    --temp;
                }
                else posi = 0;
            }
        }
        if(posi) puts("YES");
        else puts("NO");
    }
    return 0;
}
