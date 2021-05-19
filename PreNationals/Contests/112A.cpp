#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    string a,b;
    cin >> a >> b;
    for(auto &let:a)
        let = tolower(let);
    for(auto &let:b)
        let = tolower(let);
    if(a < b) puts("-1");
    else if(a == b) puts("0");
    else puts("1");
    return 0;
}
