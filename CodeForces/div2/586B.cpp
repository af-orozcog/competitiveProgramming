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
	int n;
	scanf(" %d",&n);
	vector<int> row1u(n),row2u(n),row1d(n),row2d(n);
	int row1[n-1],row2[n-1];
	for(int i = 0; i < n-1;++i) scanf(" %d",&row1[i]);
	for(int i = 0; i < n-1;++i) scanf(" %d",&row2[i]);
	row1u[0] = row2u[0] = 0;
	for(int i = 1; i < n;++i){
		row1u[i] = row1u[i-1]+row1[i-1];
		row2u[i] = row2u[i-1]+row2[i-1];
	//	cout << row1u[i] << " " <<  row2u[i] <<endl;
	}
	//cout << " lil " << endl;
	row2d[n-1] = row1d[n-1] = 0;
	for(int i = n-2; i > -1;--i){
		row1d[i] = row1[i] + row1d[i+1];
		row2d[i] = row2[i] + row2d[i+1];
	//	cout << row1d[i] << " " <<  row2d[i] <<endl;
	}
	int cross[n];
	for(int i = 0; i < n;++i) scanf(" %d",&cross[i]);
	int ans = 100000000;
	for(int i = 0; i < n;++i){
		for(int j = 0; j < n;++j){
			if(i == j) continue;
			int temp = min(cross[i]+cross[j]+row1u[i]+row2d[i]+row2d[j]+row1u[j],
				cross[i]+cross[j]+row2d[i]+row1u[i]+row1u[j]+row2d[j]);
			ans = min(ans,temp);
		}
	}
	printf("%d\n",ans);
	return 0;
}