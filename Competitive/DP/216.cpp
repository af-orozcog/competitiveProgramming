#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std;

vector<pair<int,int>> nums(8);
double dp[8][(1<<9)];
int N;
int upTo;

double solve(int p, int visi){
	if(visi == upTo)
		return 0;
	if(dp[p][visi] != -1.0)
		return dp[p][visi];
	double ans = 10000000;
	for(int i = 0; i < N;++i){
		if(((visi>>i) & 1) == 0){
			double val = solve(i,visi | (1<<i)) + sqrt(pow(nums[p].first - nums[i].first,2.0) +pow(nums[p].second - nums[i].second,2.0)) + 16.0;
			if(val < ans)
				ans = val;
		}
	}
	return dp[p][visi] = ans;
}

int main(){
	int ca = 1;
	while(1){
		for(int i= 0;i < 8;++i){
			for(int j = 0; j < (1<<9);++j)
				dp[i][j] = -1.0;
		}
		scanf(" %d",&N);
		if(N == 0)
			break;
		upTo = (1<<N)-1;
		for(int i = 0; i< N;++i){
			int a,b;
			scanf(" %d %d",&a,&b);
			nums[i] = {a,b};
		}
		double ans = 10000000.0;
		int first;
		for(int i = 0; i < N;++i){
			double val = solve(i,1<<(i));
			if(val < ans){
				ans = val;
				first = i;
			}
		}
		int co = 1<<first;
		int last = first;
		puts("**********************************************************");
		printf("Network #%d\n", ca);
		while(1){
			int next;
			double val = 100000000.0;
			for(int i = 0; i< N;++i){
				if(((co>>i) & 1) == 0){
				    if((co| (1<<i)) == upTo){
				        next = i;
				        break;
				    }
					if((dp[i][co|(1<<i)]+sqrt(pow(nums[last].first - nums[i].first,2.0) +pow(nums[last].second - nums[i].second,2.0)) + 16) < val){
						next = i;
						val = dp[i][co|(1<<i)] + sqrt(pow(nums[last].first - nums[i].first,2.0) +pow(nums[last].second - nums[i].second,2.0)) + 16; 
					}
				}
			}
			double  imp = sqrt(pow(nums[last].first - nums[next].first,2.0) +pow(nums[last].second - nums[next].second,2.0)) + 16;
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",nums[last].first,nums[last].second,nums[next].first,nums[next].second,imp);
			co = (co| (1<<next));
			last = next;
			if(co == upTo)
				break; 
		}
		printf("Number of feet of cable required is %.2f.\n",ans);
		++ca;
	}
}