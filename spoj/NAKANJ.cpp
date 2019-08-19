#include<iostream>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

int movesX[] = {-1,1,-2,2,-2,2,-1,1};
int movesY[] = {-2,-2,-1,-1,1,1,2,2};

int bfs(int x1, int y1, int x2, int y2){
	int dist[8][8];
	memset(dist,-1,sizeof(dist));
	queue<pair<int,int>> q;
	q.push(make_pair(x1,y1));
	dist[x1][y1] = 0;
	while(q.size() && dist[x2][y2] == -1){
		int x = q.front().first,y = q.front().second;
		q.pop();
		for(int i = 0; i < 8;++i){
			int xn = x + movesX[i];
			int yn = y + movesY[i];
			if(xn >= 0 && xn < 8 && yn >= 0 && yn < 8){
				if(dist[xn][yn] != -1)
					continue;
				dist[xn][yn] = dist[x][y] + 1;
				q.push(make_pair(xn,yn));
			}
		}
	}
	return dist[x2][y2];
}

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		string a,b;
		cin >> a >> b;
		int x1 = a[0]-'a';
		int y1 = a[1] - '0';
		int x2 = b[0] - 'a';
		int y2 = b[1] -'0';
		printf("%d\n",bfs(x1-1,y1-1,x2-1,y2-1));
	}
	return 0;
}