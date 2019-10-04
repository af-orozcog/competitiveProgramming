#include<iostream>
#define ll long long

using namespace std;

ll solution(int n){
	if(n == 2)
		return 2;
	return 2*solution(n-2);
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