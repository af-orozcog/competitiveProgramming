/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<string>

using namespace std;

string set(string toSet){
	string ans = "";
	for(int i = 0; i < toSet.size();++i){
		if(toSet[i] != ' ' && toSet[i] != '!'
			&& toSet[i] != ',' && toSet[i] != '.'
			&& toSet[i] != '?')
			ans += tolower(toSet[i]);
	}
	return ans;
}

int main(){
	while(true){
		string read;
		getline(cin,read);
		if(read.compare("DONE") == 0)
			break;
		string val = set(read);
		//cout << val << endl;
		int i = 0,j = val.size()-1;
		bool posi = true;
		while(i < j){
			if(val[i] != val[j]){
				posi = false;
				break;
			}
			++i;
			--j;
		}
		if(!posi)
			cout << "Uh oh..\n";
		else
			cout << "You won't be eaten!\n";
	}
	return 0;
}