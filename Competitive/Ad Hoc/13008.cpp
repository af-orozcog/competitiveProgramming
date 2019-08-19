#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

int main(){
	int D,P,R,B;
	cin >> D >> P >> R >> B;
	vector<int> memD(D);
	vector<int> memP(P);
	for(int i = 0; i < D;++i){
		cin >> memD[i];
	}
	for(int i = 0; i < P;++i){
		cin >> memP[i];
	}
	int max = std::numeric_limits<int>::max();
	cout << max << endl;
	map<int,vector<int>> enemiesDP;
	map<int,vector<int>> enemiesPP;
	for(int i = 0; i < R;++i){
		int val1,val2;
		cin >> val1 >> val2;
		enemiesDP[val1-1].push_back(val2-1);
		enemiesPP[val2-1].push_back(val1-1);
	}
	sort(memD.begin(),memD.end());
	sort(memP.begin(),memP.end());
	vector<int> checkLater;
	int co = B;
	for(int i = 0; i < memP.size();++i){
		if()
	}
}