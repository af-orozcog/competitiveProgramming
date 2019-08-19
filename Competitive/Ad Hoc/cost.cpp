#include<stdio.h>

using namespace std;

int main(){
	int cases;
	scanf("%d",&cases);
	for(int i = 0; i < cases;i++){
		int v1,v2,v3;
		scanf("%d %d %d",&v1,&v2,&v3);
		if(v1 < v2 && v1 < v3){
			if(v2 > v3)
				printf("Case %d: %d\n",(i+1),v3);
			else
				printf("Case %d: %d\n",(i+1),v2);
		}
		else if(v2 < v1 && v2 < v3){
			if(v1 > v3)
				printf("Case %d: %d\n",(i+1),v3);
			else
				printf("Case %d: %d\n",(i+1),v1);
		}
		else{
			if(v2 > v1)
				printf("Case %d: %d\n",(i+1),v1);
			else
				printf("Case %d: %d\n",(i+1),v2);
		}
	}
	return 0;
}