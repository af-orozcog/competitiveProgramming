#include<iostream>
#include<vector>
#include<algorithm>
#define min(x,y)(x < y?x:y)

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int siz;
		cin >> siz;
		vector<int> va(siz);
		for(int i = 0; i < siz;++i){
			cin >> va[i];
		}
		sort(va.begin(),va.end());
		int im = va[siz-2];
		cout << min(siz-2,im-1) << endl;
	}
	return 0;
}