/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define ll long long
#define max(x,y)(x > y? x:y)
#define min(x,y)(x < y? x:y)

using namespace std;

int main(){
	ll ori,co;
	cin >> co >> ori;
	if(ori == 0 || (ori == 1 && co > 0)){
		puts("No");
		return 0;
	}
	if(ori - co > 1){
		puts("No");
		return 0;
	}
	if(ori - co == 1){
		puts("Yes");
		return 0;
	}
	ll alreadyCo = ori -1;
	if((co - alreadyCo)& 1){
		puts("No");
		return 0;
	} 
	puts("Yes");
	return 0;
}