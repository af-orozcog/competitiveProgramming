/**
* I'm sorry I was an Idiot
*/
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
	cout << ans << "\n";
	return 0;
}