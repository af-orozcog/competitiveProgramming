/**
* I'm sorry I was an idiot
*/
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){
	string toCheck;
	cin >> toCheck;
	char last = 'a';
	int steps = 0;
	for(int i = 0; i < toCheck.size();++i){
		if(toCheck[i] - last <= 0){
			if(toCheck[i] - last + 26  < (last -toCheck[i]))
				steps += toCheck[i] - last + 26;
			else
				steps += last -toCheck[i];
		}
		else{
			if(last - toCheck[i] + 26 < (toCheck[i]- last))
				steps += last - toCheck[i] + 26;
			else
				steps += toCheck[i]- last;
		}
		last = toCheck[i];
	}
	cout << steps << endl;
	return 0;
}