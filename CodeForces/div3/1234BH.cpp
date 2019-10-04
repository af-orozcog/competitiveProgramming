#include<iostream>
#include<deque>
#include<set>
#define min(x,y)(x < y? x:y)

using namespace std;

int main(){
	int n,k;
	scanf(" %d %d",&n,&k);
	deque<int> show;
	set<int> in;
	for(int i = 0; i < n;++i){
		int val;
		scanf(" %d",&val);
		if(in.count(val))
			continue;
		show.push_front(val);
		in.insert(val);
		if(show.size() > k){
			int del = show.back();
			in.erase(del);
			show.pop_back();
		}
	}
	printf("%d\n",min((int)show.size(),k));
	while(show.size()){
		printf("%d ",show.front());
		show.pop_front();
	}
	puts("");
	return 0;
}