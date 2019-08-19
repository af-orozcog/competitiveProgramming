/**
* I'm sorry I was an idiot
*/
#include<iostream>
#define ll long long
#include<vector>
#include<algorithm>

using namespace std;

bool checkValid(vector<ll> &a){
	for(int i = 0; i < a.size();++i){
		if(i == 0){
			ll va1,va2;
			va1 = a[a.size()-1];
			va2 = a[i+1];
			if(a[i] >= va1+va2)
				return false;
		}
		else if(i == a.size()-1){
			ll va1,va2;
			va1 = a[i-1];
			va2 = a[0];
			if(a[i] >= va1+va2)
				return false;
		}
		else{
			ll va1,va2;
			va1 = a[i-1];
			va2 = a[i+1];
			if(a[i] >= va1+va2)
				return false;
		}
	}
	return true;
}

bool com(const ll a, const ll b){
	return a > b;
}
int main(){
	int siz;
	cin >> siz;
	vector<ll> nums(siz);
	for(int i = 0; i < siz;++i){
		cin >> nums[i];
	}
	sort(nums.begin(),nums.end(),com);
	vector<ll> answer(siz);
	int m = 0, n = siz - 1;
	int turn = 1;
	for(int i = 0; i < siz;++i){
		if(turn){
			answer[n--] = nums[i];
			turn = 0;
		}
		else{
			answer[m++] = nums[i];
			turn = 1;
		}
	}
	if(checkValid(answer)){
		puts("YES");
		for(int i = 0; i < siz;++i){
			if(i == 0)
				cout << answer[i];
			else
				cout << " " << answer[i];
		}
		cout << endl;
	}
	else
		puts("NO");
	return 0;
}