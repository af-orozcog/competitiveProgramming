/**
* I'm sorry I was an idiot
*/
#include<iostream>
#include<queue>
#define ll long long

using namespace std;

int main(){
	ll pl,row;
	cin >> pl >> row;
	queue< pair< int,ll > > players;
	ll maxPo = 0;
	for(int i = 0; i < pl;++i){
		ll po;
		cin >> po;
		if(po > maxPo)
			maxPo = po;
		players.push(make_pair(i,po));
	}
	pair<int,ll> ply1 = players.front();
	players.pop();
	pair<int,ll> ply2 = players.front();
	players.pop();
	pair<int,ll> plyW;
	if(ply1.second > ply2.second){
		plyW = ply1;
		players.push(ply2);
	}
	else{
		plyW = ply2;
		players.push(ply1);
	}
	ll wins = 1;
	while(wins != row){
		pair<int,ll> plyO = players.front();
		players.pop();
		if(plyW.second == maxPo)
			break;
		else if(plyO.second < plyW.second){
			++wins;
			players.push(plyO);
		}
		else{
			wins = 1;
			players.push(plyW);
			plyW = plyO;
		}
	}
	cout << plyW.second << endl;
	return 0;
}