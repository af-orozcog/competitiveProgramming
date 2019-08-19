#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	vector<int> nu(n);
	scanf(" %d",&nu[0]);
	for(int i = 1;i < n;++i){
		int val;
		scanf(" %d",&val);
		nu[i] = nu[i-1] + val;
	}
	int q;
	scanf(" %d",&q);
	while(q--){
		int val;
		scanf(" %d",&val);
		int index = lower_bound(nu.begin(),nu.end(),val) - nu.begin();
		printf("%d\n",index+1);
	}
	return 0;
}