#include<iostream>
#include<vector>
#define max(x,y)(x > y? x:y)

using namespace std;
int a,b;

int solve(int num, vector<int> &ava){
	if(num > b)
		return -1;
	if(num >= a && num <= b)
		return num;
	int ans = -1;
	for(int i = 1; i < 10;++i){
		if(ava[i]){
			--ava[i];
			ans = solve((num*10)+i,ava);
			if(ans != -1)
				return ans;
			if(ava[0]){
				--ava[0];
				ans = solve((num*100)+(i*10),ava);
			}
			if(ans != -1)
				return ans;
			++ava[i];++ava[0];
		}
	}
	return -1;
}

int main(){
	scanf(" %d %d",&a,&b);
	vector<int> ava(10,1);
	cout <<solve(0,ava)<<endl;
}