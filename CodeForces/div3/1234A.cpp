#include<iostream>

using namespace std;

int main(){
	int q;
	scanf(" %d",&q);
	while(q--){
		int n;
		scanf(" %d",&n);
		int sum =0;
		for(int i = 0; i < n;++i){
			int val;
			scanf(" %d",&val);
			sum += val;
		}
		printf("%d\n",sum/n +(sum%n != 0 ? 1:0));
	}
	return 0;
}