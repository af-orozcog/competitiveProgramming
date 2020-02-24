/**
* R.I.P KOBE
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;scanf(" %d",&n);
        int sum = 0;
        int zero = 0;
        for(int i = 0; i < n;++i){
            int va;scanf(" %d",&va);
            sum += va;
            if(!va) ++zero;
        }
        int ans = zero;
        sum += zero;
        if(!sum) ++ans;
        printf("%d\n",ans);
    }
    return 0;
}
