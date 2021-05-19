#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int n;
    scanf(" %d",&n);
    vector<char> first(n), second(n);
    for(int i = 0; i < n;++i) scanf(" %c",&first[i]);
    for(int i = 0; i < n;++i) scanf(" %c",&second[i]);
    int q;
    scanf(" %d",&q);
    while(q--){
        int t,a,b;
        scanf(" %d %d %d",&t,&a,&b);
        if(t == 1){
            if(b <= n)
                swap(first[a-1],first[b-1]);
            else if(a > n)
                swap(second[a-1-n],second[b-1-n]);
            else
                swap(first[a-1],second[b-n-1]);
        }
        else swap(first,second);
    }
    for(int i = 0; i < n;++i) printf("%c",first[i]);
    for(int i = 0; i < n;++i) printf("%c",second[i]);
    puts("");
    return 0;
}
