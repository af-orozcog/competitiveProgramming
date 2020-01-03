#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    map<int,int> fr;
    for(int i = 0; i < n;++i){
        int va;scanf(" %d",&va);
        ++fr[va];
    }
    if(fr.size() > 2 || fr.size() == 1) puts("NO");
    else{
        auto va = fr.begin();
        if((*va).second != (n>>1)) puts("NO");
        else{
            puts("YES");
            printf("%d ",(*va).first);
            ++va;
            printf("%d\n",(*va).first);
        }
    }
    return 0;
}
