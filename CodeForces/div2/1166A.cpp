#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	int num[26];
	memset(num,0,sizeof(num));
	while(n--){
		string r;
		cin >> r;
		++num[r[0]-'a'];
	}
	int ans = 0;
	for(int i = 0; i < 26;++i){
		int a = num[i] >> 1;
		int b = num[i] - a;
		ans += (a*(a-1))>>1;
		ans += (b*(b-1))>>1;
	}
	printf("%d\n",ans);
	return 0;
}