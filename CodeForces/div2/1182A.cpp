#include<iostream>
#define ll long long

using namespace std;

ll solution(int n){
	if(n == 2)
		return (ll)2;
	return solution(n-2)<<1;
}


int main(){
	int n;
	scanf(" %d",&n);
	if(n&1)
		puts("0");
	else
		cout << solution(n) << endl;
	return 0;
}