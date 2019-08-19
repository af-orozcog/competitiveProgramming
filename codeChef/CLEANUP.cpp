/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<bitset>
#include<vector>

using namespace std;
bitset<1000> jobs;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		jobs.set();
		int total,done;
		cin >> total >> done;
		while(done--){
			int val;
			cin >> val;
			jobs.set(val-1,0);
		}
		vector<int> che;
		vector<int> asi;
		int i = 0;
		int turn = 0;
		while(i < total){
			if(turn == 0 && jobs[i]){
				che.push_back(i+1);
				turn = 1;
			}
			else if(turn && jobs[i]){
				asi.push_back(i+1);
				turn = 0;
			}
			++i;
		}
		for(int i = 0; i < che.size();++i){
			if(i == 0)
				cout << che[i];
			else
				cout << " " << che[i];
		}
		cout << endl;
		for(int i = 0; i < asi.size();++i){
			if(i == 0)
				cout << asi[i];
			else
				cout << " " << asi[i];
		}
		cout << endl;
	}
}