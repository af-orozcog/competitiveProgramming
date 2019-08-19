#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	string data;
	while(getline(cin,data)){
		vector<int> nums;
		for(int i = 0; i < data.size();i+=3){
			string toNumber = data[i];
			toNumber += data[i+1];
			int num = stoi(toNumber);
			nums.push_back(num);
		}
		for()
	}
}