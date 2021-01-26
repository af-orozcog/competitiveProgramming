#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int now = 9;
        while(n--){
            printf("%d",now);
            --now;
            if(now < 0) now = 9;
        }
        puts("");
    }
    return 0;
}
