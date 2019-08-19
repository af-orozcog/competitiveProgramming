#include<iostream>
#include<string>
#include<cstring>

int trie[100000][10];
int n = 0;
int cnt[100000];
using namespace std;

void add(string &num){
	int cur = 0;
	for(char a : num){
		if(trie[cur][a-'0'] == 0){
			trie[cur][a-'0'] = ++n;
		}
		cur = trie[cur][a-'0'];
	}
	//cout << n << endl;
	cnt[cur] = 1;
}

bool search(string &num){
	int cur = 0;
	for(char a: num){
		cur = trie[cur][a-'0'];
		if(cur == 0)
			return false;
		if(cnt[cur] == 1)
			return true;
	}
	return true;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		n = 0;
		memset(trie,0,sizeof(trie));
		memset(cnt,0,sizeof(cnt));
		int n;
		cin >> n;
		bool p = true;
		while(n--){
			string read;
			cin >> read;
			if(!p)
				continue;
			if(!search(read))
				add(read);
			else
				p = false;
		}
		cout << (p ? "YES":"NO") << "\n";
	}
	return 0;
}