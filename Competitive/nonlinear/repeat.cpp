/**
*for the team and валентина в
*/
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int main(){
	map<int, int> occur;
	string num;
	vector<int> unique;
	while(cin >> num){
		int val = stoi(num);
		if(occur.count(val) > 0){
			int val1 = occur[val];
			occur[val] = val1+1;
		}
		else{
			occur[val] = 1;
			unique.push_back(val);
		}
	} 
	for(int i = 0; i < unique.size();i++){
		cout << unique[i] << " " << occur[unique[i]] << endl;
	}
	return 0;
}