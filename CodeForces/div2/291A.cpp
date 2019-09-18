#include<iostream>
#include<map>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	bool posi = true;
	map<int,int> freq;
	int ans = 0;
	for(int i = 0; i < n;++i){
		int val;
		scanf(" %d",&val);
		if(val == 0) continue;
		if(freq.count(val))
			++freq[val];
		else
			freq[val] = 1;
		if(freq[val] == 2)
			++ans;
		if(freq[val] > 2)
			posi = false;
	}
	if(!posi)
		puts("-1");
	else
		printf("%d\n",ans);
	return 0;
}