#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	while(1){
		int a,d;
		scanf(" %d %d",&a,&d);
		if(a == 0 && d == 0)
			break;
		int numsA[a];
		int numsD[d];
		for(int i = 0; i <a;++i)
			scanf(" %d",&numsA[i]);
		for(int i = 0; i < d;++i)
			scanf(" %d",&numsD[i]);
		sort(numsA,numsA+a);
		sort(numsD,numsD+d);
		int pos1 = numsA[0];
		int pos2 = numsD[1];
		if(pos1 < pos2)
			puts("Y");
		else
			puts("N");
	}
	return 0;
}