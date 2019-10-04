#include<iostream>
#include<string>
#define ll long long
#include<cstring>
#include<vector>

using namespace std;

int main(){
	string check;
	cin >> check;
	vector<ll> st(check.size(),0);
	vector<ll> en(check.size(),0);
	for(int i = 0;i < check.size();++i){
		for(int j = i; j < check.size();++j){
			int t1 = i,t2 = j;
			bool pal = true;
			while(t1 <= t2 && pal){
				if(check[t1] != check[t2])
					pal = !pal;
				else{
					++t1;--t2;
				}
			}
			if(pal){
				++st[i];
				++en[j];
			}
		}
	}
	ll sum = 0;
	for(int i = check.size()-1;i > -1;--i){
		sum += st[i];
		st[i] = sum;
	}
	ll ans = 0;
	for(int i = 0; i < check.size()-1;++i){
		if(en[i] > 0 && st[i+1] > 0)
			ans += (en[i]* st[i+1]);
	}
	cout << ans << endl;
	return 0;
}
