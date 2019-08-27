#include<iostream>
#define ll long long

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		ll n,m,k;
		scanf(" %lld %lld %lld",&n,&m,&k);
		ll nums[n][m];
		for(int i = 0; i < n;++i){
			for(int j = 0; j < m;++j)
				scanf(" %lld",&nums[i][j]);
		}
		for(int j = 0; j < m;++j){
			for(int i = 0; i < n;++i){
				ll val = nums[i][j];
				if(i > 0)
					val += nums[i-1][j];
				if(j > 0)
					val += nums[i][j-1];
				if(i > 0 && j > 0)
					val -= nums[i-1][j-1];
				nums[i][j] = val;
			}
		}
		int area;
		int cost;
		int disX = n-1;
		int disY = m -1;
		for(int i = 0; i < n;++i){
			for(int j = 0; j < m;++j){
				
			}
		}
	}
}