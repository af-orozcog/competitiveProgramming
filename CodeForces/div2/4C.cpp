/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main(){
	unordered_map<string,int> ma;
	int cas;
	cin >> cas;
	while(cas--){
		string toRead;
		cin >> toRead;
		if(ma.count(toRead) == 0){
			cout << "OK" << endl;
			ma[toRead] = 1;
		}
		else{
			int look = ma.at(toRead);
			cout << toRead << ma.at(toRead) << endl;
			ma[toRead] = look + 1;
		}
	}
	return 0;
}