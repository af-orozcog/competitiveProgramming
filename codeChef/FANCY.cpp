/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<string>

using namespace std;

int main(){
	int cas;
	cin >> cas;
	string toCheck = "not";
	cin.ignore();
	while(cas--){
		string read;
		getline(cin,read);
		int now = 0;
		bool cool = false;
		//cout << read.size() << endl;
		for(int i = 0; i < read.size();++i){
			//cout << i << endl;
			if(now != 3 && read[i] == toCheck[now]){
				++now;
				if(now != 3)
					continue;
			}
			//cout << "now " << now << endl;
			if(now == 3 && i == read.size()-1){
				if(i - 3 < 0)
					cool = true;
				else if(read[i - 3] == ' ')
					cool = true;
				else 
					cool = false;
				break;
			}
			if(i != read.size() - 1 && now == 3 && read[i+1] == ' '){
				if(i - 3 < 0)
					cool = true;
				else if(read[i-3] == ' ')
					cool = true;
				else
					cool = false;
				break;
			}
			else
				now = 0;
		}
		if(cool)
			puts("Real Fancy");
		else
			puts("regularly fancy");
	}
	return 0;
}