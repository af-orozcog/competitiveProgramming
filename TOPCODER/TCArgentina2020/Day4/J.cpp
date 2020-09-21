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

const ll MOD = 1000000007;

int n, a[15];
ll c[105][105];
ll dp[105][15];

ll solve(int len, int j){
    if(dp[len][j]!=-1)return dp[len][j];
    else if(j==9)return dp[len][j]=len>=a[9];
    dp[len][j]=0;
    int x = len;
    if(j==0){
        x--;
    }
    for(int i = a[j]; i<=len; ++i ){
        dp[len][j]+=(solve(len-i,j+1)*1LL*c[x][i])%MOD;
        if(dp[len][j]>=MOD)dp[len][j]-=MOD;
    }
    //error(len,j,dp[len][j]);
    return dp[len][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(c,0,sizeof(c));
    memset(dp,-1,sizeof(dp));

    for(int i =0; i<105; ++i){
        c[i][i]=c[i][0]=1;
        for(int j = 1; j<i; ++j){
            if ((c[i][j] = c[i-1][j-1] + c[i-1][j]) >= MOD) c[i][j] -= MOD;
            //cout << i << " " << j << " "<<c[i][j] << "\n";
        }
    }
    cin>>n;
    for(int i =0; i<=9; ++i){
        cin>>a[i];
    }
    cout<<solve(n,0)<<"\n";
}
