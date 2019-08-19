#include<iostream>
#include<cstring>
#define max(x,y)(x > y?x:y)

using namespace std;

int n,m,c0,d0;

int dp[10][10001];
int a[10];
int b[10];
int c[10];
int d[10];

int solve(int p, int l){
	//cout << "what?" << endl;
	if(p == m)
		return 0;
	if(dp[p][l] != -1)
		return dp[p][l];
	int i = 0;
	int ans = 0;
	while(1){
		if((i*c[p] > l) || (i*b[p] > a[p]))
			break;
		ans = max(ans,solve(p+1,l-(i*c[p]))+(i*d[p]));
	//	cout << "l is "<< l <<" i*cp[p] is " << i*c[p] << endl;
		++i;
	}
	return dp[p][l] = ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf(" %d %d %d %d",&n,&m,&c0,&d0);
	//cout << n << m << c0 << d0 << endl;
	for(int i = 0; i < m;++i){
		int a1,b1,c1,d1;
		scanf(" %d %d %d %d",&a1,&b1,&c1,&d1);
		a[i] = a1;
		b[i] = b1;
		c[i] = c1;
		d[i] = d1;
	}
	//here
	int ans = 0;
	int i = 0;
	while(1){
		if(i*c0 > n)
			break;
		ans = max(ans,solve(0,n-(i*c0))+ (d0*i));
	//	cout << i*c0 <<endl; 
		++i;
	}
	printf("%d\n",ans);
}