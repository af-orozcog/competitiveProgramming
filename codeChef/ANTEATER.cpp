/**
*I'm sorry I was an Idiot
*/
#include<iostream>
#include<cstring>
#include<map>
#include<vector>

using namespace std;

int simulation(map<int,pair<pair<int,int>,int>> ants, int **matrix,int x, int y){
	int total = 0;
	while(ants.size() != 0){
		vector<int> toDelete;
		for(auto const &pa: ants){
			int coorx = pa.second.first.first;
			int coory = pa.second.first.second;
			int direction = pa.second.second;
			//cout << coorx << " " << coory << " direction " << direction << endl;
			matrix[coorx][coory] = 0;
			if(direction == 1){
				if(coorx > 0){
					ants[pa.first] = make_pair(make_pair(coorx-1,coory),direction);
					if(matrix[coorx-1][coory] < 0)
						toDelete.push_back(pa.first);
					else{
						if(matrix[coorx-1][coory] == 1)
							total += 1;
						else if(matrix[coorx-1][coory] > 1)
							total += matrix[coorx-1][coory];
						matrix[coorx-1][coory] += 1;
					}			
				}
				else
					toDelete.push_back(pa.first);	
			}
			else if(direction == 2){
				if(coorx < x - 1){
					ants[pa.first] = make_pair(make_pair(coorx+1,coory),direction);
					if(matrix[coorx+1][coory] < 0)
						toDelete.push_back(pa.first);
					else{
						if(matrix[coorx+1][coory] == 1)
							total += 1;
						else if(matrix[coorx+1][coory] > 1)
							total += matrix[coorx+1][coory];
						matrix[coorx+1][coory] += 1;
					}
				}
				else
					toDelete.push_back(pa.first);
			}
			else if(direction == 3){
				if(coory < y - 1){
					ants[pa.first] = make_pair(make_pair(coorx,coory+1),direction);
					if(matrix[coorx][coory+1] < 0)
						toDelete.push_back(pa.first);	
					else{
						if(matrix[coorx][coory+1] == 1)
							total += 1;
						else if(matrix[coorx][coory+1] > 1)
							total += matrix[coorx][coory+1];
						matrix[coorx][coory+1] += 1;
					}
				}
				else
					toDelete.push_back(pa.first);
			}
			else{
				if(coory > 0){
					ants[pa.first] = make_pair(make_pair(coorx,coory-1),direction);
					if(matrix[coorx][coory-1] < 0)
						toDelete.push_back(pa.first);
					else{
						if(matrix[coorx][coory-1] == 1)
							total += 1;
						else if(matrix[coorx][coory-1] > 1)
							total += matrix[coorx][coory-1];
						matrix[coorx][coory-1] += 1;
					}
				}
				else
					toDelete.push_back(pa.first);
			}
			//cout << "total " << total << endl;
		}
		for(int i = 0; i < toDelete.size();++i){
			map<int,pair<pair<int,int>,int>>::iterator it;
			it = ants.find(toDelete[i]);
			ants.erase(it);
		}
	}
	return total;
}

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		int x,y;
		cin >> x >> y;
		int matrixQuanti[x][y];
		memset(matrixQuanti,0,sizeof(matrixQuanti));
		char part[y+1];
		map<int,pair<pair<int,int>,int>> ants;
		int counter = 0;
		for(int i = 0; i < x;++i){
			scanf(" %s",part);
			for(int j = 0; j < y;++j){
				if(part[j] == 'R'){
					matrixQuanti[i][j] = 1;
					ants[counter++] = make_pair(make_pair(i,j),3);
				}
				if(part[j] == 'U'){
					matrixQuanti[i][j] = 1;
					ants[counter++] = make_pair(make_pair(i,j),1);
				}
				if(part[j] == 'D'){
					matrixQuanti[i][j] = 1;
					ants[counter++] = make_pair(make_pair(i,j),2);
				}
				if(part[j] == 'L'){
					matrixQuanti[i][j] = 1;
					ants[counter++] = make_pair(make_pair(i,j),4);
				}
				if(part[j] == '#'){
					matrixQuanti[i][j] = -100000;
				}
			}
		}
		int *b[x];  // surrogate
    	for (size_t i = 0; i < x; ++i)
    	{
    	    b[i] = matrixQuanti[i];
    	}
		cout << simulation(ants,b,x,y) << endl;;
	}
}