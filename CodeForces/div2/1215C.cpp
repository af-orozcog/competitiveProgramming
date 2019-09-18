#include<iostream>
#include<vector>

using namespace std;
typedef vector<pair<int,int>> vip;

int main(){
	int siz;
	scanf(" %d",&siz);
	char st1[siz+1];
	char st2[siz+1];
	scanf(" %s",st1); scanf(" %s",st2);
	vector<int> neA,neB;
	for(int i = 0; i < siz;++i){
		if(st1[i] != st2[i]){
			if(st1[i] == 'a')
				neB.push_back(i);
			else
				neA.push_back(i);
		}
	}
	if(((int)neA.size() & 1)!=((int)neB.size() & 1)){
		puts("-1");
		return 0;
	}
	vip ans;
	for(int i = 0; i < ((int)neA.size())-1;i+=2)
		ans.push_back({neA[i],neA[i+1]});
	for(int i = 0; i < ((int)neB.size())-1;i+=2)
		ans.push_back({neB[i],neB[i+1]});
	if((int)neA.size() & 1){
		ans.push_back({neB[neB.size()-1],neB[neB.size()-1]});
		ans.push_back({neB[neB.size()-1],neA[neA.size()-1]});
	}
	printf("%d\n",(int)ans.size());
	for(auto va:ans)
		printf("%d %d\n",va.first + 1,va.second+ 1);
	return 0;
}