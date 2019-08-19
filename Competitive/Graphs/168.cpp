/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int main(){
	while(1){
		string graph;
		cin >> graph;
		if(graph[0] == '#')
			break;
		int num = 0;
		map<char,int> trans;
		map<int,char> transBack;
		bool head = true;
		int adding;
		vector<vector<int>> gra(100);
		for(int i = 0; i < graph.size();++i){
			if(head){
				char toAdd = graph[i];
				if(trans.count(toAdd) == 0){
					trans[toAdd] = num;
					transBack[num++] = toAdd;
				}
				adding = trans[toAdd];
				head = false;
			}
			else{
				char toAdd = graph[i];
				if(toAdd == ':')
					continue;
				if(toAdd == ';' || toAdd == '.'){
					head = true;
					continue;
				}
				//cout << toAdd << endl;
				if(trans.count(toAdd) == 0){
					trans[toAdd] = num;
					transBack[num++] = toAdd;
				}
				gra[adding].push_back(trans[toAdd]);
			}
		}
		string mino,thes;
		cin >> mino >> thes;
		int k;
		cin >> k;
		vector<char> ans;
		char lastAns;
		int counter = 0;
		int minn = trans[mino[0]];
		int thess = trans[thes[0]];
		map<int,bool> marked;
		while(1){
			++counter;
			bool posi = false;
			for(int i = 0; i < gra[minn].size();++i){
				//cout << "minn " <<minn << " " << gra[minn].size()<< endl;
				if(gra[minn][i] != thess && marked.count(gra[minn][i]) == 0){
					//cout << gra[minn][i] << endl;
					posi = true;
				//	cout << "counter es: "<< counter << " k es: "<< k << endl;
					if(counter == k){
						marked[minn] = true;
				//		cout << "wtf: "<<transBack[minn]<<endl;
						ans.push_back(transBack[minn]);
						counter = 0;
					}
					thess = minn;
					minn = gra[minn][i];
					break;
				}
			}
			//cout << "pasa aqui" << endl;
			if(!posi){
				lastAns = transBack[minn];
				break;
			}
		}
		for(int i = 0; i < ans.size();++i){
				cout << ans[i]<<" ";
		}
		cout << "/" << lastAns<<endl;
	}
	return 0;
}