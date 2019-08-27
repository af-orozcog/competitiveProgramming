#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define max(x,y)(x > y? x:y)

using namespace std;

int main(){
	int to;
	scanf(" %d",&to);
	for(int k = 1; k <= to;++k){
		int n;
		scanf(" %d",&n);
		vector<int> he(n),wi(n);
		vector<int> hec,wic;
		for(int i = 0; i < n;++i) scanf(" %d",&he[i]);
		for(int i = 0; i < n;++i) scanf(" %d",&wi[i]);
		hec = he;
		wic = wi;
		reverse(hec.begin(),hec.end());
		reverse(wic.begin(),wic.end());
		vector<int> dp1(n);
		vector<int> dp2(n);
		dp1[0] = wi[0];
		for(int i = 1; i < n;++i){
			for(int j = i-1;j>= 0;--j){
			    dp1[i] = max(dp1[i],wi[i]);
				if(he[i] > he[j])
					dp1[i] = max(dp1[i],dp1[j] + wi[i]);
			}
		}
		dp2[0] = wic[0];
		for(int i = 1; i < n;++i){
			for(int j = i-1;j>= 0;--j){
				dp2[i] = max(dp2[i],wic[i]);
				if(hec[i] > hec[j]){
					dp2[i] = max(dp2[i],dp2[j] + wic[i]);
				}
			}
		}
		int maA = 0;
		int maB = 0;
		for(int i = 0; i < n;++i){
			maA = max(maA,dp1[i]);
			maB = max(maB,dp2[i]);
		}
		if(maA >= maB)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n",k,maA,maB);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n",k,maB,maA);
	}
}