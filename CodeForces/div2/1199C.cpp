#include<iostream>
#include<map>
#include<cmath>

using namespace std;


int main(){
	map<int,int> freq;
	int n,b;
	cin >> n >> b;
	for(int i = 0; i < n;++i){
		int val;
		cin >> val;
		if(freq.count(val))
			++freq[val];
		else
			freq[val] = 1;
	}
	int beg = freq.begin()->first;
	int end = freq.rbegin()->first;
	//cout << beg << endl;
	//cout << end << endl;
	int ans = 0;
	//cout << log2((double)freq.size()) << endl;
	while((ceil(log2((double)freq.size()))*n) > (b*8)){
		if(freq[beg] < freq[end]){
			ans += freq[beg];
			freq.erase(beg);
			beg = freq.begin()->first;
		}
		else if(freq[end] < freq[beg]){
			ans += freq[end];
			freq.erase(end);
			end = freq.rbegin()->first;
		}
		else{
			
		}
	}
	printf("%d\n",ans);
	return 0;
}