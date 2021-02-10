#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        for(int i = 0; i < n;++i){
            int a,b,c,d;
            scanf(" %d %d %d %d",&a,&b,&c,&d);
        }
        if(m % 4 != 0)
            puts("NO");
        else puts("YES");
    }
    return 0;
}