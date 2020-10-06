//#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)\
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")\
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 100005
#define ff first
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int nums[MAX];

pdd get_recta(double x1, double x2, double y1, double y2) {
    double m = (y2-y1)/(x2-x1);
    double b = y1-m*x1;
    return {m,b};
}

double eval_inv(pdd f, double y){
    return (y-f.ss)/f.ff;
}

double eval (pdd f, double x, double xi, double xd, double my){
    if(x>=(xi-1e-6) && x<=(xd+1e-6)) return f.ff*x+f.ss;
    return my;

}

double inter(pdd f1, pdd f2){
    return (f2.ss-f1.ss)/(f1.ff-f2.ff);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.in", "r", stdin);

    int t, n, a, b, m;
    int x1,x2,x3,x4;
    int y1, y2, y3, y4;
    cin>>x1>>y1>>x2>>y2;
    pdd f1 = get_recta(x1, x2, y1, y2);
    cin>>x3>>y3>>x4>>y4;
    pdd f2 = get_recta(x3, x4, y3, y4);
    int my = min(y2, y4);
    double dx = abs(eval_inv(f1, my)-eval_inv(f2, my));
    double dy = my-eval(f1, inter(f1, f2), max(x1, x4), min(x2, x3), my);
    if(dy>my) dy = 0;
    cout<<fixed<<setprecision(9)<<(dy*dx)/2.0<<"\n";
}
