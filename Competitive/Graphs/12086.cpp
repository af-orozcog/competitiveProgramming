/**
* I do this because of Valentina
*/
#include<stdio.h>
#include<cstring>
#include<string>

//using namespace std;

int nums[200003];

void update(int pos, int val){
	while(pos < 200003){
		nums[pos] += val;
		int dig = (pos&(-pos));
		pos += dig;
	}
}

int sum(int pos){
	int ans = 0;
	while(pos){
		ans += nums[pos];
		int dig = (pos&(-pos));
		pos -= dig;
	}
	return ans;
}

int summation(int i, int j){
	return sum(j) - sum(i-1);
}

int main(){
	int cas = 1;
	while(1){
		int n;
		scanf(" %d",&n);
		//cout << n << endl;
		if(n == 0)
			break;
		if(cas != 1)
			puts("");
		printf("Case %d:\n", cas++);
		memset(nums,0,sizeof(nums));
		for(int i = 1; i <= n;++i){
			int val;scanf(" %d",&val);
			update(i,val);
		}
		char cmd[50],op[10];
		while(1){
			scanf(" %s",cmd);
			//cout << a << endl;
			if(cmd[0] == 'E')
				break;
			int x,y;
			scanf(" %d %d",&x,&y);
			if(cmd[0] == 'M')
				printf("%d\n",summation(x,y));
			else{
				int less = summation(x,x);
				update(x,-less);
				update(x,y);
			}
		}
	}
	return 0;
}