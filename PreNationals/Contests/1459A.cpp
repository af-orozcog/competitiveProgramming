#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        char num1[n+1],num2[n+1];
        scanf(" %s",num1);
        scanf(" %s",num2);
        int one = 0, two = 0;
        for(int i = 0; i < n;++i){
            if(num1[i] > num2[i])
                ++one;
            else if(num2[i] > num1[i])
                ++two;
        }
        if(one > two) puts("RED");
        else if(two > one) puts("BLUE");
        else puts("EQUAL");
    }
    return 0;
}
