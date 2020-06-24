#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int k,p,x;
    scanf(" %d %d %d",&k,&p,&x);
    double ans = (double)1000000000000.0;
    int i = 1;
    while(1){
        double sum = (double)i*(double)x;
        double time = (double)k/(double)i;
        sum += time*(double)p;
        if(sum > ans)break;
        ans = sum;
        ++i;
    }
    cout << fixed << setprecision(3) << ans << "\n";
    return 0;
}
