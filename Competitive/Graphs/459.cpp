/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;
int UF[100000];
int rankk[100000];

void sett(int siz){
	for(int i = 0; i < siz;++i){
		UF[i] = i;
		rankk[i] = 1;
	}
}
int find(int x){
	return UF[x] == x? x : (UF[x] = find(UF[x]));	
}
bool connected(int x,int y){
	return find(x) == find(y);
}
void connect(int x, int y){
	int dadX = find(x),dadY = find(y);
	if(dadX != dadY){
		if(rankk[dadX] > rankk[dadY]){
			UF[dadY] = dadX;
		}
		else{
			UF[dadX] = dadY;
			if(rankk[dadX] == rankk[dadY]) ++rankk[dadY];
		}
	}
}

int main(){
	int cas;
	cin >> cas;
	cin.ignore();
	string lil;
	//cout << "lil es " <<lil<<endl;
	getline(cin,lil);
	bool first = true;
	while(cas--){
		if(!first)
			cout << endl;
		map<char,int> trans;
		int num = 0;
		string line;
		getline(cin,line);
		trans[line[0]] = num++;
		int upTo = line[0]-'A' + 1;
		sett(upTo);
		//cout << "upTo " << upTo << " la letra es: " << line[0]<<endl;
		while(getline(cin,line)){
			if(line.size() == 0)
				break;
			if(trans.count(line[0]) == 0)
				trans[line[0]] = num++;
			if(trans.count(line[1]) == 0)
				trans[line[1]] = num++;
			connect(trans[line[0]],trans[line[1]]);
		}
		for(int i = 0; i < num;++i){
			find(i);
		}
		map<int,bool> dif;
		for(int i = 0; i < upTo;++i){
			dif[UF[i]] = true;
		}
		cout << dif.size() << endl;
		first = false;
	}
	return 0;
}