#include<iostream>

using namespace std;

int main(){
	int t;scanf(" %d",&t);
	while(t--){
		int L,v,l,r;scanf(" %d %d %d %d",&L,&v,&l,&r);
		int numsDiv = (r/v) - ((l-1)/v);
		int total = L/v;
		printf("%d\n",total-numsDiv); 
	}
	return 0;
}
