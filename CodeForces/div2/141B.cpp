#include<stdio.h>
#include<tgmath.h>

int main(){
	int a,x,y;
	scanf(" %d %d %d",&a,&x,&y);
	if(ceil((double)y/(double)a) == ((double)y/(double)a)){
		puts("-1");
		return 0;
	}
	int imp = ceil((double)y/(double)a);
	double xp = (double)x;
	double ap = (double)a;
	double yp = (double)y;
	if(imp == 1 && (x > (-ap/2.0)) && (x < (ap/2.0))){
		puts("1");
		return 0;
	}
	if(imp == 1){
		puts("-1");
		return 0;
	}
	if((imp & 1) &&(x == 0)){
		puts("-1");
		return 0;
	}
	if((imp & 1)){
		if(x >= a || x <= -a)
			puts("-1");
		else if(x < 0){
			int num = imp + (imp/2) -1;
			printf("%d\n",num);
		}
		else if(x > 0){
			int num = imp + (imp/2);
			printf("%d\n",num);
		}
		return 0;
	}
	if((x > (-ap/2.0)) && (x < (ap/2.0))){
		int num = imp + (imp/2) -1;
		printf("%d\n",num);
		return 0;
	}
	puts("-1");
	return 0;
}