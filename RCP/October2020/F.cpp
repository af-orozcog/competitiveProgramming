//#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)\
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")\
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 105
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

ll DP[MAX][MAX][MAX];

const ll mod = 1e9+7;
string s1, s2, s3, s;

ll dp(int i, int j, int k){
    int l = i+j+k;
    if(l==s.size()) return 1;
    if(DP[i][j][k]!=-1) return DP[i][j][k];
    ll rta = 0;
    if(s[l]==s1[i]) rta+=dp(i+1,j,k);
    if(s[l]==s2[j]) rta+=dp(i,j+1,k);
    if(s[l]==s3[k]) rta+=dp(i,j,k+1);
    return DP[i][j][k] = rta%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.in", "r", stdin);
    memset(DP, -1, sizeof(DP));
    cin>>s1>>s2>>s3>>s;
    s1+="$"; s2+="$"; s3+="$";
    ll rta = dp(0,0,0);
    cout<<rta<<"\n";
    return 0;
}
