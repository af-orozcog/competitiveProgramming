#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1.0)
using namespace std;
int n,k;
int main(){
    freopen("baklava.in","r",stdin);
    scanf("%d",&n);
    while(n--){
        scanf("%d",&k);
        printf("%.5f\n",10000/(1-(cos(PI/2)-cos(PI/k))*(cos(PI/2)-cos(PI/k))));
    }
    return 0;
}
