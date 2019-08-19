#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> ans;
	int actL,actH,actR;
	while(cin >> actL >> actH >> actR){
		ans.push(actL);
		ans.push(actH);
		ans.push(actR);
	}
	vector<int> rans;
	for(int i = 0; i < ans.size(); i += 3){
		int L = ans[i];
		int H = ans[i+1];
		int R = ans[i+2];
		while(true){
			int co = 
		}
	}
}