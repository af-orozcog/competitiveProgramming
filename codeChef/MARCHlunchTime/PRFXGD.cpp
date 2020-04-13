#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        string re;
        cin >> re;
        int k,x;
        scanf(" %d %d",&k,&x);
        int let[26]; memset(let,0,sizeof(let));
        int ans = 0;
        for(int i = 0; i < re.size();++i){
            ++let[re[i]-'a'];
            if(let[re[i]-'a'] <= x) ++ans;
            else if(k) --let[re[i]-'a'],--k;
            else break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
