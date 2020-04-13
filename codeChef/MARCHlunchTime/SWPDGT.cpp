#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        string re1,re2;
        cin >> re1 >> re2;
        int ma = 0;
        for(int i = 0; i < re1.size();++i){
            for(int j = 0; j < re2.size();++j){
                swap(re1[i],re2[j]);
                int va = stoi(re1)+stoi(re2);
                ma = max(ma,va);
                swap(re1[i],re2[j]);
            }
        }
        printf("%d\n",ma);
    }
    return 0;
}
