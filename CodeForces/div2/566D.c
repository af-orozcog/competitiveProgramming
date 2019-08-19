#include<stdio.h>

int UF[200001];
int rk[200001];

int set(int n){
	for(int i = 0; i < n;++i){
		UF[i] = i;
		rk[i] = 1;
	}
}

int search(int x){
	return UF[x] == x ? x : (UF[x] =search(UF[x]));
}

int connected(int x, int y){
	if(search(x) == search(y))
		return 1;
	return 0;
}

int connect(int x, int y){
	int dadX = search(x),dadY = search(y);
	if(dadX != dadY){
		if(rk[dadX] > rk[dadY])
			UF[dadY] = dadX;
		else{
			UF[dadX] = dadY;
			if(rk[dadY] == rk[dadX]) ++rk[dadY];
		}
	}
	return 1;
}

int main(){
	int n,q;
	scanf(" %d %d",&n,&q);
	set(n);
	while(q--){
		int t,x,y;
		scanf(" %d %d %d",&t,&x,&y);
		--x;--y;
		if(t == 1)
			connect(x,y);
		else if(t == 2){
			for(int i = x;i <= y;++i)
				connect(x,i);
		}
		else{
			if(connected(x,y))
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}