#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int a,b,c,r;
        scanf(" %d %d %d %d",&a,&b,&c,&r);
        if(a > b) swap(a,b);
        int covL = c- r,covR = c+r;
        if(a > covR || b < covL)printf("%d\n",abs(b-a));
        else{
            int dis1 = covL-a;
            if(dis1 < 0) dis1 = 0;
            int dis2 = b - covR;
            if(dis2 < 0) dis2 = 0;
            printf("%d\n",dis1+dis2);
        }
    }
    return 0;
}
