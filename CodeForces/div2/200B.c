/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int main(){
	int many;
	scanf(" %d",&many);
	double div = many * 100.0;
	double cum = 0.0;
	while(many--){
		double val;
		scanf(" %f",&val);
		cum += val;
	}
	printf("%f\n",(cum/div)*100.0);
	return 0;
}