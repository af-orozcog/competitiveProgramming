/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		string gems;
		cin>> gems;
		map<char,bool> letters;
		string toCheck;
		cin >> toCheck;
		for(int i = 0; i < gems.size();++i){
			letters[gems[i]] = true;
		}
		int total = 0;
		for(int i = 0; i < toCheck.size();++i){
			if(letters.count(toCheck[i]) > 0)
				++total;
		}
		cout << total << endl;
	}
	return 0;
}