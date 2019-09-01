#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int main(){
	while(1){
		int n,m;
		scanf(" %d %d",&n,&m);
		if(!n)
			break;
		bool pos[n];
		memset(pos,true,sizeof(pos));
		while(m--){
			int a,b;
			scanf(" %d %d",&a,&b);
			if(b < 0){
				b+= 1;
				pos[abs(b)] = false; 
			}
		}
		int ans = 0;
		for(int i = 0; i< n;++i)
			if(pos[i])
				++ans;
		printf("%d\n",ans);
	}
	return 0;
}