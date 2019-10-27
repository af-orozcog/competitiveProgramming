/**
* ALL I DO IS WRONG
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;

int main(){
	int n;
	scanf(" %d",&n);
	bool imp = 0;
	for(int i = 0; i < n;++i){
		int va;scanf(" %d",&va);
		if(va&1){
			if(imp)
				printf("%d\n",va>>1);
			else
				printf("%d\n",(va>>1)+1);
			imp = !imp;
		}
		else
			printf("%d\n",va>>1);
	}	
	return 0;
}