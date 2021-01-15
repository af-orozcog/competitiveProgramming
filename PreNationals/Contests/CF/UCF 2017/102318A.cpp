#include<bits/stdc++.h>
#define ll long long
using namespace std;

int imp = 1000;

int main(){
    int f,s;
    scanf(" %d %d",&f,&s);
    int n;
    scanf(" %d",&n);
    while(n--){
        int val;
        scanf(" %d",&val);
        int temp = val;
        int ans = min(imp,val)*f;
        val -= min(imp,val);
        ans += val*s;
        printf("%d %d\n",temp,ans);
    }
    return 0;
}
