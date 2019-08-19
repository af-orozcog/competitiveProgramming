/**
* I'm not doing this for you 
* or I do?
*/
#include<iostream>
#include<vector>

using namespace std;

int main(){
	int siz;
	scanf(" %d",&siz);
	int ar[siz];
	int sum = 0;
	for(int i = 0; i < siz;++i){
		int val;
		scanf(" %d",&val);
		ar[i] = val;
		sum += val;
	}
	if(ar[0] > (sum>>1)){
		cout << 1 << endl << 1 << endl;
		return 0;
	}
	vector<int> ans(1,0);
	int summ = ar[0];
	for(int i = 1; i < siz;++i){
		if((ar[i]<<1) <= ar[0]){
			ans.push_back(i);
			summ += ar[i];
		}
	}
	//cout << summ <<endl;
	if(summ <= (sum >> 1)){
		cout << 0 << endl;
		return 0;
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size();i++){
		if(i == 0)
			cout << ans[i]+1;
		else
			cout << " " << ans[i]+1;
	}
	cout << endl;
	return 0;
}