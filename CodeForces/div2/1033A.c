#include<stdio.h>
#include<tgmath.h>
#include<string.h>

int moveX[] = {1,-1,0,0,1,1,-1,-1};
int moveY[] = {0,0,-1,1,1,-1,1,-1};

int n;
int tarX,tarY;
int posX,posY;
int matrix[1000][1000];

int move(int x,int y){
	if(x == tarX && y == tarY)
		return 1;
	if(x >= n || y >= n || x < 0 || y < 0)
		return 0;
	if(matrix[x][y] == 1)
		return 0;
	if(x == posX || y == posY)
		return 0;
	if(fabs(x-posX) == fabs(y-posY))
		return 0;
	matrix[x][y] = 1;
	int ans = 0;
	for(int i = 0; i < 8 && ans == 0;++i){
		ans = move(x+moveX[i],y+moveY[i]);
	}
	return ans;
}

int main(){
	memset(matrix,0,sizeof(matrix));
	scanf(" %d",&n);
	scanf(" %d %d",&posX,&posY);
	--posX;--posY;
	int sX,sY;
	scanf(" %d %d",&sX,&sY);
	--sX;--sY;
	scanf(" %d %d",&tarX,&tarY);
	--tarX;--tarY;
	if(move(sX,sY))
		puts("YES");
	else
		puts("NO");
	return 0;	
}