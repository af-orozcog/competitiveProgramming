#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	string re;
	cin >> re;
	for(int i = 1; i < n;++i){
		if(re[i-1] > re[i]){
			puts("YES");
			printf("%d %d\n",i,i+1);
			return 0;
		}
	}
	puts("NO");
	return 0;
}