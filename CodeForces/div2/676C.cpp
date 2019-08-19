#include<iostream>
#include<vector>
#define max(x,y)(x > y? x:y)
#define min(x,y)(x < y?x:y)

using namespace std;

int main(){
	int n,k;
	scanf(" %d %d",&n,&k);
	vector<pair<int,int>> ar;
	vector<pair<int,int>> br;
	int s;
	char last;
	char st[n+1];
	scanf(" %s",st);
	for(int i = 0; i < n;++i){
		if(i == 0){
			s = i;
			last = st[i];
			continue;
		}
		if(st[i] != last){
			if(last == 'a')
				ar.push_back(make_pair(s,i-1));
			else
				br.push_back(make_pair(s,i-1));
			s= i;
			last = st[i];
		}
	}
	if(last == 'a')
		ar.push_back(make_pair(s,n-1));
	else
		br.push_back(make_pair(s,n-1));
	int ans = 0;
	for(int i = 0; i < ar.size();++i){
		int siz = ar[i].second - ar[i].first;
		//cout << ar[i].first << " " << ar[i].second << endl;
		++siz;
		int co = k;
		int j = 0;
		while(i + j < ar.size()-1 && co){
			int dist = ar[i+j+1].first - ar[i+j].second;
			--dist;
		//	cout << "dist is " << dist << endl; 
			if(co < dist)
				break;
			co-= dist;
			siz += ar[i+j+1].second - ar[i+j+1].first;
			++siz;
			siz += dist;
			++j;
		}
		//cout << siz << endl;
		siz += co;
		ans = max(ans,siz);
	}
	for(int i = 0; i < br.size();++i){
		int siz = br[i].second - br[i].first;
		++siz;
		int co = k;
		int j = 0;
		while(i + j < br.size()-1 && co){
			int dist = br[i+j+1].first - br[i+j].second;
			--dist;
			if(co < dist)
				break;
			co-= dist;
			siz += br[i+j+1].second - br[i+j+1].first;
			++siz;
			siz += dist;
			++j;
		}
		siz += co;
		ans = max(ans,siz);
	}
	printf("%d\n",min(ans,n));
	return 0;
}