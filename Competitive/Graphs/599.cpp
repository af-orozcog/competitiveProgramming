/**
* Lo hago por Valentina, para ser mejor y para llegar a Moscú
*/
#include<iostream>
#include<bitset>
#include<string>


using namespace std;

int main(){
	int cas;
	cin >> cas;
	for(int i = 0; i < cas;++i){
		bitset<26> letters;
		int edges = 0;
		while(true){
			string val;
			cin >> val;
			if(val[0] == '*')
				break;
			++edges;
		//	cout << val << endl;
			letters[val[1] - 65] = 1;
			letters[val[3] - 65] = 1;
		}
		//cout << "edges :" << edges << endl;
		cin.ignore();
		string val;
		getline(cin,val);
		int many = val.size() - (val.size()/2);
		//cout << "many: " << many << endl;
		int corns = 0;
		for(int e = 0; e < val.size(); e+=2){
			if(!letters[val[e] - 65])
				++corns;
		}
		cout << "There are " << many - edges - corns << " tree(s) and " << corns << " acorn(s)." << endl;
	}
	return 0;
}