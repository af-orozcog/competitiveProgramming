#include<bits/stdc++.h>
using namespace std;

vector<int> phi(int n){
    vector<int> answer(n+1);
    for(int i = 0; i <= n;++i)
        answer[i] = i;
    for(int i = 2; i <= n;++i){
        if(answer[i] == i){
            for(int j = i; j <= n; j+=i)
                answer[j] -= answer[j]/i;
        }
    }
    return answer;
}

int main(){
    vector<int> deep = phi(2000001);
    deep[1] = 0;
    for(int i = 2; i < deep.size();++i){
        int temp = deep[deep[i]] + 1;
        deep[i] = temp;
    }
    vector<int> sum(deep.size(),0);
    for(int i = 1; i < sum.size();++i)
        sum[i] += sum[i-1]+deep[i];
    int t;
    scanf(" %d",&t);
    while(t--){
        int l,r;
        scanf(" %d %d",&l,&r);
        printf("%d\n",sum[r]-sum[l-1]);
    }
    return 0;
}
