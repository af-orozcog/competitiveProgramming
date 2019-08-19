/**
* Lo hago por Valentina, para ser mejor y para llegar a Moscú
*/
#include<iostream>

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		int x,y;
		cin >> x >> y;
		int matrix[x][y];
		for(int i = 0; i < x; ++i){
			for(int j = 0; j < y;++j){
				cin >> matrix[i][j];
			}
		}
		int x1,y1;
		int vals[10][10] = {};
		bool posi = true;
		for(int i = 0; i < y; i++){
			int many = 0;
			for(int j = 0; j < x; j++){
				if(matrix[j][i]){
					if(many == 0)
						x1 = j;
					else
						y1 = j;
					many++;
				}
			}
			if(many != 2){
				cout << "No" << endl;
				posi = !posi;
				break;
			}
			if(vals[x1][y1] && posi){
				cout << "No" << endl;
				posi = !posi;
				break;
			}
			vals[x1][y1] = vals[y1][x1] = 1;
		}
		if(posi)
			cout << "Yes" << endl;
	}
}
