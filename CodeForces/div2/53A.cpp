/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main(){
	string toSee;
	cin >> toSee;
	int siz;
	cin >> siz;
	vector<string> vals(siz);
	for(int i = 0; i < siz;++i){
		cin >> vals[i];
	}
	sort(vals.begin(),vals.end());
	vector<string>::iterator low = lower_bound(vals.begin(),vals.end(),toSee);
	if(low == vals.end()){
		cout << toSee << endl;
		return 0;
	}
	string toCheck = vals[low - vals.begin()];
	for(int i = 0; i < toSee.size();++i){
		if(toSee[i] != toCheck[i]){
			cout << toSee << endl;
			return 0;
		}
	}
	cout << toCheck << endl;
	return 0;
}