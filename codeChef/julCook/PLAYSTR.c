#include<stdio.h>

int main(){
	int t;
	scanf(" %d",&t);	
	while(t--){
		int s;
		scanf(" %d",&s);
		char a[s+1];
		char b[s+1];
		scanf(" %s",a);
		scanf(" %s",b);
		//printf(" %s  %s",a,b);
		int o1 = 0,i1 = 0,o2= 0,i2 = 0;
		for(int i = 0; i < s;++i){
			if(a[i] == '0')
				++o1;
			if(a[i] == '1')
				++i1;
			if(b[i] == '0')
				++o2;
			if(b[i] == '1')
				++i2;
		}
		if(o1 == o2 && i1 == i2)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}