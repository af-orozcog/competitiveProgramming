#include<iostram>
#include<map>
#include<vector>
#include<iostram>

using namespace std;

int main(){
	map<String,vector> infra;
	int cases;
	cin >> cases;
	for(int i = 0; i < cases; i++){
		string str;
		getline(cin,str);
		map<String,vector<pair<string,pair<int,int>>>> infra;
		map<int,int> costs;
		for(int j = 0; j < 24; j++){
			int val;
			cin >> val;
			costs[j] = val;
		}
		while(getline(cin,str) && str != ""){
			int j = 0;
			string plates = "";
			for(;j < str.size();j++){
				if(str[j] == ' '){
					j++;
					break;
				}
				plates += str[j];
			}
			string hour = "";
			for(; j < str.size();j++){
				if(str[j] == ' '){
					j++;
					break;
				}
				hour += str[j];
			}
			string what = str[j] + str[j+1] + str[j+2];
			int enter = 0;
			string beg;
			if(what.compare("ent") == 0){
				enter = 1;
				j += 6;
			}
			else{
				j += 5;
			}
			string beg = "";
			for(; j < str.size(); j++){
				beg += str[j];
			}
			int beg1 = stoi(beg);
			pair<string,pair<int,int>> toAdd;
			toAdd.first = hour;
			toAdd.second.first = enter;
			toAdd.second.second = beg1;
			if(infra.count(plates) > 0){
				infra[plates].push_back(toAdd);
			}
			else{
				vector<pair<string,pair<int,int>>> to;
				to.push_back(toAdd);
				infra[plates] = to;
			}
		}
		for(const auto &mypair: infra){
			
		}
	}
}