#include<iostream>
#include<cstring>
#define max(x,y)(x > y?x:y)

using namespace std;

int main(){
	int cum[1000][5];
	memset(cum,0,sizeof(cum));
	int st,q;
	scanf(" %d %d",&st,&q);
	int scores[q];
	for(int i = 0; i < st;++i){
		for(int j = 0; j < q;++j){
			char l;
			scanf(" %c",&l);
			++cum[j][l -'A'];
		}
	}
	for(int i = 0; i < q;++i)
		scanf(" %d",&scores[i]);
	int ans = 0;
	for(int i = 0; i < q;++i){
		int ma = 0;
		ma = max(ma,cum[i][0]);
		ma = max(ma,cum[i][1]);
		ma = max(ma,cum[i][2]);
		ma = max(ma,cum[i][3]);
		ma = max(ma,cum[i][4]);
		ans += ma*scores[i];
	}
	printf("%d\n",ans);
	return 0;
}