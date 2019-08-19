#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>> square;
void per(){
	int i = 1;
	while(i*i <= 100000){
		square.push_back(make_pair(i*i,i));
		++i;
	}
}

int main(){
	int t;
	per();
	cin >> t;
	while(t--){
		string va;
		cin >> va;
		int dpO[va.size()];
		if(va[0] == '0')
			dpO[0] = 1;
		else
			dpO[0] = 0; 
		for(int i = 1; i < va.size();++i){
			if(va[i] == '0')
				dpO[i] = dpO[i-1] + 1;
			else
				dpO[i] = dpO[i-1];
		}
		int ans = 0;
		for(int i = 0; i < square.size();++i){
			int r = square[i].first;
			int m = square[i].second;
			int to = r + m;
			if(to > va.size())
				break;
			for(int j = 0;j < va.size() && j + to -1 < va.size();++j){
				int le  = dpO[j + to-1] - dpO[j];
				//cout << 
				if(va[j] == '0')
					++le;
				//cout << le << " "<< j << " " << j+to-1 << endl;
				if(le == r)
					++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}