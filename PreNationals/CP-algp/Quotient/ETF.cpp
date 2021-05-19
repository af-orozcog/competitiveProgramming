#include<bits/stdc++.h>
using namespace std;

int MAX = 1000002;

vector<int> phi(1000002);

void sett(){
    phi[0] = 0;
    phi[1] = 1;

    for(int i = 2; i < MAX;++i)
        phi[i] = i;

    for(int i = 2; i < MAX;++i){
        if(phi[i] == i){
            for(int j = i; j < MAX;j+=i)
                phi[j] -= phi[j]/i;
        }
    }
}

int main(){
    sett();
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        printf("%d\n",phi[n]);
    }
    return 0;
}
