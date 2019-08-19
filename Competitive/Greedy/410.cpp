/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
	int c,s;
	int cas = 1;
	while(cin >> c >> s){
		vector<int> spe(2*c);
		int i = 0;
		double ma = 0.0;
		for(;i < s; ++i){
			cin >> spe[i];
			ma += spe[i];
		}
		ma /= (double)c;
		for(;i < 2*c;++i){
			spe[i] = 0;
		}
		sort(spe.begin(),spe.end());
		vector<pair<int,int>> conta;
		double imb = 0;
		for(int i = 0; i < c;++i){
			conta.push_back(make_pair(spe[i],spe[2*c - 1 -i]));
			double sum = spe[i] + spe[2*c - 1 -i];
			imb += abs(sum - ma);
		}
		cout << "Set #" << cas << endl;
		for(int i = 0; i < conta.size();++i){
			cout << " " << i << ":";
			if(conta[i].first != 0)
				cout << " "<<conta[i].first;
			if(conta[i].second != 0)
				cout <<" " << conta[i].second;
			cout << endl;
		}
		printf("IMBALANCE = %.5f\n\n",imb);
		++cas;
	}
}