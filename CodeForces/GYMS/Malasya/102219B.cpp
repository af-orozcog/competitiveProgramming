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
	int t;
	scanf(" %d",&t);
	while(t--){
		int a,b;
		scanf(" %d %d",&a,&b);
		if(a == b)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}