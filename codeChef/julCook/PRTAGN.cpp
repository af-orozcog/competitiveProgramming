/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

bool isEven(int check){
	int num = 0;
	while(check){
		if(check & 1)
			++num;
		check = check >> 1;
	}
	return num % 2 == 0;
}

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		int que;
		cin >> que;
		int odd = 0;
		int even = 0;
		unordered_map<int,bool> ele;
		while(que--){
			int val;
			cin >> val;
			if(ele.count(val)){
				cout << even << " "<< odd << endl;
				continue;
			}
			else{
				if(isEven(val))
					++even;
				else
					++odd;
				vector<int> toAdd;
				for(auto &it: ele){
					int add = val ^ it.first;
					if(ele.count(add))
						continue;
					if(add == val)
						continue;
					if(isEven(add))
						++even;
					else
						++odd;
					toAdd.push_back(add);
				}
				ele[val] = true;
				for(int i = 0; i < toAdd.size();++i){
					ele[toAdd[i]] = true;
				}
			}
			cout << even << " "<< odd << endl;
		}
	}
	return 0;
}