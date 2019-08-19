#include<iostream>
#define max(x,y)(x > y? x:y)
#include<cstring>

using namespace std;

int main(){
	int n,m,k;
	scanf(" %d %d %d",&n,&m,&k);
	char map[n][m];
	int coa[m];
	int coc[m];
	memset(coa,0,sizeof(coa));
	memset(coc,0,sizeof(coc));
	int counter;
	int ans = 0;
	for(int i = 0; i < n;++i){
		counter = 0;
		for(int j = 0; j < m;++j){
			char a;
			scanf(" %c",&a);
			if(a == '*'){
				//cout << counter << endl;
				ans += max(counter-k+1,0);
				coa[j] += max(coc[j]-k+1,0);
				counter = 0;
				coc[j] = 0;
			}
			else{
				++counter;
				++coc[j];
			}
		}
		ans += max(counter-k+1,0);
	}
	if(k == 1){
		printf("%d\n",ans);
		return 0;
	}
	//cout << ans << endl;
	for(int i = 0; i < m;++i){
		ans += coa[i] + max(coc[i]-k+1,0);
	//	cout << coc[i] << endl;
	}
	printf("%d\n",ans);
}