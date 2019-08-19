/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<string>

using namespace std;

int main(){
	int siz;
	cin >> siz;
	string toCheck;
	cin >> toCheck;
	int lastpos = 0;
	int ones = 0;
	int zero = 0;
	for(int i = 0; i < toCheck.size();++i){
		if(toCheck[i] == '0')
			++zero;
		else if(toCheck[i] == '1')
			++ones;
		if(zero != ones)
			lastpos = i;
	}
	if(lastpos == toCheck.size()-1)
		cout << 1 << endl;
	else
		cout << 2 << endl;
	for(int i = 0; i <= lastpos;++i){
		cout << toCheck[i];
	}
	bool first = 1;
	for(int i = lastpos +1; i < toCheck.size();++i){
		if(first){
			cout << " ";
		}
		cout << toCheck[i];
	}
	cout << endl;
}