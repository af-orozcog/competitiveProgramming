#include<iostream>
#include<string>

using namespace std;

int main(){
	int n,k;
	scanf(" %d %d",&n,&k);
	char num[n+1];
	scanf(" %s",num);
	for(int i = 0,j = 0; i < n && j < k;++i){
		if((i == n-1 || i != 0) && num[i] != '0'){
			num[i] = '0';
			++j;
		}
		else if(num[i] != '0' && num[i] != '1'){
			num[i] = '1';
			++j;
		}
	}
	printf("%s\n", num);
	return 0;
}