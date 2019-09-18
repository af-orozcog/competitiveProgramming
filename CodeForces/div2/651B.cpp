#include<iostream>
#include<map>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	map<int,int> freq;
	for(int i = 0; i < n;++i){
		int val;scanf(" %d",&val);
		if(freq.count(val))
			++freq[val];
		else
			freq[val] = 1;
	}
	int ans = 0;
	int add = 1;
	while(add>0){
		add = 0;
		for(auto &pa:freq){
			if(pa.second > 0){
				--pa.second;
				++add;
			}
		}
		--add;
		ans += (add > 0 ? add:0);
	}
	printf("%d\n",ans);
	return 0;
}