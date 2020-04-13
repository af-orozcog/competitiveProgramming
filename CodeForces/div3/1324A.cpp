#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int ar[] = {0,0};
        int n;
        scanf(" %d",&n);
        while(n--){
            int va;scanf(" %d",&va);
            ++ar[va&1];
        }
        if((ar[0] && !ar[1]) || (!ar[0] && ar[1])) puts("YES");
        else puts("NO");
    }
    return 0;
}
