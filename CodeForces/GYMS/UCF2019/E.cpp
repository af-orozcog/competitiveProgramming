#include<bits/stdc++.h>
#define ll long long
using namespace std;


bitset<2000002> po,po2;
int n,k;

int main(){
    scanf(" %d %d",&n,&k);
    //cout << "wut\n";
    po.set();
    po[0] = po[0] = 0;
    for(ll i = 2; i < (ll)2000002;++i){
        if(po[i] == 1){
            //cout << po[i] << endl;
            for(ll j = i*i; j < (ll)2000002;j+=i) po[j] = 0;
           // cout << "wut " << po[i] <<"\n";
        }
    }
    po2.set();
    po2[0] = po2[1] = 0;
    for(ll i = 2; i <= (ll)n;++i){
        if(po2[i] == 1){
            for(ll j = i*i; j < (ll)2000002;j+=i) po2[j] = 0;
        }
    }
    for(int i = 0,j = 0; i < 2000002 && j < k;++i){
        //cout << po[i] << " " << po2[i] << " " << i << "\n";
        if(!po[i] && po2[i])++j;
        if(j == k) printf("%d\n",i);
    }
    return 0;
}
