#include<bits/stdc++.h>
using namespace std;
int main(){
    int ar[3];
    scanf(" %d %d %d",&ar[0],&ar[1],&ar[2]);
    sort(ar,ar+3);
    int ans = ar[0] + (ar[1]-ar[0])/3 + (ar[2]-ar[0])/3;
    for(int i = ar[0]-1, j = 0; i > -1 && j < 5;--i,++j){
        int comp = i + (ar[0]-i)/3 + (ar[1]-i)/3 + (ar[2]-i)/3;
        ans = max(ans,comp);
    }
    printf("%d\n",ans);
    return 0;
}
