#include<iostream>
#include<string>

using namespace std;

int main(){
	string lin;
	vector<string> words;
	while(1){
		getline(cin,lin);
		if(lin.size() == 0){
			puts("");
			continue;
		}
		if(lin[0] == '0')
			break;
		string last = "";
		for(int i = 0; i < lin.size();++i){
			if(lin[i] == ' ' || lin[i] == '\'' || lin[i] == ''){
				printf("")
			}
		}
	}
	return 0;
}