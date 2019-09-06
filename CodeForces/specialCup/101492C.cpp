#include<iostream>
#include<map>
#include<vector>
#include<bitset>
#define ll long long

using namespace std;
typedef vector<int> vi;
vi primes;
bitset<100001> bs;

void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i  = 2; i < 100000;++i){
		if(bs[i]){
			for(ll j = i*i; j < 100000;j += i) bs[j] = 0;
			primes.push_back((int)i);
		}
	}
}

vector<int> primeFact(int n){
	int from = 0, pf = primes[from];
	vi ans;
	while(pf*pf <= n){
		while(n % pf == 0){
			n/= pf;
			ans.push_back(pf);
		}
		pf = primes[++from];
	}
	if(n != 1) ans.push_back(n);
	return ans;
}

int main(){
	sieve();
	int n,m;
	scanf(" %d %d",&n,&m);
	map<int,int> f1;
	int f;
	scanf(" %d",&f);
	vector<int> f2 = primeFact(f);
	//cout << "lel" << endl;
	for(auto va : f2){
		if(f1.count(va))
			++f1[va];
		else
			f1[va] = 1;
	}
	vector<map<int,int>> vals(n);
	vi nums(n);
	nums[0] = f;
	vals[0] = f1;
	for(int i = 1; i < n;++i){
		scanf(" %d",&f);
		nums[i] = f;
		f2 = primeFact(f);
		for(auto va : f2){
			if(vals[i].count(va))
				++vals[i][va];
			else
				vals[i][va] = 1;
		}
		for(auto &va : vals[i-1]){
			if(vals[i].count(va.first))
				vals[i][va.first] += va.second;
			else
				vals[i][va.first] = va.second;
		}
	}
	while(m--){
		int a,b;
		scanf(" %d %d",&a,&b);
		--a;--b;
		map<int,int> imp = vals[b];
		if(a != 0){
			for(auto &pa: vals[a-1]){
				imp[pa.first] -= pa.second;
			}
		}
		bool ans = false;
		for(int i = a; i < b && !ans;++i){
			map<int,int> check;
			vi prim = primeFact(nums[i]);
			for(auto va: prim){
				if(check.count(va))
					++check[va];
				else
					check[va] = 1;
			}
			bool yes = true;
			for(auto &pa: check){
				if(imp[pa.first] != pa.second){
					yes = false;
					break;
				}
			}
			if(yes)
				ans = true;
		}
		printf("%c\n",(ans? 'S':'N'));
	}
	return 0;
}