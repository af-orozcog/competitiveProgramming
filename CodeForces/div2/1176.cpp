/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#define ll long long
#include<bitset>
#include<algorithm>

using namespace std;


int main(){
	int siz;
	cin >> siz;
	vector<int> vals(6,0);
	int co = siz;
	while(siz--){
		int val;
		cin >> val;
		if(val == 4)
			++vals[0];
		else if(val == 8 && vals[0]){
			++vals[1];
			--vals[0];
		}
		else if(val == 15 && vals[1]){
			++vals[2];
			--vals[1];
		}
		else if(val == 16 && vals[2]){
			++vals[3];
			--vals[2];
		}
		else if(val == 23 && vals[3]){
			++vals[4];
			--vals[3];
		}
		else if(val == 42 && vals[4]){
			++vals[5];
			--vals[4];
		}
	}
	cout << co - (vals[5]*6) << endl;
	return 0;
}