/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>

using namespace std;

bitset<100001> pos;
vector<int> primes;

void sieve(){
	pos.set();
	for(int i = 2; i <= 100000;++i){
		if(pos[i]){
			int m = 2;
			while(i*m <= 100000){
				pos.set(i*m,0);
				++m;
			}
			primes.push_back(i);
		}
	}
}

int power2(int val){
	int i = -1;
	while(val){
		++i;
		val = val >> 1;
	//	cout << "por"<< endl;
	}
	//cout << "aqui???" << endl;
	return i;
}

int leastPrime(int val){
	for(int i = 0; i < primes.size();++i){
		if(val % primes[i] == 0)
			return primes[i];
	}
}

bool com(const pair<int,pair<int,int>> a, const pair<int,pair<int,int>> b){
	if(a.second.first > b.second.first)
		return true;
	if(a.second.first < b.second.first)
		return false;
	if(a.second.second > b.second.second)
		return true;
	if(a.second.second < b.second.second)
		return false;
	return false;
}

int main(){
	sieve();
	int cas;
	cin >> cas;
	//cout <<"lil" << endl;
	while(cas--){
		int siz;
		cin >> siz;
		vector<pair<int,pair<int,int>>> nums(siz);
		for(int i = 0; i < siz;++i){
			int val;
			cin >> val;
	//		cout << "lee?" << endl;
			nums[i] = make_pair(val,make_pair(power2(val),leastPrime(val)));
		}
		//cout << "aqui?" << endl;
		stable_sort(nums.begin(),nums.end(),com);
		//cout << "paso aqui" << endl;
		for(int i = 0; i < siz;++i){
			if(i != siz-1)
				cout << nums[i].first << " ";
			else
				cout << nums[i].first << endl;
		}
	}
	return 0;
}