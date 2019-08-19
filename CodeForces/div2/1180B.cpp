/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool com1(const pair<int,int> a,const pair<int,int> b){
	return a.second < b.second;
}

int main(){
	int negative = 0;
	vector<pair<int,int>> positives;
	vector<pair<int,int>> negatives;
	int siz;
	cin >> siz;
	vector<int> answer(siz);
	for(int i = 0; i < siz;++i){
		int val;
		cin >> val;
		if(val < 0){
			negatives.push_back(make_pair(i,val));
			++negative;
		}
		else if(val > 0)
			positives.push_back(make_pair(i,val));
		else{
			val = -1;
			negatives.push_back(make_pair(i,val));
			++negative;
		}
		answer[i] = val;
	}
	sort(negatives.begin(),negatives.end(),com1);
	sort(positives.begin(),positives.end(),com1);
	int imp = siz - negative;
	if((imp == 1 && negative % 2 == 1) || (imp == 0 && siz % 2 == 1)){
		bool posi = false;
		for(int i = 0; i < negatives.size();++i){
			if(negatives[i].second != -1){
				answer[negatives[i].first] = (-answer[negatives[i].first]) - 1;
				posi = true;
				break;
			}
		}
		if(!posi){
			answer[negatives[0].first] = 0;
		}
	}
	else{
		if(imp % 2 != 0)
			imp -= 1;
		//cout << "entro aqui" << endl;
		for(int i = 0; i < imp;++i){
			//cout << answer[positives[i].first] << endl;
			answer[positives[i].first] = (-answer[positives[i].first]) - 1;
		}
	}
	for(int i = 0; i < answer.size();++i){
		if(i == 0)
			cout << answer[i];
		else
			cout << " "<< answer[i];
	}
	cout << endl;
	return 0;
}