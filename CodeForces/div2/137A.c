/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int main(){
	char toSee[101];
	scanf("%s",toSee);
	int conse = 0;
	int ans = 0;
	for(int i = 0; toSee[i+1] != '\0';++i){
		if(toSee[i] != toSee[i+1]){
			++ans;
			conse = 0;
		}
		else
			++conse;
		if(conse == 5){
			++ans;
			conse = 0;
		}
	}
	++ans;
	printf("%d\n",ans);
}