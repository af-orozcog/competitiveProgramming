/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define max(x,y)(x > y? x:y)

using namespace std;

int main(){
	int siz;
	scanf(" %d",&siz);
	ll nums[siz];
	for(int i = 0; i < siz;++i){
		cin >> nums[i];
	}
	int ans = 1;
	int i = 0;
	int j = 1;
	int last = j - 1;
	while(i < siz && j < siz){
		if(nums[last] * 2 >= nums[j]){
			//cout << " 1 " << nums[last] << " 2 " << nums[j] << endl;
			++j;
			last = j -1;
		}
		else{
			//cout <<"i is " << i<<" j is "<<j << endl;
			ans = max(ans,j-i);
			i = j;
			++j;
			last = j -1;
		}
	}
	ans = max(ans,j-i);
	cout << ans << endl;
}