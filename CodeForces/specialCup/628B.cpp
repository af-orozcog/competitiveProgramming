#include<iostream>
#include<cstring>
#include<string>
#define ll long long

using namespace std;

int main(){
	string re;
	cin >> re;
	ll ans= 0;
	for(int i = 0; i< re.size();++i){
		if((re[i]-'0')%4 == 0)
			++ans;
	}
	for(int i = 0; i < re.size() - 1;++i){
		if(((re[i]-'0')*10 + re[i+1]-'0') % 4 == 0)
			ans += (i+1);
	}
	cout << ans << endl;
	return 0;
}