#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        if(n == 1) puts("FastestFinger");
        else if(n == 2) puts("Ashishgup");
        else{
            if(n&1) puts("Ashishgup");
            else{
                int two = 0;
                int imp = 0;
                while(n%2 == 0){
                    ++two;
                    n/=2;
                }
                int upTo = sqrt(n);
                for(int i = 3; i <= upTo;++i){
                    while(n % i == 0){
                        ++imp;
                        n /= i;
                    }
                }
                if(n != 1) ++imp;
                if(imp == 0 || (imp==1 && two == 1)) puts("FastestFinger");
                else puts("Ashishgup");
            }
        }
    }
    return 0;
}
