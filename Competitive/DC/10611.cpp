/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int siz;
	cin >> siz;
	vector<int> hei(siz);
	for(int i = 0; i < siz;++i){
		cin >> hei[i];
	}
	int que;
	cin >> que;
	while(que--){
		int val;
		cin >> val;
		vector<int>::iterator low = lower_bound(hei.begin(),hei.end(),val);
		vector<int>::iterator up = upper_bound(hei.begin(),hei.end(),val);
		int founds = -1;
		int less = low - hei.begin();
		if(less == hei.size()) --less;
		//cout << less es: " << less << endl;
		while(less != -1 && hei[less] >= val){--less;}
		//cout << "less es: " << less << endl;
		if(less != -1)
			founds = hei[less];
		int foundu = -1;
		if(up != hei.end())
			foundu = hei[up - hei.begin()];
		if(founds == -1)
			cout << "X ";
		else
			cout << founds << " ";
		if(foundu == -1)
			cout << "X \n";
		else
			cout << foundu << "\n";
	}
	return 0;
}