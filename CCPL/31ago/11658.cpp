#include<iostream>
#include<bitset>
#include<string>

using namespace std;

int main(){
	while(1){
		int n,m;
		scanf(" %d %d",&n,&m);
		if(n == 0)
			break;
		bitset<10001> dp;
		int nums[n];
		for(int i = 0; i < n;++i){
			string re;
			cin >> re;
			int j = 0;
			while(re[j] != '.'){++j;}
			int a = stoi(re.substr(0,j)), b = stoi(re.substr(j+1,re.size()-j));
			a = a*100 + b;
			nums[i] = a;
		}
		dp[0] = 1;
		for(int i = 0; i < n;++i){
			if(i == m-1)
				continue;
			for(int j = 10000-nums[i];j >= 0;--j){
				if(dp[j])
					dp[j+nums[i]] = 1;
			}
		}
		int ans;
		if(nums[m-1] > 5000)
			ans = nums[m-1];
		for(int i = 0; i <= 10000;++i){
			if(dp[i] && (i + nums[m-1] > 5000)){
				ans = i; 
				break;
			}
		}
		ans += nums[m-1];
		printf("%.2f\n",((double)nums[m-1]/(double)ans)*100.0);
	}
	return 0;
}