#include<iostream>
#include<vector>
#include<set>

using namespace std;

int UF[1001];

void sett(int n){
	for(int i = 0; i < n;++i)
		UF[i] = i;
}

int search(int x){
	return UF[x] == x? x :(UF[x] = search(UF[x]));
}

bool connected(int x,int y){
	return search(x) == search(y); 
}

void connect(int x, int y){
	int dadX = search(x),dadY = search(y);
	if(dadX != dadY)
		UF[dadX] = dadY;
}

int main(){
	int n;
	scanf(" %d",&n);
	sett(n);
	vector<pair<int,int>> change;
	for(int i = 0; i< n-1;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		--a;--b;
		if(connected(a,b)){
			change.push_back({a,b});
			continue;
		}
		connect(a,b);
	}
	if(change.size() == 0){
		puts("0");
		return 0;
	}
	vector<pair<pair<int,int>,pair<int,int>>> ans;
	for(int i = 0; i < change.size();++i){
		for(int j = 0; j < n;++j){
			if(!connected(change[i].first,j)){
				connect(change[i].first,j);
				ans.push_back({{change[i].first,change[i].second},{change[i].first,j}});
				break;
			}
		}
	}
	printf("%d\n",(int)ans.size());
	for(int i = 0; i < ans.size();++i)
		printf("%d %d %d %d\n",ans[i].first.first+1,ans[i].first.second+1,ans[i].second.first+1,ans[i].second.second+1);
	return 0;
}