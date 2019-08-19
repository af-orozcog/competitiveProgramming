#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
void blanks(int siz){
	for(int i = 0; i < siz; i++){
		cout << " ";
	}
}

void printer(vector<string> data, int columns, int siz){
	//cout << "siz es: " << siz << endl;
	int rows = ceil((double)data.size()/(double)columns);
	cout << "------------------------------------------------------------"<< endl;
	for(int i = 0; i < rows;i++ ){
		int k = 0;
		for(int j = i; j < data.size()&& k < columns; j+= rows){
			if(j+rows < data.size() && j != data.size()-1)
			{
				cout<< data[j];
				blanks(siz - data[j].size());
			}
			else{
				//cout << siz-2-data[j].size() << endl;
				//cout << "entro" <<endl;
				cout<< data[j]; //<< " entro " << siz<< " "<< siz-2-data[j].size();
				blanks(siz-2-data[j].size());
			}
			k++;
			//cout << "las columnas son:" << columns << " y el k es:" << k << endl;
		}
		cout << endl;
	}
}

int main(){
	int num;
	while(cin >> num){
		vector<string> names;
		int biggest = 0; 
		for(int i = 0; i < num;i++){
			string val;
			cin >> val;
			if(val.size()> biggest)
				biggest = val.size();
			names.push_back(val);
		}
		sort(names.begin(),names.end());
		//if((double)60/(double)(biggest+2)-(double)(60/(biggest + 2)) == 0.5)
		//	printer(names,ceil((double)60/(double)(biggest+2)),biggest+2);
		//else
		int num = 60 - biggest;
		printer(names,floor((double)num/(double)(biggest+2))+1,biggest+2);
	}
}