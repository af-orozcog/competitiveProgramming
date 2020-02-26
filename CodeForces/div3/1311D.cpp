#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int a,b,c;
        scanf(" %d %d %d",&a,&b,&c);
        int mod1 = b %a;
        int ans = 2000000000;
        int who1,who2,who3;
        for(int i = 1; i <= c;++i){
            for(int j = i ;j <= c +i;j += i){
                if(j%i != 0) continue;
                int add = min(j-(c%j),c%j);
                int dist = abs(i-a) + abs(b-j) + add;
                if(dist < ans){
                    ans = dist;
                    who1 = i,who2 = j;
                    if(add == j-(c%j)) who3 = c + j-(c%j);
                    else who3 = c - (c%j);
                }
            }
        }
        printf("%d\n",ans);
        printf("%d %d %d\n",who1,who2,who3);
    }
    return 0;
}
