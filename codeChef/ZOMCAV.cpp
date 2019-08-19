#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int n;
		scanf(" %d",&n);
		vector<int> val(n);
		vector<int> nums1(n,0);
		vector<int> nums2(n);
		for(int i = 0; i < n;++i)
			scanf(" %d",&val[i]);
		for(int i = 0; i < n;++i){
			int to = val[i];
			++nums1[i];
			int m = 1;
			while(m <= to && i+m < n){
				++nums1[i+m]; 
				++m;
			}
		}
		for(int i = n-1;i >= 0;--i){
			int to = val[i];
			int m = 1;
			while(m <= to && i-m >= 0){
				++nums1[i-m];
				++m;
			} 
		}
		for(int i = 0; i < n;++i)
			scanf(" %d",&nums2[i]);
		sort(nums1.begin(),nums1.end());
		sort(nums2.begin(),nums2.end());
		bool posi = true;
		for(int i = 0; i < n && posi;++i){
			if(nums1[i]!= nums2[i])
				posi = false;
		}
		if(posi)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}