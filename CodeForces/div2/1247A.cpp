/**
* I only hope everything will be back to normal
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;

int main(){
	int a,b;
	scanf(" %d %d",&a,&b);
	if(a == 9 && b == 1)
		puts("9 10");
	else if(a > b)
		puts("-1");
	else if(a==b)
		printf("%d %d\n",(a*10),(b*10)+1);
	else if(b - a == 1)
		printf("%d %d\n",(a*10)+9,(b*10));
	else
		puts("-1");
	return 0;
}