#include<stdio.h>

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int n;
		scanf(" %d",&n);
		 int ck = 0;
        while(n%2==0){
            ck++;
            n/=2;
        }
        ck++;
        printf("%d\n",ck);
        ck=0;
	}
}