#include<iostream>
#include<vector>
#define ll long long

using namespace std;


bool solve(ll num,ll tar,vector<ll> &tr){
	tr.push_back(num);
	if(num == tar){
		cout << "YES\n";
		cout << tr.size() << endl;
		for(int i = 0; i < tr.size();++i){
			if(i == 0)
				cout << tr[i];
			else
				cout << " " << tr[i];
		}
		cout << endl;
		return true;
	}
	if(num > tar){
		tr.pop_back();
		return false;
	}
	ll pos1 = (num * 10) + 1;
	ll pos2 = num << 1;
	bool a1 = solve(pos1,tar,tr);
	bool a2 = solve(pos2,tar,tr);
	if(!(a1 || a2))
		tr.pop_back();
	return a1 || a2;
}

int main(){
	ll a,b;
	cin >> a >> b;
	vector<ll> s;
	if(!solve(a,b,s)){
		cout << "NO" << endl;
	}
	return 0;
}