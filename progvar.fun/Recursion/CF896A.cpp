#include<bits/stdc++.h>
#define ll long long
using namespace std;

string important = "What are you doing at the end of the world? Are you busy? Will you save us?";
string part1 = "What are you doing while sending \"";
string part2 = "\"? Are you busy? Will you send \"";
string part3 = "\"?";
vector<ll> dp;


void initia(){
    dp.push_back(important.size());
    for(int i = 1; i < 55;++i){
        ll temp = dp.back();
        temp <<= 1;
        temp += (ll)part1.size() + (ll)part2.size() + (ll)part3.size();
        dp.push_back(temp);
    }
}


char getLetter(int from, ll n){
    if(from < 53 && n>dp[from]) return '.';
    if(from == 0) return important[n-1];
    if(n <= 34ll) return part1[n-1];
    if(from >= 54 || n <= dp[from-1]+34ll) return getLetter(from-1,n-34ll);
    if(n <= dp[from-1]+66ll) return part2[n-dp[from-1]-35ll];
    if(n >= dp[from]-1) return part3[1-(dp[from]-n)];
    return getLetter(from-1,n-dp[from-1]-66ll);
}

int main(){
    initia();
    //cout << dp.back() << "\n";
    //printf("%lld\n",dp[1]);
    int q;
    scanf(" %d",&q);
    while(q--){
        ll n,k;
        scanf(" %lld %lld",&n,&k);
        printf("%c",getLetter(n,k));
    }
    puts("");
    return 0;
}
