#include<bits/stdc++.h>
#define ll long long

ll N[3*100000];

ll sum(int x){
	ll ans = 0;
	while(x){
		ans += N[x];
		int less = (x&(-x));
		x -= less;
	}
	return ans;
}

void update(int x, ll va){
	while(x < 100000){
		N[x] += va;
		int add = (x&(-x));
		x += add;
	}
}

ll rangeSum(int x,int y){
	return sum(y) -sum(x-1);
}

int main(){
    int n,d,a
}
