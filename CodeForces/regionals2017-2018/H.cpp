#include<bits/stdc++.h>
using namespace std;

int main(){
   int ar1[3],ar2[3];

   for(int i = 0; i < 3;++i) scanf(" %d",&ar1[i]);
   for(int i = 0; i < 3;++i) scanf(" %d",&ar2[i]);
   int ans = 0;
   for(int i = 0;i < 3;++i)
        ans += (ar1[i]-ar2[i] < 0? ar2[i]-ar1[i]:0);
    printf("%d\n",ans);
    return 0;
}
