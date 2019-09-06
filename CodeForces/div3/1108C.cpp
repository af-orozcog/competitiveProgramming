#include<iostream>
#define min(x,y)(x < y ? x:y)

using namespace std;

int main(){
	char pos [][3] = {{'B','R','G'},{'B','G','R'},{'R','G','B'}
				,{'R','B','G'},{'G','R','B'},{'G','B','R'}};
	int n;
	scanf(" %d",&n);
	char re[n];
	for(int i = 0; i < n;++i) scanf(" %c",&re[i]);
	char ansc[n+1];
	ansc[n] = '\0';
	int ans = 10000000;
	for(int i = 0; i < 6;++i){
		int chan = 0;
		char temp[n];
		for(int j = 0,po = 0; j < n;++j,po = (po+1)%3){
			if(pos[i][po] != re[j])
				++chan;
			temp[j] = pos[i][po];
		}
		if(chan < ans){
			ans = chan;
			for(int j = 0; j < n;++j) ansc[j] = temp[j];
		}
	}
	printf("%d\n%s\n",ans,ansc);
	return 0;
}