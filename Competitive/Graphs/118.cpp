/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

int main(){
	pair<int,int> North = make_pair(0,1);
	pair<int,int> South = make_pair(0,-1);
	pair<int,int> West = make_pair(-1,0);
	pair<int,int> East = make_pair(1,0);
	vector<pair<int,int>> directions = {North,East,South,West};
	int x,y;
	cin >> x >> y;
	int matrix[x+1][y+1];
	memset(matrix,0,sizeof(matrix));
	string pos;
	int posx,posy;
	while(cin >> posx >> posy >> pos){
		string moves;
		cin >> moves;
		int place;
		if(pos[0] == 'E')
			place = 1;
		else if(pos[0] == 'N')
			place = 0;
		else if(pos[0] == 'W')
			place = 3;
		else
			place = 2;
		bool lost = false;
		for(int i = 0; i < moves.size();++i){
			if(moves[i] == 'F'){
				int neX = posx + directions[place].first;
				int neY = posy + directions[place].second;
				//cout <<
				if(neX < 0 || neX > x || neY < 0 || neY > y){
					if(matrix[posx][posy] == 1)
						continue;
					else{
						matrix[posx][posy] = 1;
						lost = true;
						break;
					}
				}
				posx = neX;
				posy = neY;
			}
			else{
				if(moves[i] == 'R')
					place = (place+1) % 4;
				else
					place = place-1;
				if(place < 0)
					place = 3;
			}
			//cout << "posx " << posx << " posy " << posy << endl;
		}
		if(place == 1)
			pos[0] = 'E';
		else if(place == 0)
			pos[0] = 'N';
		else if(place == 2)
			pos[0] = 'S';
		else
			pos[0] = 'W';
		cout << posx << " " << posy << " " << pos << (lost? " LOST":"") <<endl;
	}
	return 0;
}