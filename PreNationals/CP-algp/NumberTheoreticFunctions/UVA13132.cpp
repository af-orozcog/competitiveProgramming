#include<bits/stdc++.h>
using namespace std;

vector<int> phi(int n){
    vector<int> answer(n+1);
    for(int i = 0; i <= n;++i)
        answer[i] = i;

    for(int i = 2; i <= n;++i){
        if(answer[i] == i){
            for(int j = i; j <= n;j+=i)
                answer[j] -= answer[j]/i;
        }
    }
    return answer;
}


int main(){
    int t;
    scanf(" %d",&t);
    vector<int> use = phi(100000);
    while(t--){
        int n;
        scanf(" %d",&n);
        printf("%d\n",use[n]);
    }
    return 0;
}
