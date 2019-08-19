/**
* Lo hago por Valentina, para ser mejor y para llegar a Moscú
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

typedef vector<int> vi;
vi numbers(10001,0);
vi ranks(10001,1);
map<int,vi> enemies;

void sett(int m){
	for(int i = 0; i < m; i++){
		numbers[i] = i;
		ranks[i] = 1;
	}
}

int search(int m){
	return (numbers[m] == m) ? m : (numbers[m] = search(numbers[m]));
}

bool connected(int x, int y){
	return search(x) == search(y);
}
void mergeEnemies(int x,int y);

void connect(int x, int y){
	if(!connected(x,y)){
		int x1 = search(x), y1 = search(y);
		if(ranks[x1] > ranks[y1]){
			numbers[y1] = x1;
			mergeEnemies(x1,y1);
		}
		else{
			numbers[x1] = y1;
			mergeEnemies(y1,x1);
			if(ranks[x1] == ranks[y1]) ranks[y1]++;
		}
	}
}
void mergeEnemies(int x, int y){
	if(enemies.count(x) > 0){
		if(enemies.count(y) > 0)
			connect(enemies[x][0],enemies[y][0]);
	}
	else{
		if(enemies.count(y) > 0)
			enemies[x].push_back(enemies[y][0]);
	}
}

bool areEnemies(int x,int y){
	if(enemies.count(search(x)) == 0)
		return false;
	if(enemies.count(search(y)) == 0)
		return false;
	if(connected(enemies[search(x)][0],search(y)))
		return true;
	return false;
}


int main(){
	int all;
	cin >> all;
	sett(all);
	while(true){
		int c,x,y;
		cin >> c >> x >> y;
		if(c == 0){
			break;
		}
		if(c == 1){
			if(areEnemies(search(x),y)){
				cout << -1 << endl;
				continue;
			}
			connect(x,y);
		}
		else if(c == 2){
			if(connected(x,y)){
				cout << -1 << endl;
				continue;
			}
			if(enemies.count(search(x)) > 0)
				connect(enemies[search(x)][0],y);
			else
				enemies[search(x)].push_back(search(y));
			if(enemies.count(search(y)) > 0)
				connect(enemies[search(y)][0],x);
			else
				enemies[search(y)].push_back(search(x));
		}
		else if(c == 3){
			if(connected(x,y))
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if(c == 4){
			if(connected(x,y))
				cout << 0 << endl;
			else if(areEnemies(search(x),y))
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
	return 0;
}