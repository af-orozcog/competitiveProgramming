#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	vector<int> mod0(101);
	vector<int> mod1(101);
	int N,B;
	vector<int> nums(101);
	scanf(" %d %d",&N,&B);
	int f;
	scanf(" %d",&f);
	nums[0] = f;
	if(f & 1){
		mod1[0] = 1;
		mod0[0] = 0;
	}
	else{
		mod1[0] = 0;
		mod0[0] = 1;
	}
	for(int i = 1; i < N;++i){
		int v;
		scanf(" %d",&v);
		nums[i] = v;
		if(v & 1){
			mod1[i] = mod1[i-1]+1;
			mod0[i] = mod0[i-1];
		}
		else{
			mod1[i] = mod1[i-1];
			mod0[i] = mod0[i-1] +1;
		} 
	}
	if(N & 1){
		puts("0");
		return 0;
	}
	if(mod0[N-1] != mod1[N-1]){
	    puts("0");
	    return 0;
	}
	int num = B;
	int last = -1;
	vector<int> cuts;
	for(int i = 1; i < N-2;i += 2){
		if(mod0[i] == mod1[i])
			cuts.push_back(abs(nums[i] -nums[i+1]));
	}
	sort(cuts.begin(),cuts.end());
	int ans = 0;
	int less = B;
	for(int i = 0; i < cuts.size();++i){
		if(less >= cuts[i]){
			++ans; 
			less -= cuts[i];
		}
		else
			break;
	}
	printf("%d\n",ans);
	return 0;
}