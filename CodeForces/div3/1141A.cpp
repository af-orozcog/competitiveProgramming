#include<iostream>
#define max(x,y)(x > y? x:y)
using namespace std;

int main(){
	int a,b;
	scanf(" %d %d",&a,&b);
	if(b % a != 0){
		puts("-1");
		return 0;
	}
	int t = 0;
	int div = b / a;
	while(div != 1){
		if(div % 2 == 0){
			//cout << 1 << endl;
			div = div >> 1;
		}
		else if(div % 3 == 0){
			//cout << 2<< endl;
			div = div / 3;
		}
		else{
			t = -1;
			break;
		}
		++t;
	}
	printf("%d\n",t);
	return 0;
}