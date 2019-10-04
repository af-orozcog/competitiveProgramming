#include<stdio.h>
#include<string.h>
#define min(x,y)(x < y? x:y)

int z = 0, e = 1, r = 2, o = 3, n = 4;

int main(){
	int s;
	scanf(" %d",&s);
	int ocu[5];
	memset(ocu,0,sizeof(ocu));
	for(int i = 0; i < s;++i){
		char va; scanf(" %c",&va);
		if(va == 'z') ++ocu[z];
		if(va == 'e') ++ocu[e];
		if(va == 'r') ++ocu[r];
		if(va == 'o') ++ocu[o];
		if(va == 'n') ++ocu[n];
	}
	int ones = min(ocu[o],min(ocu[n],ocu[e]));
	ocu[o] -= ones;
	ocu[n] -= ones;
	ocu[e] -= ones;
	int zero = min(ocu[z],min(ocu[e],min(ocu[r],ocu[o])));
	for(int i = 0; i < ones;++i) printf("%d ",1);
	for(int i = 0; i < zero;++i) printf("%d ",0);
	puts("");
	return 0;
}