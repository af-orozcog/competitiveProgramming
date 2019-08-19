/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

void construct(vector<int> &a,vector<int> &P, int start){
	int x = start;
	stack<int> ans;
	for(;P[x] >= 0;x = P[x]) ans.push(a[x]);
	//cout << "here?" << endl;
	cout << a[x] << endl;
	while(ans.size()){
		cout << ans.top()<<endl;
		ans.pop();
	} 
}

bool com(const int a, const int b){
	return a < b;
}

int main(){
	vector<int> seque;
	int val;
	while(cin >> val){
		seque.push_back(val);
	}
	int added = 0;
	int last = 0;
	vector<int> lis(seque.size(),-1);
	vector<int> lis_id(seque.size());
	vector<int> P(seque.size());
	//cout << "size es: " << seque.size();
	for(int i = 0;i < seque.size();++i){
		vector<int>::iterator low = lower_bound(lis.begin(),lis.begin()+added,seque[i],com);
		int index = low - lis.begin();
		lis[index] = seque[i];
		lis_id[index] = i;
		P[i] = index ? lis_id[index-1]:-1;
		if(index + 1 > added){
			added = index + 1;
			last = i;
		}
		else if(index +1 == added)
		    last = i;
	}
	cout << added << endl << "-" << endl;
	construct(seque,P,last);
	return 0;
}
