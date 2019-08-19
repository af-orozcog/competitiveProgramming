#include<iostream>
#include<map>
#include<climits>
#define min(x,y)(x < y? x:y)

using namespace std;

int main(){
	int t;
	int m = scanf(" %d",&t);
	map<char,char> next;
	next['R'] = 'G';
	next['G'] = 'B';
	next['B'] = 'R';
	char let[] = {'G','B','R'};
	while(t--){
		int siz,k;
		scanf(" %d %d",&siz,&k);
		char ar[siz+1];
		scanf(" %s",ar);
		int ans = INT_MAX;
		for(int i = 0; i < siz-k+1;++i){
			for(int w = 0; w < 3;++w){
				char last = let[w];
				int chan = 0;
				if(last != ar[i])
					++chan;
				for(int j = 1; j < k && chan < ans;++j){
					if(ar[i+j] != next[last])
						++chan;
					last = next[last];
				}
				ans = min(ans,chan);
			}
		}
		printf("%d\n",ans);
	}
}