#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
	int que;
	cin >> que;
	while(que--){
		string s,t,p;
		map<char,int> pt;
		cin >> s >> t >> p; 
		if(s.size() > t.size()){
			puts("NO");
			continue;
		}
		for(int i = 0; i < p.size();++i){
			char a = p[i];
			if(pt.count(a))
				++pt[a];
			else
				pt[a] = 1;
		}
		bool posi = true;
		int n = 0;
		for(int i = 0; i < t.size();++i){
			if(n < s.size() && t[i] == s[n]){
				++n;
				continue;
			}
			if(pt.count(t[i]) && pt[t[i]] > 0){
				--pt[t[i]];
			}
			else{
				posi = false;
				break;
			}
		}
		if(posi && n == s.size())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}