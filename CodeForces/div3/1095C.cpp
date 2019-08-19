    /**
    * probably get TLE
    */
    #include<iostream>
    #include<vector>
    #define ll long long
     
    using namespace std;
     
     
    int log2(ll a){
    	int i = 0;
    	while(a){
    		a = a >> 1;
    		++i;
    	}
    	return i;
    }
     
    vector<ll> ans(ll N,ll K){
    	vector<ll> a;
    	ll copy = N;
    	int i = 0;
    	while(copy){
    		ll add = copy & (1 << i);
    		if(add != 0)
    			a.push_back(add);
    		add = ~add;
    		copy = copy & add;
    		++i;
    	}
    	if(a.size() > K){
    		a.clear();
    		return a;
    	}
        cout << "before ? "<< a.size() << endl;
    	for(int i = 0; i < a.size() && a.size() < K;++i){
    		if(a[i] != 1){
    			ll m = a[i];
                int n = 2;
                m /= 2;
                while(n + a.size() < K && m > 1){
                    m /= 2;
                    n *= 2;
                }
    			--i;
    		}
    	}
    	/*if(a.size() != K){
    		a.clear();
    		return a;
    	}*/
    	return a;
    }
     
    int main(){
    	ll N,K;
    	cin >> N >>K;
    	vector<ll> an = ans(N,K);
    	if(an.size() == 0){
    		cout << "NO" << endl;
    		return 0;
    	}
    	cout << "YES" << endl;
    	for(int i = 0; i < an.size();++i){
    		if(i == 0)
    			cout << an[i];
    		else
    			cout << " " << an[i];
    	}
    	cout << endl;
    	return 0;
    }