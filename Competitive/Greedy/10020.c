#include<stdio.h>

using namespace std;

int main(){
	int cas;
	scanf(" %d",&cas);
	while(scanf--){
		pair<int,int> pa[100000];
		int m;
		scanf(" %d",&m);
		int many = 0;
		int l,r;
		while(scanf(" %d %d",&l,&r) && (l || r)){
			pa[many] = make_pair(l,r);
		}

	}
}