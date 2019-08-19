#include<iostream>
#include<vector>
#include<string>

using namespace std;

void printArr(vector<vector<int>> data){
	cout << "--------------------------------"<< endl;
	for(int i = 0; i< data.size();i++){
		cout << i << ":";
		for(int j = 0; j < data[i].size(); j++){
			cout << " " << data[i][j];
		}
		cout << endl;
	}
}

bool valid(vector<vector<int>> data,int a, int b){
	for(int i = 0; i < data.size();i++){
		int m = 0;
		int n = 0;
		for(int j = 0; j < data[i].size(); j++){
			//cout << "lel " << data[i][j] << endl;
			if(data[i][j] == a){
				m++;
			//	cout << a << endl;
			}
			if(data[i][j] == b){
				n++;
			//	cout << b << endl;
			}
		}
		if(m==1 && n==1){
			//cout << "NUNCA ENTRA AQUI" << endl;
			return false;
		}
	}
	return true;
}

void moveOnto(vector<vector<int>> &data,int a, int b){
	int x2,y2;
	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size();j++){
			if(data[i][j] == b){
				x2 = i;
				y2 = j;
			}
		}
	}

	for(int i = y2+1; i < data[x2].size();i++){
		vector<int> toAdd;
		toAdd.push_back(data[x2][i]);
		data[(data[x2][i])] = toAdd;
		data[x2].erase(data[x2].begin()+i);
		i--;
	}
	int x,y;
	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size();j++){
			if(data[i][j] == a){
				x = i;
				y = j;
			}
		}
	}
	data[x].erase(data[x].begin()+y);
	for(int i = y; i < data[x].size(); i++){
		vector<int> toAdd;
		toAdd.push_back(data[x][i]);
		data[(data[x][i])] = toAdd;
		data[x].erase(data[x].begin()+i);
		i--;
	}
	data[x2].push_back(a);
	//cout << "1" << endl;
	//printArr(data);
}
void moveOver(vector<vector<int>> &data,int a, int b){
	int x1;
	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size();j++){
			if(data[i][j] == b){
				x1 = i;
			}
		}
	}
	int x2,y2;
	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size();j++){
			if(data[i][j] == a){
				x2 = i;
				y2 = j;
			}
		}
	}
	data[x2].erase(data[x2].begin()+y2);
	for(int i = y2; i < data[x2].size(); i++){
		vector<int> toAdd;
		toAdd.push_back(data[x2][i]);
		data[(data[x2][i])] = toAdd;
		data[x2].erase(data[x2].begin()+i);
		i--;
	}
	data[x1].push_back(a);
	//cout << "3" << endl;
	//printArr(data);
}

void pileOnto(vector<vector<int>> &data,int a, int b){
	int x2,y2;
	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size();j++){
			if(data[i][j] == b){
				x2 = i;
				y2 = j;
			}
		}
	}
	//cout << "entro aqui" << endl; 
	for(int i = y2+1; i < data[x2].size();i++){
		vector<int> toAdd;
		toAdd.push_back(data[x2][i]);
		data[(data[x2][i])] = toAdd;
		data[x2].erase(data[x2].begin()+i);
		i--;
	}
	int x,y;
	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size();j++){
			if(data[i][j] == a){
				x = i;
				y = j;
			}
		}
	}
	int upTo = data[x].size();
	for(int i = y; i < upTo;i++){
		data[x2].push_back(data[x][i]);
	}
	data[x].erase(data[x].begin()+y);
	for(int i = y; i < data[x].size(); i++){
		data[x].erase(data[x].begin()+i);
		i--;
	}
	//cout << "2" << endl;
	//printArr(data);
}

void pileOver(vector<vector<int>> &data,int a, int b){
	int x1;
	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size();j++){
			if(data[i][j] == b){
				x1 = i;
			}
		}
	}
	int x2,y2;
	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size();j++){
			if(data[i][j] == a){
				x2 = i;
				y2 = j;
			}
		}
	}
	int upTo = data[x2].size();
	for(int i = y2; i < upTo;i++){
		data[x1].push_back(data[x2][i]);
	}
	data[x2].erase(data[x2].begin()+y2);
	for(int i = y2; i < data[x2].size(); i++){
		data[x2].erase(data[x2].begin()+i);
		i--;
	}
}

int main(){
	int number;
	cin >> number;
	vector<vector<int>> boxes;
	for(int i = 0; i < number;i++){
		vector<int> toAdd;
		toAdd.push_back(i);
		boxes.push_back(toAdd);
	}
	string inst1,inst2;
	int a,b;
	int lul = 0;
	while(cin >> inst1 >> a >> inst2 >> b){
		bool ans = valid(boxes,a,b);
		if(ans){
			//cout << "paso aqui" << endl;
			if(inst1.compare("move") == 0){
				if(inst2.compare("onto") == 0)
					moveOnto(boxes,a,b);
				if(inst2.compare("over") == 0)
					moveOver(boxes,a,b);
			}
			else{
				//cout << "aqui2" << endl;
				if(inst2.compare("onto") == 0){
					//cout << "aqui3" << endl;
					pileOnto(boxes,a,b);
				}
				if(inst2.compare("over") == 0)
					pileOver(boxes,a,b);
			}
		}
		//cout << inst1 <<" " <<a << " "<<inst2 <<" "<< b << endl;
		//cout << "LUKLLLLLL " << lul << endl;
		//printArr(boxes);
		//lul++;
	}
	for(int i = 0; i< number;i++){
		cout << i << ":";
		for(int j = 0; j < boxes[i].size(); j++){
			cout << " " << boxes[i][j];
		}
		cout << endl;
	}
	return 0;
}