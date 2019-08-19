#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	vector<pair<int,int>> vals(n);
	for(int i = 0; i < n;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		vals[i] = {a,b};
	}
}