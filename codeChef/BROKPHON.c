#include<stdio.h>

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int n;
		int less = 0;
		scanf(" %d",&n);
		int last; scanf(" %d",&last);
		int ans = 0;
		for(int i = 1; i < n;++i){
			int val; scanf(" %d",&val);
			if(val != last){
				ans += 2;
				ans -= less;
				less = 1;
			}
			else
				less = 0;
			last = val;
		}
		printf("%d\n", ans);
	}
	return 0;
}