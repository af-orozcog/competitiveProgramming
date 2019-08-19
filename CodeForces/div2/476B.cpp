#include<iostream>
#include<string>

using namespace std;

string a,b;
int siz;
int ta;

double solve(int n,int p){
	if(n == siz){
		if(ta == p)
			return 1.0;
		return 0;
	}
	if(b[n] == '?')
		return solve(n+1,p+1)*0.5 + solve(n+1,p-1)*0.5;
	int sum = (b[n] == '+'? 1:-1);
	return solve(n+1,p+ sum);
}

int main(){
	cin >> a >> b;
	siz = a.size();
	int t = 0;
	for(int i = 0; i < siz;++i){
		if(a[i] == '+')
			++t;
		else
			--t;
	}
	ta = t;
	printf("%.10f\n",solve(0,0));
	return 0;
}