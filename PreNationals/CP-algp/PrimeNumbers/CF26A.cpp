#include<bits/stdc++.h>
using namespace std;

vector<int> posi;


int main(){
    int n;
    scanf(" %d",&n);
    posi.resize(n+1,1);
    posi[0] = posi[1] = 0;
    for(int i = 2; i < posi.size();++i){
        if(posi[i] == 1){
            for(int j = i*2; j < posi.size();j+=i) ++posi[j];
        }
    }
    for(int i = 2; i < posi.size();++i)
        posi[i] = (posi[i] == 3) + posi[i-1];
    printf("%d\n",posi.back());
    return 0;
}
