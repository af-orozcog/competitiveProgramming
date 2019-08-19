#include<iostream>
#include<cstring>
#define ll long long

using namespace std;
ll M = 1000000007;

ll dp[3][200000];

ll n0,n1,n2;
ll siz;

int solve(int r,int p){
	if(p == siz){
		if(r == 0)
			return 1;
		else
			return 0;
	}
	if(dp[r][p] != -1)
		return dp[r][p];
	 ans = n0*solve(r,p+1);
	ans = ans % M;
	ans += n1*solve((r+1)%3,p+1);
	ans = ans % M;
	ans += n2*solve((r+2)%3,p+1);
	ans = ans %M;
	return dp[r][p] = ans;
}

int main(){
	int l,r;
	cin >> siz >> l >> r;
	memset(dp,-1,sizeof(dp));
	if(l % 3 == 0){
		n0 = 1;
		n0 += (r-l) / 3;
		++l;
		if(l <= r)
			n1 = ((r-l)/3) + 1;
		else
			n1 = 0;
		++l;
		if(l <= r)
			n2 = ((r-l)/3) + 1;
		else
			n2 = 0;
	}
	else if(l % 3 == 1){
		n1 = 1;
		n1+= (r-l)/3;
		++l;
		if(l <= r)
			n2 = ((r-l)/3) + 1;
		else
			n2 = 0;
		++l;
		if(l <= r)
			n0 = ((r-l)/3) + 1;
		else
			n0 = 0;
	}
	else if(l % 3== 2){
		n2 = 1;
		n2+= (r-l)/3;
		++l;
		if(l <= r)
			n0 = ((r-l)/3) + 1;
		else
			n0 = 0;
		++l;
		if(l <= r)
			n1 = ((r-l)/3) + 1;
		else
			n1 = 0;
	}
	//cout << n0 << " " << n1 << " " << n2 << endl;
	cout << solve(0,0) << endl;
	return 0;
}