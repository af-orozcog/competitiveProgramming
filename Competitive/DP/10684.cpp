/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define max(x,y)(x > y ? x: y)

using namespace std;

int main(){
	int siz;
	while(cin >> siz){
		if(siz == 0)
			break;
		int sum, ans;
		sum = ans = 0;
		while(siz--){
			int val;
			cin >> val;
			sum += val;
			ans = max(sum,ans);
			if(sum < 0)
				sum = 0; 
		}
		if(ans <= 0)
			puts("Losing streak.");
		else
			printf("The maximum winning streak is %d.\n", ans);
	}
	return 0;
}