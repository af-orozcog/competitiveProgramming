/**
* I'm sorry I was an Idiot
*/
#include <iostream>
#include <stack>
#include<vector>
#include <string>
#define max(x,y)(x > y?x:y)

using namespace std;

int main(){
	while(true){
		vector<stack<string>> piles;
		for(int i = 0;i < 52;++i){
			string toRead;
			cin >> toRead;
			if(toRead[0] == '#')
				return 0;
			stack<string> toAdd;
			toAdd.push(toRead);
			piles.push_back(toAdd);
		}
		bool posi = true;
		while(posi){
			posi = false;
			for(int i = 0;i < piles.size();++i){
				int c1 = i -1;
				int c2 = i -3;
				if(c2 >= 0 &&piles[c2].top()[0] == piles[i].top()[0]){
					piles[c2].push(piles[i].top());
					piles[i].pop();
					if(piles[i].size() == 0){
						piles.erase(piles.begin() + i);
					}
					posi = true;
					break;
				}
				if(c2 >= 0 && piles[c2].top()[1] == piles[i].top()[1]){
					piles[c2].push(piles[i].top());
					piles[i].pop();
					if(piles[i].size() == 0){
						piles.erase(piles.begin() + i);
					}
					posi = true;
					break;
				}
				if(c1 < 0)
					continue;
				if(piles[c1].top()[0] == piles[i].top()[0]){
					piles[c1].push(piles[i].top());
					piles[i].pop();
					if(piles[i].size() == 0){
						piles.erase(piles.begin() + i);
					}
					posi = true;
					break;
				}	
				if(piles[c1].top()[1] == piles[i].top()[1]){
					piles[c1].push(piles[i].top());
					piles[i].pop();
					if(piles[i].size() == 0){
						piles.erase(piles.begin() + i);
					}
					posi = true;
					break;
				}
			}
		}	
		cout << piles.size() << " pile" << (piles.size() > 1?"s":"") <<" remaining:";
		for(int i = 0; i < piles.size();++i){
			cout << " " << piles[i].size();
		}
		cout << endl;
	}
	return 0;
}