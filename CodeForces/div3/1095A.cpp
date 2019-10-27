#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n;scanf(" %d",&n);
	vector<char> ans;
	int next = 0;
	for(int i = 0,co = 1; i < n;++i){
		char va; scanf(" %c",&va);
		if(next == i){
			ans.push_back(va);
			next += co;
			++co;
		}
	//	cout << next << endl;
	}
	for(auto &va:ans)
		printf("%c",va);
	puts("");
	return 0;
}