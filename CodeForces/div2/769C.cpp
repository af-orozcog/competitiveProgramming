#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

char map[1005][1005];
int dist[1005][1005];

int n,m,k;
int impX,impY;
vector<char> moves;

char info[] = {'D','L','R','U'};
int movX[] = {1,0,0,-1};
int movY[] = {0,-1,1,0};

bool solve(int pox, int poy, int pok){
	if(pok == 0){
		if(pox == impX && poy == impY)
			return true;
		return false;
	}
	if(dist[pox][poy] > pok){
		return false;
	}
	for(int i = 0; i < 4;++i){
		int nex = pox + movX[i],ney = poy + movY[i];
		if(nex >= n || nex < 0 || ney >= m || ney < 0 || map[nex][ney] == '*'){
			continue;
		}
		moves.push_back(info[i]);
		if(solve(nex,ney,pok-1))
			return true;
		moves.pop_back();
	}
	return false;
}

void disst(int pox, int poy){
	dist[pox][poy] = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(pox,poy));
	while(q.size()){
		int a,b;
		a = q.front().first;b = q.front().second;
		q.pop();
		for(int i = 0; i < 4;++i){
			if((a+movX[i] < n) && (a+movX[i] >= 0) && (b+movY[i] < m) && (b+movY[i] >= 0) && dist[a+movX[i]][b+movY[i]] == -1)
				if(map[a+movX[i]][b+movY[i]] == '.'){
					dist[a+movX[i]][b+movY[i]] = dist[a][b] + 1;
					q.push(make_pair(a+movX[i],b+movY[i]));
				}
		}
	}
}

int main(){
	scanf(" %d %d %d",&n,&m,&k);
	memset(dist,-1,sizeof(dist));
	for(int i = 0; i < n;++i){
		for(int j = 0; j < m;++j){
			char re;
			scanf(" %c",&re);
			map[i][j] = re;
			if(re == 'X'){
				impX = i;
				impY = j;
			}
		}
	}
	//cout << impX << " " << impY << endl;
	if(k & 1){
		puts("IMPOSSIBLE");
		return 0;
	}
	disst(impX,impY);
	if(solve(impX,impY,k)){
		for(int i= 0; i < moves.size();++i){
			printf("%c",moves[i]);
		}
		puts("");
		return 0;
	}
	puts("IMPOSSIBLE");
	return 0;
}