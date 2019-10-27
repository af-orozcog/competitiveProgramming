#include<iostream>
#include<vector>
#include<string>
#define ll long long

using namespace std;


ll fastSum(ll val){
	return (val*(val+1))>>1;
}

int main(){
	int n;
	scanf(" %d",&n);
	string check;
	cin >> check;
	vector<int> posi;
	for(int i = 0; i < check.size();++i){
		if(check[i] == '1')
			posi.push_back(i);
	}
	ll ans = 0;
	if(!n){
		for(int i = 0; i < posi.size();++i){
			if(!i)
				ans += fastSum(posi[i]);
			else
				ans += fastSum((posi[i] -posi[i-1])-1);
			if(i == (int)posi.size()-1)
				ans += fastSum((check.size()-1)-posi[i]);
		}
		if(posi.size() == 0)
			ans += fastSum(check.size());
	}
	for(int i = 0; i < posi.size()&&n;++i){
		int j = (i+n)-1;
		if(j >= (int)posi.size())
			break;
		ll left = 0;
		ll right = 0;
		//cout << "j is " << j << endl;
		if(i > 0)
			left = (posi[i] - posi[i-1])-1;
		else
			left = posi[i];
		if(j < posi.size()-1)
			right = (posi[j+1]-posi[j])-1;
		else
			right = (check.size()-1)-posi[j];
		++left;
		++right;
		//cout << left << " " << right<< endl;
		ans += left*right;
	}
	cout << ans << endl;
	return 0;
}