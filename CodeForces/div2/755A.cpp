/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<bitset>
#include<vector>
#include<algorithm>

using namespace std;

bitset<10001> pos;
vector<int> primes;

void set(){
	pos.set();
	for(int i = 2;i <= 10000;++i){
		if(pos[i]){
			int m = 2;
			while(i * m <= 10000){
				pos.set(i*m,0);
				++m;
			}
			primes.push_back(i);
		}
	}
}

int main(){
	set();
	int toCheck;
	cin >> toCheck;
	if(toCheck == 2){
		cout << 4<< endl;
		return 0;
	}
	vector<int>::iterator low = lower_bound(primes.begin(),primes.end(),toCheck);
	if(primes[low - primes.begin()] == toCheck){
		cout << 1 << endl;
	}
	else{
		if(primes[low -primes.begin()] != toCheck + 1)
			cout << 1 << endl;
		else{
			int i = 2;
			while(true){
				int co = (toCheck * i) + 1; 
				vector<int>::iterator low = lower_bound(primes.begin(),primes.end(),co);
				if(primes[low -primes.begin()] != co){
					cout << i << endl;
					return 0;
				}
				++i;
			}
		}
	}
	return 0;
}