#include<iostream>
#include<bitset>

using namespace std;

int main(){
	int n,m;
	while(cin >> n >> m){
		if(n == 0 && m == 0){
			break;
		}
		bool print = true;
		bitset<1000000> free;
		for(int i = 0; i < n; i++){
			int start,end;
			cin >> start >> end;
			bool entro = false;
			for(int j = start+1; j < end && print;j++){
				if(free[j] == 1 && free[j-1]==1){
					cout << "CONFLICT" << endl;
					print = false;
					break;
				}
				free[j] = 1;
				entro = true;
			}
			if(!entro && free[end] == 1 && print){
				cout << "CONFLICT" << endl;
				print = false;
			}
			//cout << i << endl;
		}
		for(int i = 0; i < m; i++){
			int start,end,repe;
			cin >> start >> end >> repe;
			for(int j = 0; j < 1000000 && print; j+=repe){
				if(start + j >= 1000000)
					break;
				bool entro = false;
				for(int k = start+1+j; k < end+j && k < 1000000 && print;k++){
					if(free[k] && free[k-1]){
						cout << "CONFLICT" << endl;
						print = false;
						break;
					}
					free[k] = 1;
					entro = true;
				}
				if(end+j >= 1000000){
					if(!entro && free[end+j] == 1 && print){
						cout << "CONFLICT" << endl;
						print = false;
					}
				}
			}
			//cout << i << endl;
		}
		if(print)
			cout << "NO CONFLICT" << endl;
	}
	return 0;
}