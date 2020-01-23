#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        char va[n];
        int ans = 0;
        for(int i = 0; i < n;++i)scanf(" %c",&va[i]);
        for(int i = 0; i < n;){
            if(va[i] == '1') i+=2;
            else if(i == 0 && va[i+1] == '0') ++ans,i+=2;
            else if(i == n-1 && va[i-1] == '0') ++ans,i+=2;
            else if(va[i+1] == '0' && va[i-1] == '0') ++ans,i+=2;
            else ++i;
        }
        printf("%d\n",ans);
    }
    return 0;
}
