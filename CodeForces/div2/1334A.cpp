#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int a,b;
        scanf(" %d %d",&a,&b);
        n--;
        bool posi = 1;
        if(b > a) posi = 0;
        while(n--){
            int an,bn;
            scanf(" %d %d",&an,&bn);
            if(an < a || bn < b) posi = 0;
            int dist = an - a;
            if(bn - b > dist) posi = 0;
            if(bn > an) posi = 0;
            a = an,b = bn;
        }
        if(posi) puts("YES");
        else puts("NO");
    }
    return 0;
}
