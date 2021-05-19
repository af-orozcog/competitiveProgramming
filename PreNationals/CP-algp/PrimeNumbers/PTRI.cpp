#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll MAX = 100000001;

bitset<100000000> posi;
vector<int> primes;
vector<int> answer1(100000001,-1);
vector<int> answer2(100000001,-1);

void sett(){
    posi.set();
    posi[0] = posi[1] = 0;
    for(ll i = 2; i < MAX;++i){
        if(posi[i]){
            for(ll j = i*i; j < MAX;j+=i) posi[j] = 0;
            primes.push_back((int)i);
        }
    }
    int up = 1;
    for(int i = 1,j = 2,use1 = 1,use2 = 1; i <= primes.size();++i){
        answer1[primes[i-1]] = use1;
        answer2[primes[i-1]] = use2;
        if(i == up){
            use1++;
            up += j;
            j++;
            use2 = 1;
        }
        else ++use2;
    }
}


int main(){
    sett();
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        if(answer1[n] == -1) printf("-1\n");
        else printf("%d %d\n",answer1[n],answer2[n]);
    }
    return 0;
}
