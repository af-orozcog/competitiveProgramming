#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string re;
        cin >> re;
        int ar[] = {0,0};
        for(auto va:re)
            ++ar[va-'0'];
        int see = min(ar[0],ar[1]);
        if(see&1) puts("DA");
        else puts("NET");
    }
    return 0;
}
