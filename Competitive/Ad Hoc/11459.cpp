#include<iostream>
#include<vector>

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
			to[from] = to;
		}
		int turn = 1;
		bool moves = true;
		while(c--){
			if(!moves)
				continue;
			int mo;
			scanf(" %d",&mo);
			players[turn] += mo;
			if(mo >= 100){
				moves = false;
				players[turn] = 100;
			}
			if(to.count(players[turn]))
				players[turn] = to[players[turn]];
			turn++;
			if(turn > a)
				turn = 1; 
		}
		for(int i = 1;i <=a;++i)
			printf("Position of player %d is %d.\n",i,players[i]);
	}
	return 0;
}