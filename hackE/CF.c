#include<stdio.h>

int UF[100001];
int rk[100001];

int set(int n){
	for(int i = 0; i < n;++i){
		UF[i] = i;
		rk[i] = 1;
	}
	return 1;
}

int search(int x){
	return (UF[x] == x)?x:(UF[x] = search(UF[x]));
}

int connect(int x, int y){
	int dadX = search(x),dadY = search(y);
	if(dadX != dadY){
		rk[dadX] += rk[dadY];
		UF[dadY] = dadX;
	}
}

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	set(n);
	while(m--){
		int a,b;
		scanf(" %d %d",&a,&b);
		--a;--b;
		connect(a,b);
	}
	for(int i = 0; i < n;++i){
		if(i == 0)
			printf("%d", rk[search(i)]-1);
		else
			printf(" %d",rk[search(i)]-1);
	}
	puts("");
	return 0;
}