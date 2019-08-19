/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<string>
#include<vector>
#define max(x,y)(x > y?x:y)

using namespace std;

int main(){
	int cas;
	cin >> cas;
	bool fi = true;
	while(cas--){
		if(!fi)
			cout << endl;
		vector<string> ones;
		string first;
		cin >> first;
		ones.push_back(first);
		for(int i = 0;i < first.size()-1;++i){
			string read;
			cin >> read;
			ones.push_back(read);
		}
		int matrix[first.size()][first.size()];
		int siz = first.size();
		for(int i = 0; i < siz;++i){
			for(int j = 0; j < siz;++j){
				int sum;
				if(ones[i][j] == '0')
					sum = -25*25;
				else
					sum = 1;
				if(i != 0)
					sum += matrix[i-1][j];
				if(j != 0)
					sum += matrix[i][j-1];
				if(i != 0 && j!= 0)
					sum -= matrix[i-1][j-1];
				matrix[i][j] = sum;
			}
		}
		int ans = 0;
		for(int i = 0; i < siz;++i){
			for(int j = 0; j < siz;++j){
				for(int m = i; m < siz;++m){
					for(int n = j; n < siz;++n){
						int sum = matrix[m][n];
						if(i != 0)
							sum -= matrix[i-1][n];
						if(j != 0)
							sum -= matrix[m][j-1];
						if(i != 0 && j != 0)
							sum += matrix[i-1][j-1];
						ans = max(ans,sum);
					}
				}
			}
		}
		cout << ans << endl;
		fi = false;
	}
	return 0;
}