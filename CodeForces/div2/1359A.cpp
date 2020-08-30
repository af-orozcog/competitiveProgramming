#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int r,g,b,w;
        scanf(" %d %d %d %d",&r,&g,&b,&w);
        vector<int> odd;
        int mi = min(r,min(g,b));
        if(r&1) odd.push_back(r);
        if(g&1) odd.push_back(g);
        if(b&1) odd.push_back(b);
        if(!odd.size() || (int)odd.size() == 3)
            puts("YES");
        else if((int)odd.size() == 2 && (w %2 == 0 || mi == 0))
            puts("NO");
        else if((int)odd.size() == 1 && w&1)
            puts("NO");
        else puts("YES");
    }
    return 0;
}
