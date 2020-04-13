#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        char ar[n+1];
        char ans1[n+1];
        char ans2[n+1];
        ans1[n] = ans2[n] = '\0';
        scanf(" %s",ar);
        bool ca = 0;
        ans1[0] = ans2[0] = '1';
        for(int i = 1; i < n;++i){
            if(ca){
                ans1[i] = '0';
                ans2[i] = ar[i];
            }
            else if(ar[i] != '1'){
                if(ar[i] == '2') ans1[i] = ans2[i] = '1';
                else ans1[i] = ans2[i] = '0';
            }
            else
                ans1[i] = ar[i], ans2[i] = '0',ca = 1;
        }
        printf("%s\n%s\n",ans1,ans2);
    }
    return 0;
}
