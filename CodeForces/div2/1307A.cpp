#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf(" %d",&t);
    while(t--){
      int n,d;
      scanf(" %d %d",&n,&d);
      int ar[n];
      for(int i = 0; i < n;++i) scanf(" %d",&ar[i]);

      for(int i = 1,j = 1; i < n && d > 0;){
           while(ar[i] && d>= j){
                ++ar[0];
                d-=j;
                --ar[i];
            }
            ++i,++j;
      }
      printf("%d\n",ar[0]);
    }
    return 0;
}
