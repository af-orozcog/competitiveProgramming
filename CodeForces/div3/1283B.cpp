#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        int res = n % k;
        //cout << res << endl;
        if(res > (k >>1)) n -= (res-(k>>1));
        printf("%d\n",n);
    }
    return 0;
}
