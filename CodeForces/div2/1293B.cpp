#include<bits/stdc++.h>
using namespace std;
int main(){
    int va;
    scanf(" %d",&va);
    double ans = 0;
    for(int i = 1; i <= va;++i)
        ans += 1.0/(double)i;
    printf("%.12f\n",ans);
    return 0;
}
