#include<stdio.h>
#include<stdlib.h>
#define max(x,y)(x > y? x:y)

int main(){
	int x1,y1,x2,y2;
	scanf(" %d %d %d %d",&x1,&y1,&x2,&y2);
	int md1,md2;
	scanf(" %d %d",&md1,&md2);
	int distX = abs(x1-x2);
	if(distX % md1 != 0){
		puts("NO");
		return 0;
	}
	int distY = abs(y1-y2);
	if(distY % md2 != 0){
		puts("NO");
		return 0;
	}
	distY /= md2;
	distX /= md1;
	int ma = max(distY,distX);
	distX -= ma;
	distY -= ma;
	if(distY % 2 == 0 && distX % 2 == 0)
		puts("YES");
	else
		puts("NO");
	return 0;
}