#include<iostream>
#include<cstring>

using namespace std;

bool dp[30000][30000];
int nums[30000];
int N;

void bUP(){
	for(int i = 0; i < N){
		int l = i-1,r = i+1;
		if(l < 0 || r >= N)
			continue;
		int ll = nums[l],rr = nums[r];
		int siz = 1;
		while(l > 0 && r < N){
			if()
		}
	}
}

int main(){
	memset(dp,false,sizeof(dp));
}