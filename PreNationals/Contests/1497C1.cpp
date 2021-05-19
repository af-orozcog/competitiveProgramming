#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        if(n&1)
            printf("%d %d 1",n/2,n/2);
        else if(n%4 == 0)
            printf("%d %d %d",n/2,n/4,n/4);
        else printf("2 %d %d",n/2-1,n/2-1);
        puts("");
    }
    return 0;
}
