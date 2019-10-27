/**
* I don't hate you, cause you are the reason I
* started doing this
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;

string getZarr(string &str) 
{ 
    int n = str.length();
    int L, R, k;
    int siz = str.size();
    vi Z(str.size());
    set<int> check;
    L = R = 0; 
    for (int i = 1; i < n; ++i) 
    { 
        if (i > R) 
        { 
            L = R = i; 
            while (R<n && str[R-L] == str[R]) 
                R++; 
            Z[i] = R-L; 
            R--; 
        } 
        else
        { 
            k = i-L;
            if (Z[k] < R-i+1) 
                Z[i] = Z[k];  
            else
            { 
                L = i; 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; 
            } 
        }
        if(Z[i] == (siz-i))
        	check.insert(Z[i]);
    }
    int toCheck = 0;
    for(int i = 0; i < str.size();++i){
    	if(Z[i]){
    		auto va = check.lower_bound(Z[i]);
    		if(*va == Z[i] && Z[i] != (siz-i))
    			toCheck = max(toCheck,Z[i]);
    		if(va != check.begin()){
    			--va;
    			toCheck = max(toCheck,*va);
    		}
    	}
    }
    return str.substr(0,toCheck);
}


int main(){
	string re;
	cin >> re;
	string ans = getZarr(re);
	if(ans.size())
		cout << ans << endl;
	else
		puts("Just a legend");
	return 0;
}