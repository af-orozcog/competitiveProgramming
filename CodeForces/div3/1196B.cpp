/**
* about to lose ranking very hard
*/
#include<iostream>
#define ll long long
#include<vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int siz,k;
		cin >> siz >> k;
		int odd = 0;
		int even = 0;
		vector<int> in;
		for(int i = 0; i < siz;++i){
			ll va;
			cin >> va;
			if(va & 1)
				in.push_back(i);
		}
		if(((in.size()- k) % 2) ||(in.size() < k)){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i = 0; i < k-1;++i){
			if(i == 0)
				cout << in[i]+1;
			else
				cout <<" " <<in[i]+1;
		}
		cout << " " << siz << "\n";
	}
	return 0;
}