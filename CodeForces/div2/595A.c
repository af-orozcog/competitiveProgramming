#include<stdio.h>

int main(){
	int f,m;
	scanf(" %d %d",&f,&m);
	short flag = 0;
	int ans = 0;
	for(int i = 0; i < f;++i){
		for(int j = 1; j <= (m<<1);++j){
			short val;scanf(" %hd",&val);
			if(val){
				++ans;
				if(j & 1)
					flag = 1;
				else{
					ans -= flag;
					flag = 0;
				}
			}
			else
				flag = 0;
		}
	}
	printf("%d\n",ans);
	return 0;
}