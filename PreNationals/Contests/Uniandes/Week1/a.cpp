#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int sum1 = 0, sum2 = 0;
    while(a){
        sum1 += a%10;
        a/= 10;
    }
    while(b){
        sum2 += b%10;
        b/= 10;
    }
    printf("%d\n",max(sum1,sum2));
    return 0;
}
