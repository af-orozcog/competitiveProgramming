/**
* I'm an Idiot
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>

using namespace std;

int N;

int UF[100];
int rankk[100];
void sett(){
	for(int i = 0; i < N;++i){
		UF[i] = i;
		rankk[i] = 1;
	}	
}
int search(int x){
	//cout << UF[x] <<" " <<x <<endl;
	return UF[x] == x ? x :(UF[x] = search(UF[x]));
}

void connect(int x, int y){
	int dadX = search(x),dadY = search(y);
	if(dadX != dadY){
		if(rankk[dadX] > rankk[dadY]){
			UF[dadY] = dadX;
		}
		else{
			UF[dadX] = dadY;
			if(rankk[dadY] == rankk[dadX]) ++rankk[dadY];
		}
	}
}

int main(){
	cin >> N;
	sett();
	vector<pair<int,int>> cor(N);
	for(int i = 0; i < N;++i){
		int val1,val2;
		cin >> val1>>val2;
		cor[i] = make_pair(val1,val2);
	}
	for(int i = 0; i < N;++i){
		for(int j = i+1;j < N;++j){
			if(cor[i].first == cor[j].first || 
				cor[i].second == cor[j].second){
				connect(i,j);
			}
		}
	}
	//cout << "lel" << endl;
	map<int,bool> ans;
	for(int i = 0; i < N;++i){
		int n = search(i);
	//	cout << n << endl;
		ans[n] = true;
	}
	cout << ans.size() -1 << endl;
}