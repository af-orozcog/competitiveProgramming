#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    string ans = "";
    for(int i = 0; i < n;++i)
        ans +=  '*';
    bool posi = 1;
    while(m--){
        int s,v;
        scanf(" %d %d",&s,&v);
        --s;
        if(ans[s] != '*' && ('0'+v) != ans[s]){
            posi = 0;continue;
        }
        ans[s] = '0' + v;
    }
    if(!posi){puts("-1");return 0;}
    for(int i = 0; i < n;++i){
        if(ans[i] != '*') continue;
        else ans[i] = ((i == 0 && n != 1)? '1':'0');
    }
    if(ans[0] == '0' && n > 1) puts("-1");
    else cout << ans << endl;
    return 0;
}
