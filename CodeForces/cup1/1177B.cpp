#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll unsigned long long

using namespace std;
string nums = "";
vector<ll> range = {0};

void sett(){
	ll total = 0;
	ll actual = 1;
	while(total < 1000000000000){
		nums += to_string(actual);
		total = (actual*(actual+1)) >> 1;
		//if(total < 100)
		//	cout << total << endl;
		range.push_back(total);
		++actual;
	}
}

int main(){
	sett();
	ll toCheck;
	cin >> toCheck;
	vector<ll>::iterator low = lower_bound(range.begin(),range.end(),toCheck);
	int n = low -range.begin();
	--n;
	cout << range[n] << endl;
	cout << nums[toCheck - range[n]] << endl;
	return 0;
}