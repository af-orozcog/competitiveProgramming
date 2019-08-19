#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){
	int siz;
	scanf(" %d",&siz);
	int ans = 0;
	map<int,int> can;
	vector<pair<int,int>> num(siz);
	for(int i= 0; i < siz;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		num[i] = make_pair(a,b);
		if(can.count(b))
			++can[b];
		else
			can[b] = 1;
	}
	for(int i = 0; i < siz;++i){
		if(num[i].first == num[i].second){
			if(can.count(num[i].first)){
				if(can[num[i].first] > 1)
					++ans;
			}
		}
		else if(can.count(num[i].first))
			++ans;
	}
	printf("%d\n",siz -ans);
}