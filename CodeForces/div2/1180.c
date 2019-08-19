#include<iostream>
#define ll long long
using namespace std;

int main(){
	int read;
	scanf("%d",&read);
	ll ans = 0;
	while(read != 0){
		if(read == 1)
			ans += 1;
		else
			ans += (read-1) << 2;
		--read;
	}
	printf("%d\n",ans);
}