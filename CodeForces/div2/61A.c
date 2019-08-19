#include<stdio.h>

int main(){
	char ar1[101];
	char ar2[101];
	scanf(" %s",ar1);
	scanf(" %s",ar2);
	char ans[101];
	int i = 0;
	for(; i < 101 && ar1[i]!= '\0';++i){
		if(ar1[i] != ar2[i])
			ans[i] = '1';
		else
			ans[i] = '0';
	}
	ans[i] = '\0';
	printf("%s\n",ans);
	return 0;
}