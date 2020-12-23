#include<bits/stdc++.h>
using namespace std;

vector<int> phi(int n){
    vector<int> phi(n+1);

    for(int i = 0; i <= n;++i)
        phi[i] = i;

    for(int i = 2; i <= n;++i){
        if(phi[i] == i){
            for(int j = i; j <= n;j+=i)
                phi[j] -= phi[j]/i;
        }
    }
    return phi;
}


int main(){
    vector<int> ans = phi(1000001);
    int t;
    scanf("%d ",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
