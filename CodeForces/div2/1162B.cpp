#include<iostream>

using namespace std;

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	int ma1[n][m];
	int ma2[n][m];
	for(int i = 0; i < n;++i){
		for(int j = 0; j < m;++j){
			scanf(" %d",&ma1[i][j]);
		}
	}
	for(int i = 0; i < n;++i){
		for(int j = 0; j < m;++j){
			scanf(" %d",&ma2[i][j]);
		}
	}
	bool posi = true;
	for(int j = 0; j < m && posi;++j){
		for(int i = 0; i < n && posi;++i){
			if(j == 0 && i == 0)
				continue;
			bool need = false;
			if(j > 0){
			    //cout << ma1[i][j-1] << " " << ma1[i][j] << "\n";
				if(ma1[i][j-1] >= ma1[i][j])
					need = true;
				if(ma2[i][j-1] >= ma2[i][j])
					need = true;
			}
			if(i > 0){
				if(ma1[i-1][j] >= ma1[i][j])
					need = true;
				if(ma2[i-1][j] >= ma2[i][j])
					need = true;
			}
			if(need){
				int temp = ma1[i][j];
				ma1[i][j] = ma2[i][j];
				ma2[i][j] = temp;
			}
			if(j > 0){
				if(ma1[i][j-1] >= ma1[i][j])
					posi = false;
				if(ma2[i][j-1] >= ma2[i][j])
					posi = false;
			}
			if(i > 0){
				if(ma1[i-1][j] >= ma1[i][j])
					posi = false;
				if(ma2[i-1][j] >= ma2[i][j])
					posi = false;
			}
		}
	}
	cout << (posi? "Possible":"Impossible") << "\n";
	return 0;
}