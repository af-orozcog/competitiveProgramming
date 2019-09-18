#include<iostream>
#include<string>
#include<cstring>
#include<set>

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int freq[26];
		memset(freq,0,sizeof(freq));
		int st;
		scanf(" %d",&st);
		for(int i = 0; i < st;++i){
			string re;
			cin >> re;
			set<char> uni;
			for(char va:re)uni.insert(va);
			for(auto va:uni) ++freq[va-'a'];
		}
		int ans = 0;
		for(int i= 0; i < 26;++i){
			if(freq[i] == st)
				++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}