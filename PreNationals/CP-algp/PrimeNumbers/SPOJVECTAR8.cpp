#include<bits/stdc++.h>
using namespace std;

bitset<1000001> posi;
vector<int> primes;
vector<int> sums(1000001,0);

bool check(int val){
    string see = to_string(val);
    for(auto let:see)
        if(let == '0') return 0;

    for(int i = 0; i < see.size();++i){
        int isPrime = stoi(see.substr(i,see.size()));
        if(!posi[isPrime])
            return 0;
    }
    return 1;
}

int main(){
    int upTo = sqrt(1000001);
    posi.set();
    posi[0] = posi[1] = 0;
    for(int i = 2; i <= upTo;++i){
        if(posi[i]){
            for(int j = i*i; j < 1000001;j+=i)posi[j] = 0;
        }
    }
    cout << posi[5] << "\n";
    for(int i = 2; i < 1000001;++i){
        if(posi[i] && check(i))
            sums[i]++;
    }
    for(int i = 1; i < 1000001;++i)
        sums[i] += sums[i-1];
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        printf("%d\n",sums[n]);
    }
    return 0;
}
