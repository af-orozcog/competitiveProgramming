#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    set<char> let;
    int ans = 0;
    for(int i = 0; i < t;++i){
        char va;scanf(" %c",&va);
        if(va >= 'A' && va <= 'Z'){ans = max((int)let.size(),ans);let.clear();}
        else let.insert(va);
    }
    ans = max(ans,(int)let.size());
    printf("%d\n",ans);
    return 0;
}
