#include<iostream>
#include<vector>
#define min(x,y)(x < y? x:y)

using namespace std;

int main(){
	int siz;
	scanf(siz);
	int a[siz];
	int b[siz];
	int c[siz];
	int d[siz];
	for(int i = 0; i < siz;++i){
		int z,x,c,v;
		scanf(" %d %d %d %d",&z,&x,&c,&v);
		a[i] = z;b[i] = x;c[i] = c;d[i] = v;
	}
	int no;
	for(int i = 0; i < siz;++i){
		int w = 0;
		for(int j = i+1;j <siz;++j){
			if(a[i] < a[j] && b[i] < b[j] &&
				c[i] < c[j]){
				w++;
			}
		}
		if(w == siz-1){
			no = i;
			break;
		}
	}
	int ans = 10001;
	int ann;
	for(int i = 0; i < siz;++i){
		if(i == no)
			continue;
		ans = min(ans,d)
	}
}