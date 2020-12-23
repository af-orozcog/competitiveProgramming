#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> answer;
vector<ll> preCalc;
void phi(int n){
    answer.resize(n+1);
    preCalc.resize(n+1,1);
    for(int i = 0; i <= n;++i)
        answer[i] = i;

    for(int i = 2; i <= n;++i){
        if(answer[i] == i){
            for(int j = i; j <= n;j+=i)
                answer[j] -= answer[j]/i;
        }
    }
    for(int i = 2; i <=n;++i){
        for(int j = i; j <= n;j+=i){
            preCalc[j] += ((ll)i * answer[i]);
        }
    }
    for(int i = 2; i <= n;++i){
        ++preCalc[i];
        preCalc[i] *= (ll)i;
        preCalc[i] >>= 1;
    }
}


int main(){
    phi(1000000);
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        printf("%lld\n",preCalc[n]);
    }
    return 0;
}
