#include<iostream>

using namespace std;

int main(){
	unsigned int n,m;
	while(scanf(" %d %d",&n,&m) == 2){
		printf("%u\n",n^m);
	}
	return 0;
}