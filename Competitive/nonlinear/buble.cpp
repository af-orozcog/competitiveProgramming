#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
	string str;
	map<string,string> dict;
	while(getline(cin,str) && str != ""){
		int i = 0;
		string first = "";
		for(; i < str.size(); i++){
			if(str[i] == ' '){
				i++;
				break;
			}
			first += str[i];
		}
		string second = "";
		for(; i < str.size();i++){
			second += str[i];
		}
		dict[second] = first;
	}

	while(cin >> str){
		if(dict.count(str) > 0){
			cout << dict[str] << endl;
		} 
		else
			cout << "eh" << endl;
	}
	return 0;
}