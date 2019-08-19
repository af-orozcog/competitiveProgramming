#include<iostream>
#include<string>
#define ll long long
#define M 1000000007

using namespace std;

int main(){
	ll ans = 0;
	ll dp = 0;
	string re;
	cin >> re;
	ll cum = 0;
	for(int i = 0; i < re.size();++i){
		if(re[i] == 'b'){
			ans += cum;
			ans = ans %M;
			ans += dp * cum;
			ans = ans % M;
			dp+= cum;
			cum = 0;
		}
		else if(re[i] == 'a')
			++cum;
	}
	ans += cum;
	ans = ans %M;
	ans += dp * cum;
    ans = ans % M;
	dp+= cum;
	cout << ans << endl;
	return 0;
}