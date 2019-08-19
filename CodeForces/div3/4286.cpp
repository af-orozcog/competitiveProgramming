#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int num;
	cin >> num;
	ll val;
	cin >> val;
	ll min = val;
	ll max = val;
	cout << min + max << endl;
	--num;
	while(num--){
		ll vel;
		cin >> vel;
		if(vel < min)
			min = vel;
		else if(vel > max)
			max = vel;
		cout << min + max << endl;
	}
	return 0;
}