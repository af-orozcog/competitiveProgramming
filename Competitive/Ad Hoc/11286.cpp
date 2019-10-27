#include<iostream>
#include<map>
#include<queue>
#define ll long long

using namespace std;

int main(){
	while(1){
		int n;
		scanf(" %d",&n);
		if(!n)
			break;
		map<ll,int> ocu;
		int max = 0;
		int many = 0;
		for(int i = 0; i < n;++i){
			priority_queue<ll> q;
			for(int j = 0; j< 5;++j){
				ll val;scanf(" %lld",&val);
				q.push(val);
			}
			ll num = 0;
			for(int j = 0; j < 5;++j){
				num *= 1000;
				num += q.top();
				q.pop();
			}
			//cout << num << endl;
			if(ocu.count(num))
				++ocu[num];
			else
				ocu[num] = 1;
			if(ocu[num] > max){
				max = ocu[num];
				many = 0;
			}
			if(ocu[num] == max) many+=max;
		}
		printf("%d\n",many);
	}
}