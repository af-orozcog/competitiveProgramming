/**
* I'm sorry I was an Idiot
*/
#include<string>
#include<iostream>

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		string normal,toCompare;
		cin >> normal >> toCompare;
		int j = 1;
		bool posi = true;
		if(normal[0] != toCompare[0] || normal.size() > toCompare.size()){
			cout << "NO"<< endl;
			continue;
		}
		char last = normal[0];
		for(int i = 1;i < normal.size();++i){
			while(toCompare[j] == last && toCompare[j] != normal[i]){
				++j;
				if(j == toCompare.size())
					break;
			}
			if(j == toCompare.size() || toCompare[j] != normal[i]){
				//cout << "here " << j  << endl;
				//cout << toCompare[j] << " " << normal[i] << endl;
				posi = false;
				break;
			}
			last = normal[i];
			++j;
		}
		if(j != toCompare.size() && posi){
			while(j < toCompare.size()){
				if(toCompare[j] != last){
					posi = false;
					break;
				}
				++j;
			}
		}
		if(!posi)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}