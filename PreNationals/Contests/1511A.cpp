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
        int down[2],up[2];
        memset(down,0,sizeof(down));
        memset(up,0,sizeof(up));
        for(int i = 0; i < n;++i){
            int type; scanf(" %d",&type);
            int see1 = up[0]-down[0];
            int see2 = up[1]-down[1];
            if(type == 1){
                if(see1 > see2) ++up[0];
                else up[1];
            }
            else if(type == 2){
                if(see1 < see2) ++down[0];
                else ++down[1];
            }
            else{
                if(see1 < see2){
                    if(see2 < 0) ++down[0];
                    else ++up[1];
                }
                else{
                    if(see1 < 0) ++down[1];
                    else ++up[0];
                }
            }
        }
        printf("%d\n",up[0]+up[1]);
    }
    return 0;
}
