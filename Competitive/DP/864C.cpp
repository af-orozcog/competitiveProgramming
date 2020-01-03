#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,f,k;
    scanf(" %d %d %d %d",&a,&b,&f,&k);
    int last = 0,posi = 1;
    int fu = b, ans = 0;
    for(int i = 0; i < k && posi;++i){
        fu -= a;
        if(fu < 0){
            ++ans;
            fu += (i&1?b-f:b-(a-f));
            if(fu < 0 && last == 0)
                fu += (i&1?b-(a-f):b-f),++ans;
            else if(fu < 0)
                posi = 0;
            last = 1;
        }
        else last = 0;
    }
    if(fu < 0){
        ++ans;
        fu += (k&1?b-f:b-(a-f));
        if(fu < 0 && last == 0)
            fu += (k&1?b-(a-f):b-f),++ans;
        else if(fu < 0)
            posi = 0;
        last = 1;
    }
    if(!posi) puts("-1");
    else printf("%d\n",ans);
    return 0;
}
