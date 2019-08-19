/**
* Lo hago por Valentina, para ser mejor y para llegar a Moscú
*/
#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;

int main(){
	int cas;
	cin >> cas;
	for(int i = 0; i < cas; i++){
		int minNums = 10001;
		vi all;
		int places;
		cin >> places;
		cin.ignore();
		for(int j = 0; j < places;++j){
			string numbers;
			getline(cin,numbers);
			int many = 0;
			for(int e = 0; e < numbers.size();e++){
				if(numbers[e] == ' ')
					many++;
			}
			if(many == minNums)
				all.push_back(j+1);
			if(many < minNums){
				minNums = many;
				vi ne;
				all = ne;
				all.push_back(j+1);
			}
		}
		for(int j = 0; j < all.size();j++){
			if(j == 0)
				cout << all[j];
			else
				cout << " " << all[j];
		}
		cout << endl;
	}
	return 0;
}