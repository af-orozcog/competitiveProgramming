#include<bits/stdc++.h>
#define ld long double
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    ld dist[n];
    for(int i = 0; i < n;++i){
        ld x,y,z;
        cin >> x >> y >> z;
        ld add = sqrt((x*x)+(y*y)+(z*z));
        dist[i] = add;
    }
    sort(dist,dist+n);
    cout << fixed << setprecision(7) << dist[k-1] << "\n";
    return 0;
}
