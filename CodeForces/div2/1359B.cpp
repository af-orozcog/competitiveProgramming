#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,x,y;
    scanf(" %d %d %d %d",&n,&m,&x,&y);
    for(int j = y; j > 0;--j)
        printf("%d %d\n",x,j);
    for(int j = y+1; j <= m;++j)
        printf("%d %d\n",x,j);
    int co = 0;
    int i = (x+1);
    if(i > n) i -= n;
    while(i != x){
        if(!co)
            for(int j = m; j > 0;--j)
                printf("%d %d\n",i,j);
        else
            for(int j = 1; j <= m;++j)
                printf("%d %d\n",i,j);
        ++i;
        if(i > n) i -= n;
        ++co;
        co = co&1;
    }
    return 0;
}
