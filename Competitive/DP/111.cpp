/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<map>
#include<string>
#include<vector>
#define max(x,y)(x > y ? x : y)

using namespace std;


int main(){
	string read;
	map<int,int> order;
	bool see = false;
	while(getline(cin,read)){
		if(see){
			order.clear();
			int counter = 1;
			string num = "";
			for(int i = 0; i < read.size();++i){
				if(read[i] == ' '){
					order[counter++] = stoi(num);
					num = "";
				}
				if(i == read.size() - 1){
					num += read[i];
					order[counter++] = stoi(num);
				}
				else
					num += read[i];
			}
			see = false;
			continue;
		}
		bool first = true;
		for(int i = 0; i < read.size();++i){
			if(read[i] == ' '){
				//cout << "entro?" << endl;
				first = false;
				break;
			}
		}
		if(first){
			see = true;
			continue;
		}
		vector<int> toCheck(order.size() + 1);
		string num = "";
		int counter = 1;
		for(int i = 0; i < read.size();++i){
			if(read[i] == ' '){
				toCheck[stoi(num)] = order[counter++];
				num = "";
			}
			if(i == read.size() - 1){
				num += read[i];
				toCheck[stoi(num)] = order[counter++];
			}
			else
				num += read[i];
		}
		/*for(int i = 1; i < toCheck.size();++i){
			cout << toCheck[i] <<" ";
		}*/
		//cout << endl;
		int memo[toCheck.size()];
		int valmax = 1;
		for(int i = 1; i < toCheck.size();++i){
			if(i == 1){
				memo[i] = 1;
			}
			if(i != 1){
				int ans = 1;
				for(int j = i - 1;j >= 1;--j){
					if(toCheck[j] <= toCheck[i])
						ans = max(ans,(memo[j] + 1));
				}
				memo[i] = ans;
				valmax = max(ans,valmax);
			}
		}
		cout << valmax << endl;
	}
	return 0;
}