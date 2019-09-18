#include<stdio.h>
#include<map>
#include<vector>

using namespace std;
typedef pair<int,int> pii;

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	int x,y;
	scanf(" %d %d",&x,&y);
	vector<pii> outX;
	vector<pii> outY;
	for(int i = 1; i < m;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		if(a != x && b != x)
			outX.push_back({a,b});
		if(a != y && b != y)
			outY.push_back({a,b});
	}
	if(outX.size() == 0 && outY.size() == 0){
		puts("YES");
		return 0;
	}
	map<int,int> hel1;
	short tr = 0;
	for(int i = 0; i < outX.size();++i){
		int a = outX[i].first,b = outX[i].second;
		if(hel1.count(a) == 0)
			hel1[a] = 1;
		else
			++hel1[a];
		if(hel1.count(b) == 0)
			hel1[b] = 1;
		else
			++hel1[b];
		if(hel1[a] == outX.size())
			tr = 1;
		if(hel1[b] == outX.size())
			tr = 1;
	}
	if(tr){
		puts("YES");
		return 0;
	}
	map<int,int> hel2;
	tr = 0;
	for(int i = 0; i < outY.size();++i){
		int a = outY[i].first,b = outY[i].second;
		if(hel2.count(a) == 0)
			hel2[a] = 1;
		else
			++hel2[a];
		if(hel2.count(b) == 0)
			hel2[b] = 1;
		else
			++hel2[b];
		if(hel2[a] == outY.size())
			tr = 1;
		if(hel2[b] == outY.size())
			tr = 1;
	}
	if(tr)
		puts("YES");
	else
		puts("NO");
	return 0;
}