#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll MAX_SIZE = 1000001; 

const char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y' ,'Z'};
vector<ll>isprime(MAX_SIZE , true); 
vector<ll>prime; 
vector<ll>SPF(MAX_SIZE); 
  

void manipulated_seive(ll N) 
{ 
    isprime[0] = isprime[1] = false ; 
  
    for (ll i=2; i<N ; i++) 
    { 
        if (isprime[i]) 
        { 
            prime.push_back(i); 
  
            SPF[i] = i; 
        } 
  
        for (ll j=0; 
             j < (int)prime.size() && 
             i*prime[j] < N && prime[j] <= SPF[i]; 
             j++) 
        { 
            isprime[i*prime[j]]=false; 
   
            SPF[i*prime[j]] = prime[j] ; 
        } 
    } 
}
int main(){
	int testCases;
	manipulated_seive(10000);
	cin >> testCases;
	for(int i = 0; i < testCases; i++){
		ll N,charac;
		cin >> N >> charac;
		ll nums[charac];
		ll primeUsedOrd[charac+1];
		ll primeUsedUno[charac+1];
		for(ll e = 0; e < charac; e++){
			ll num;
			cin >> num;
			nums[e] = num;
		}
		ll first;
		ll second;
		for(ll e = 0; e < prime.size();e++){
			for(ll u = e; u < prime.size();u++){
				if((prime[e] * prime[u]) == nums[0]){
					first = prime[e];
					second = prime[u];
					break;
				}
			}
		}
		int flag = 0;
		for(ll a = 0; a < prime.size(); a++){
			if((first * prime[a]) == nums[1]){
				flag = 1;
				primeUsedOrd[2] = prime[a];
				primeUsedUno[2] = prime[a];
				break;
			}
		}
		if(flag == 1){
			ll temp = first;
			first = second;
			second = temp;
		}
		primeUsedOrd[0] = first;
		primeUsedOrd[1] = second; 
		primeUsedUno[0] = first;
		primeUsedUno[1] = second;
		ll position = 1 + flag;
		for(ll m = (3-(1-flag)); m < charac+1 && position < charac; m++){
			ll val = nums[position++]/primeUsedOrd[m-1];
			primeUsedOrd[m] = val;
			primeUsedUno[m] = val;
		}
		ll n = sizeof(primeUsedOrd) /sizeof(primeUsedOrd[0]);
		sort(primeUsedOrd,primeUsedOrd+n);
		/*for(int l = 0; l < charac + 1; l++){
			cout << primeUsedOrd[l] << endl;
		}*/
		map<ll,char> letterMap;
		ll position2 = 0;
		for(ll t = 0; t < charac + 1 && position2 < 26; t++){
			if(t == 0 || (primeUsedOrd[t-1] != primeUsedOrd[t]))
			    letterMap.insert(pair<ll,char>(primeUsedOrd[t],alphabet[position2++]));
		}
		string answer = "";
		for(ll q = 0; q < charac +1; q++){
			answer += letterMap.at(primeUsedUno[q]);
		}
		    cout << "Case #" <<(i+1) << ": " << answer << endl;
	}
	return 0;
}