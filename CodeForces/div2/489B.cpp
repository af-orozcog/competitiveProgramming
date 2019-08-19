#include<iostream>
#include<vector>
#include<algorithm>
#define abs(x)(x < 0?-x:x)

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n;++i){
		cin >> a[i];
	}
	cin >> n;
	vector<int> b(n);
	for(int i = 0; i <n;++i){
		cin >> b[i];
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int f = 0;
	int ans = 0;
	for(int i = 0; i < a.size();++i){
		int search = a[i]-1;
		int in = lower_bound(b.begin()+f,b.end(),search) - b.begin();
		if(in == b.size())
			break;
		if(abs(b[in]-a[i]) <= 1){
			++ans;
			f = in + 1;
		}
	}
	cout << ans<< endl;
	return 0;
}