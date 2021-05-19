#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        char see1[n+1],see2[n+1];
        scanf(" %s %s",see1,see2);
        int lets1[27],lets2[27];
        memset(lets1,0,sizeof(lets1));
        memset(lets2,0,sizeof(lets2));
        for(int i = 0; i < n;++i){
            ++lets1[see1[i]-'a'];
            ++lets2[see2[i]-'a'];
        }
        bool posi = 1;
        for(int i = 0; i < 26;++i){
            if(lets1[i] < lets2[i]) posi = 0;
            else{
                lets1[i] -= lets2[i];
                if((i != 25 && lets1[i] % k != 0) || (i == 25 && lets1[i] != 0)) posi = 0;
                else if(i != 25) lets1[i+1] += lets1[i];
            }
        }

        if(posi) puts("Yes");
        else puts("No");
    }
    return 0;
}
