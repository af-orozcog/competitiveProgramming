#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int a,b,c;
		scanf(" %d %d %d",&a,&b,&c);
		map<int,int> to;
		vector<int> players(a+1,1);
		for(int i = 0; i < b;++i){
			int from,too;
			scanf(" %d %d",&from,&too);
			to[from] = too;
		}
		int turn = 1;
		bool moves = true;
		while(c--){
			//cout << c << endl;
			int mo;
			scanf(" %d",&mo);
			if(!moves)
				continue;
			players[turn] += mo;
			if(to.count(players[turn]))
				players[turn] = to[players[turn]];
			if(players[turn] >= 100){
				moves = false;
				players[turn] = 100;
			}
			turn++;
			if(turn > a)
				turn = 1; 
		}
		for(int i = 1;i <=a;++i)
			printf("Position of player %d is %d.\n",i,players[i]);
	}
	return 0;
}