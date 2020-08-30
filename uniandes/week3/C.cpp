#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int x,y,z;
    cin >> x >> y >> z;
    int ans = 100000000;
    int where;
    for(int i = 0;i < 102;++i){
        int dist = abs(i-x) + abs(i-y) + abs(i-z);
        if(dist < ans)
            ans = dist;
    }
    cout << ans << "\n";
    return 0;
}
