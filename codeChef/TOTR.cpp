/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<map>

using namespace std;

int main(){
	int cas;
	string com;
	cin >> cas >> com;
	map<char,char> trans;
	for(int i = 0; i < 26;++i){
		char n = i + 97;
		trans[n] = com[i];
		char m = com[i] - 32;
		char q = i + 65;
 		trans[q] = m;
	}
	//cout << trans['P'] << endl;
	//cout << trans['p'] << endl;
	while(cas--){
		string toTrans;
		cin >> toTrans;
		char answer[toTrans.size() + 1];
		int i = 0;
		for(; i < toTrans.size();++i){
			if(toTrans[i] == '_')
				answer[i] = ' ';
			else if(toTrans[i] == '.' ||
				toTrans[i] == ','
				|| toTrans[i] == '!'
				|| toTrans[i] == '?')
				answer[i] = toTrans[i];
			else
				answer[i] = trans[toTrans[i]];
		}
		answer[i] = '\0';
		printf("%s\n",answer);
	}
	return 0;
}