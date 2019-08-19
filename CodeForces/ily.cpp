#include<iostream>
#include<string>
#define ll long long
using namespace std;

int main(){
	string val;
	cin >> val;
	if(val[0] != '-'){
		//cout << "aqui" << endl;
		cout << val << endl;
		return 0;
	}
	if(val.size() == 3){
		//cout << "auqi" << endl;
		//cout << val[2] << endl;
		if(val[2] == '0'){
			cout << val[2] << endl;
			return 0;
		}
		if((int)val[2] < (int)val[1]){
			string answer = "";
			answer += val[0];
			answer += val[2];
			cout << answer << endl;
			return 0;
		}
		string answer = "";
		answer += val[0];
		answer += val[1];
		cout << answer << endl;
		return 0;
	}
	string answer = "";
	bool a = true;
	if((int)val[val.size()-1] < (int)val[val.size()-2])
		a = false;
	for(ll i = 0; i< val.size()-1;i++){
		if(i == val.size()-2 && a){
			answer += val[i];
			cout << answer << endl;
			return 0;
		}
		else if(i == val.size()-2 && !a){
			answer += val[i+1];
			cout << answer << endl;
			return 0;
		}
		answer += val[i];
		//cout << answer << endl;
	}
	return 0;
}