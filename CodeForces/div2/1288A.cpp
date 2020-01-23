#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,d;
        scanf(" %d %d",&n,&d);
        int lo = 0, hi = n, pos = 0;
        while(lo <=hi && !pos){
            int mid = (lo+hi)>>1;
            int check = mid + (d/(mid+1));
            if(d % (mid+1)) ++check;
            if(check <= n) pos = 1;
            else if(check > n) hi = mid - 1;
            else lo = mid +1;
        }
        if(pos) puts("YES");
        else puts("NO");
    }
}
