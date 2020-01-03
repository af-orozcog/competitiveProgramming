#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int h,m;
        scanf(" %d %d",&h,&m);
        int lefH = 24-h-1;
        int leM = 60 - m;
        printf("%d\n",leM+lefH*60);
    }
    return 0;
}
