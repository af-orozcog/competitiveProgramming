#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int s,b;
	scanf(" %d %d",&s,&b);
	int at[s];
	for(int i = 0; i < s;++i)
		scanf(" %d",&at[i]);
	vector<pair<int,int>> ba(b);		
	for(int i = 0; i < b;++i){
		int d,g;
		scanf(" %d %d",&d,&g);
		ba[i] = make_pair(d,g);
	}
	sort(ba.begin(),ba.end());
	for(int i = 0;i < s;++i){
		int g = 0;
		int a = at[i];
		//cout << a << endl;
		int m = 0;
		while(m < b && a >= ba[m].first){
			g += ba[m].second;
			++m;
		}
		if(i == 0)
			printf("%d", g);
		else
			printf(" %d",g);
	}
	puts("");
	return 0;
}