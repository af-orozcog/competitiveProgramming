#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main(){
	string whole;
	cin >> whole;
	int last = - 1;
	for(int i = whole.size()-1; i >= 0; i--){
		if(whole[i] == 'a'){
			last = i;
			break;
		}
	}
	if(last == whole.size()-1){
		for(int i = 0; i < whole.size(); i++){
			if(whole[i] != 'a'){
				cout << ":(" << endl;
				return 0;
			}
		}
		cout << whole << endl;
		return 0;
	}
	if(last == -1){
		string toCheck = "";
		for(int i = 0; i < whole.size();i++){
			if(whole[i] != 'a')
				toCheck += whole[i];
		}
		if(toCheck.size()%2 != 0){
			cout << ":(" << endl;
			return 0;
		}
		for(int i = 0; i < toCheck.size()/2; i++){
			if(toCheck[i] != toCheck[(toCheck.size()/2)+i]){
				cout << ":(" << endl;
				return 0;
			}
		}
		string answer = "";
		int less = toCheck.size()/2;
		//cout << "toCheck " << toCheck << endl;
		for(int i = 0; i < (whole.size()-less);i++){
			answer += whole[i];
		}
		//cout << "entro aqui" << endl;
		cout << answer << endl;
		return 0;
	}
	else{
		//cout << last << endl;
		string toCheck1 = "";
		for(int i = 0; i < last; i++){
			if(whole[i] != 'a')
				toCheck1+= whole[i];
		}
		string toCheck2 = "";
		for(int i = last+1;i < whole.size(); i++){
			toCheck2 += whole[i];
		}
		string toge = toCheck1 + toCheck2;
		if(toCheck1.size() > toCheck2.size() || toge.size()%2 != 0){
			cout << ":(" << endl;
			//cout << "entro aqui"<< endl;
			return 0;
		}
		for(int i = 0; i < toge.size()/2; i++){
			if(toge[i] != toge[(toge.size()/2)+i]){
				cout << ":(" << endl;
				return 0;
			}
		}
		string answer = "";
		int less = toge.size()/2;
		for(int i = 0; i < (whole.size()-less);i++){
			answer += whole[i];
		}
		cout << answer << endl;
		return 0;
	}
}