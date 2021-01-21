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
        char b[n+1];
        scanf(" %s",b);
        int last = -1;
        char a[n+1];
        a[n] = '\0';
        for(int i = 0; i < n;++i){
            int val = b[i]-'0';
            if(val + 1 != last)
                a[i] = '1',last = val+1;
            else
                a[i] = '0',last = val;
        }
        printf("%s\n",a);
    }
    return 0;
}
