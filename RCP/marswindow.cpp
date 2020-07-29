#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    if(n == 2018){puts("yes");return 0;}
    int see = (n-2018)*12 - 3;
    if((26 - see%26) <= 11) puts("yes");
    else puts("no");
    return 0;
}
