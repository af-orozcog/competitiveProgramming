#include<bits/stdc++.h>
#define ll long long
#define EPS 1e-9
using namespace std;

double imp = 3.5;

int main(){
    double vals[6];
    for(int i = 0; i < 6;++i) cin >> vals[i];
    double see = 0.0;
    for(int i = 1; i <= 6;++i)
        see += (double)i*vals[i-1];
    double ans = (double)1000000000000.0;
    for(int i = 1; i <= 6;++i){
        double temp = see - (double)i*vals[i-1];
        temp = imp - temp;
        temp /= vals[i-1];
        ans = min(ans,abs(temp-(double)i));
    }
    cout << fixed << setprecision(3) << ans << "\n";
    return 0;
}
