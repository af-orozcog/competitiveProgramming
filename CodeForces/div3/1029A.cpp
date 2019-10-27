/**
* I only hope everything will be back to normal
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	string a;
	cin >> a;
	int save = a.size();
	for(int i = 1; i < a.size();++i){
		int j = 0;
		int tempI = i;
		while(tempI != a.size() && a[tempI] == a[j]){
			++tempI;
			++j;
		}
		if(tempI == a.size()){
			//cout << i << " " << j << endl;
			save = a.size()-j;
			break;
		}
	}
	//cout << save << endl;
	string show = a.substr(0,save);
	for(int i = 0; i < m-1;++i)
		cout << show;
	cout << a << endl;
	return 0;
}