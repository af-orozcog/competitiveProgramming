/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<string>
#include<cstring>
#include<climits>
#include<vector>
#define min(x,y)(x < y?x:y)
#define max(x,y)(x > y? x:y)
using namespace std;


int main(){
	int que;
	cin >> que;
	while(que--){
		int x,y;
		cin >> x >> y;
		bool map[x][y];
		//bool copy[x][y];
		bool posi = false;
		for(int i = 0; i < x;++i){
			string toRead;
			cin >> toRead;
			for(int j = 0; j < y;++j){
				if(toRead[j] == '.'){
					map[i][j] = false;
		//			copy[i][j] = false;
				}
				else{
					map[i][j] = true;
		//			copy[i][j] = true;
					posi = true;
				}
			}
		}
		if(!posi){
			cout << x+y-1<< endl;
			continue;
		}
		int colM = 0;
		vector<int> col;
		int rowM = 0;
		vector<int> row;
		for(int i = 0; i < x;++i){
			int coun = 0;
			for(int j = 0;j < y;++j){
				if(map[i][j])
					++coun;
			}
			if(coun > rowM){
				rowM = coun;
				row.clear();
				row.push_back(i);
			}
			else if(coun == rowM){
				row.push_back(i);
			}
		}
		for(int j = 0; j < y;++j){
			int coun = 0;
			for(int i = 0; i < x;++i){
				if(map[i][j])
					++coun;
			}
			if(coun > colM){
				colM = coun;
				col.clear();
				col.push_back(j);
			}
			else if(coun == colM){
				col.push_back(j);
			}
		}
		//cout << " col " << colM << " row " << rowM << endl;
		if(colM == 0 && rowM == 0){
			cout << x+y-1 << endl;
			continue;
		}
		int ans = y - rowM;
		//cout << ans << endl;
		bool co[x][y];
		memcpy(co,map,sizeof(map));
		int less = INT_MAX;
		for(int i = 0; i < row.size();++i){
			for(int j = 0; j < y;++j){
				if(!map[row[i]][j]){
					map[row[i]][j] = true;
				}
			}
			for(int j = 0; j < col.size();++j){
				int plus = 0;
				//cout << "entro?" << endl;
				for(int i = 0; i < x;++i){
					if(!map[i][col[j]]){
						++plus;
					}
				}
				//cout << " plus " << plus << endl;
			less = min(plus,less);
			if(less == 0)
				break;
			}
			if(less == 0)
				break;
			memcpy(map,co,sizeof(co));
		}
		cout << ans + less << endl;
	}
	return 0;
}