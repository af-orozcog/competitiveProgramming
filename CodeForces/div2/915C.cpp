/**
* I am who I am
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

string ans = "";
string com,temp;
bool solve(int p,bool flag,vector<int> &ava){
	if(p == temp.size())
		return true;
	if(flag){
		int i = 9;
		for(; i > -1;--i){
			if(ava[i])
				break;
		}
		ans += (i+'0');
		--ava[i];
		return solve(p+1,flag,ava);
	}
	else{
		int i = com[p] -'0';
		for(;i > -1;--i){
			if(ava[i]){
				--ava[i];
				ans += (i+'0');
				if(solve(p+1,(i< (com[p]-'0') ? 1:0),ava))
					return true;
				ans.pop_back();
				++ava[i];
			}
		}
		return false;
	}
}

int main(){
	cin >> temp >> com;
	vector<int> freq(10,0);
	for(int i = 0; i < temp.size();++i) ++freq[temp[i]-'0'];
	solve(0,(temp.size() < com.size() ? 1:0),freq);
	cout << ans << endl;
}