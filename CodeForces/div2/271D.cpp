#include<iostream>
#include<string>
#include<deque>
#include<cmath>
#include<map>
#define ll long long
#define M 1000000007

using namespace std;
bool good[26];

ll power(ll p,int n){
	ll ans = 1;
	for(int i = 0; i < n;++i){
		ans *= p;
		ans = ans % M;
	}
	return ans;
}


int main(){
	string a,check;
	int k;
	cin >> a >> check;
	for(int i =0; i < 26;++i){
		if(check[i] == '1')
			good[i] = true;
	}
	scanf(" %d",&k);
	deque<char> q;
	int bad = 0;
	ll num = 0;
	int prime = 137;
	map<int, bool> uni;
	int ans = 0;
	for(int i = 1; i < a.size();++i){
		for(int j = 0; j < a.size();++j){
			if(q.size() ==i){
				if(bad <= k && uni.count(num) == 0){
					++ans;
					uni[num]= true;
				}
				char val = q.front();
				ll less = (((val - 'a')+1)*power((ll)prime,i-1))%M;
				q.pop_front();
				num -=  less;
				if(!good[val-'a'])
					--bad;
			}
			num *= prime;
			num = num %M;
			num += ((a[j]-'a')+1);
			num = num % M;
			q.push_back(a[j]);
			if(!good[a[j]-'a'])
				++bad;
		}
		if(q.size() ==i){
			if(bad <= k && uni.count(num) == 0){
				++ans;
				uni[num]= true;
			}
			num = 0;
		}
		q.clear();
		bad = 0;
	}
	cout << ans<< endl;
	return 0;
}