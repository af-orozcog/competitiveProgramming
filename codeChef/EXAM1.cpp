/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<string>

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		int siz;
		cin >> siz;
		string correct,toCheck;
		cin >> correct >> toCheck;
		int score = 0;
		bool check = true;
		for(int i = 0; i < correct.size();++i){
			if(check){
				if(toCheck[i] != 'N'){
					if(toCheck[i] != correct[i])
						check = false;
					else
						++score;
				}
			}
			else if(!check)
				check = true;
		}
		cout << score << endl;
	}
	return 0;
}