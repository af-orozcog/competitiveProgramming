#include<iostream>
#include<cstring>

using namespace std;

int N;
int total = 0;
bool pos[2][6*3][((60*61)/2)*3][3][60];
bool pos2[2][6*3][((60*61)/2)*3];

bool upperL(int x,int y,int oldx,int oldy, bool matrix){
	if(x - 1 >= 0 && y + 1 < N){
		int neX = oldx + x + (x-1);
		int neY = oldy + y + (y+1);
		if(matrix){
			pos[0][neX][neY][x][y] = true;
			pos[0][neX][neY][x-1][y] = true;
			pos[0][neX][neY][x][y+1] = true;
			return true;
		}
		if(pos[0][oldx][oldy][x][y])
			return false;
		if(pos[0][oldx][oldy][x-1][y])
			return false;
		if(pos[0][oldx][oldy][x][y+1])
			return false;
		memcpy(pos[1][neX][neY],pos[0][oldx][oldy],sizeof(pos[0][oldx][oldy]));
		pos[1][neX][neY][x][y] = true;
		pos[1][neX][neY][x-1][y] = true;
		pos[1][neX][neY][x][y+1] = true;
		return true;
	}
	return false;
}
bool upperR(int x,int y,int oldx,int oldy, bool matrix){
	if(x + 1 < 3 && y + 1 < N){
		int neX = oldx + x + (x+1);
		int neY = oldy + y + (y+1);
		if(matrix){
			pos[0][neX][neY][x][y] = true;
			pos[0][neX][neY][x+1][y] = true;
			pos[0][neX][neY][x][y+1] = true;
			return true;
		}
		if(pos[0][oldx][oldy][x][y])
			return false;
		if(pos[0][oldx][oldy][x+1][y])
			return false;
		if(pos[0][oldx][oldy][x][y+1])
			return false;
		memcpy(pos[1][neX][neY],pos[0][oldx][oldy],sizeof(pos[0][oldx][oldy]));
		pos[1][neX][neY][x][y] = true;
		pos[1][neX][neY][x+1][y] = true;
		pos[1][neX][neY][x][y+1] = true;
		return true;
	}
	return false;
}
bool lowerL(int x,int y,int oldx,int oldy, bool matrix){
	if(x - 1 >= 0 && y - 1 >= 0){
		int neX = oldx + x + (x-1);
		int neY = oldy + y + (y-1);
		if(matrix){
			pos[0][neX][neY][x][y] = true;
			pos[0][neX][neY][x-1][y] = true;
			pos[0][neX][neY][x][y-1] = true;
			return true;
		}
		if(pos[0][oldx][oldy][x][y])
			return false;
		if(pos[0][oldx][oldy][x-1][y])
			return false;
		if(pos[0][oldx][oldy][x][y-1])
			return false;
		memcpy(pos[1][neX][neY],pos[0][oldx][oldy],sizeof(pos[0][oldx][oldy]));
		pos[1][neX][neY][x][y] = true;
		pos[1][neX][neY][x-1][y] = true;
		pos[1][neX][neY][x][y-1] = true;
		return true;
	}
	return false;
}
bool lowerR(int x,int y,int oldx,int oldy, bool matrix){
	if(x + 1 < 3 && y - 1 >= 0){
		int neX = oldx + x + (x+1);
		int neY = oldy + y + (y-1);
		if(matrix){
			pos[0][neX][neY][x][y] = true;
			pos[0][neX][neY][x+1][y] = true;
			pos[0][neX][neY][x][y-1] = true;
			return true;
		}
		if(pos[0][oldx][oldy][x][y])
			return false;
		if(pos[0][oldx][oldy][x+1][y])
			return false;
		if(pos[0][oldx][oldy][x][y-1])
			return false;
		memcpy(pos[1][neX][neY],pos[0][oldx][oldy],sizeof(pos[0][oldx][oldy]));
		pos[1][neX][neY][x][y] = true;
		pos[1][neX][neY][x+1][y] = true;
		pos[1][neX][neY][x][y-1] = true;
		return true;
	}
	return false;
}
int valY(int value){return (value/N)/3;}
int valX(int value){return (value/N)%3;}

void printTable(int x,int y){
	for(int i = 0; i < 3;++i){
		for(int j = 0; j < N;++j){
			if(pos[0][x][y][i][j])
				cout << "x ";
			else
				cout << "o ";
		}
		cout << endl;
	}
	cout << "-------------------------" << endl;
}

void solve(){
	int val = N*3*4;
	for(int i = 0; i < val;i+=4){
		int x = valX(i);
		int y = valY(i);
		if(upperR(x,y,0,0,true)){
			int neX = 0 + x + (x+1);
			int neY = 0 + y + (y+1);
			pos2[0][neX][neY] = true;
			cout << neX <<" " <<neY << endl;
			printTable(neX,neY);
		}
		if(upperL(x,y,0,0,true)){
			int neX = 0 + x + (x-1);
			int neY = 0 + y + (y+1);
			pos2[0][neX][neY] = true;
			cout << neX <<" " <<neY << endl;
			printTable(neX,neY);
		}
		if(lowerR(x,y,0,0,true)){
			int neX = 0 + x + (x+1);
			int neY = 0 + y + (y-1);
			pos2[0][neX][neY] = true;
			cout << neX <<" " <<neY << endl;
			printTable(neX,neY);
		}
		if(lowerL(x,y,0,0,true)){
			int neX = 0 + x + (x-1);
			int neY = 0 + y + (y-1);
			pos2[0][neX][neY] = true;
			cout << neX <<" " <<neY << endl;
			printTable(neX,neY);
		}
	}
	return;
	int com = ((N*(N+1))/2)*3;
	int step = 1;
	while(step < N){
		for(int i = 0; i < 6*3;++i){
			for(int j = 0;j < com;++j){
				if(pos2[0][i][j]){
					for(int m = 0; m < val;m+=4){
						int x = valX(m);
						int y = valY(m);
				//		cout << x << " " << y << endl;
						if(upperR(x,y,i,j,false)){
							int neX = i + x + (x+1);
							int neY = j + y + (y+1);
							pos2[1][neX][neY] = true;
							cout << "step: "<<step <<" " <<neX << neY << " UPR" <<endl;
						}
						if(upperL(x,y,i,j,false)){
							int neX = i + x + (x-1);
							int neY = j + y + (y+1);
							pos2[1][neX][neY] = true;
							cout << "step: "<<step <<" " <<neX << neY << " UPL" <<endl;
						}
						if(lowerR(x,y,i,j,false)){
							int neX = i + x + (x+1);
							int neY = j + y + (y-1);
							pos2[1][neX][neY] = true;
							cout << "step: "<<step <<" " <<neX << neY << " LR" <<endl;
						}
						if(lowerL(x,y,i,j,false)){
							int neX = i + x + (x-1);
							int neY = j + y + (y-1);
							pos2[1][neX][neY] = true;
							cout << "step: "<<step <<" " <<neX << neY <<" LL" <<endl;
						}
					}
				}	
			}
		}
		memcpy(pos2[0],pos2[1],sizeof(pos2[1]));
		memset(pos2[1],false,sizeof(pos2[1]));
		memcpy(pos[0],pos[1],sizeof(pos[1]));
		memset(pos[1],false,sizeof(pos[1]));
		++step;
	}
}

int main(){
	cin >> N;
	memset(pos,false,sizeof(pos));
	memset(pos2,false,sizeof(pos2));
	solve();
	cout << total << endl;
	int com = ((N*(N+1))/2)*3;
	int count = 0;
	for(int i = 0; i < 6*3;++i){
		for(int j = 0; j < com;++j){
			if(pos2[0][i][j])
				++count;
		}
	}
	cout << "count es: " << count<<endl;
	return 0;
}