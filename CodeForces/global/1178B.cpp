#include<iostream>
#include<string>
#include<cstring>
#define ll long long

using namespace std;

int main(){
	string read;
	cin >> read;
	ll dpleft[read.size()];
	ll dpright[read.size()];
	dpleft[0] = 0;
	dpright[read.size()-1] = 0;
	ll counter = (read[0] == 'v') ? 1:0;
	for(int i = 1; i < read.size();++i){
		if(read[i] == 'v'){
			++counter;
		}
		if(read[i] == 'o'){
			dpleft[i] = dpleft[i-1] + counter -1;
			counter = 0;
			continue;
		}
		dpleft[i] = dpleft[i-1];
	}
	counter = read[read.size()-1] == 'v'? 1:0;
	for(int i = read.size()-2; i >= 0;--i){
		if(read[i] == 'v'){
			++counter;
		}
		if(read[i] == 'o'){
			dpright[i] = dpright[i+1] + counter -1;
			counter = 0;
			continue;
		}
		dpright[i] = dpright[i+1];
	}
	ll ans = 0;
	for(int i = 0; i < read.size();++i){
		if(read[i] == 'o'){
			ans += dpright[i] * dpleft[i];
		}
	}
	cout << ans << endl;
	return 0;
}