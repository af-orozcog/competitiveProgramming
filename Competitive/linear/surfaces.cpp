#include<iostream>
#include<string>

using namespace std;

int main(){
	while(true){
		int val;
		cin >> val;
		if(val == 0){
			break;
		}
		int space[val];
		int min = 27;
		for(int i = 0; i < val;i++){
			string value;
			cin >> value;
			if(value.size() < 25){
				string nex; 
				cin >> nex;
				value += nex;
			}
			int answer = value.size();
			answer = 25 - answer;
			space[i] = answer;
			if(answer < min)
				min = answer;
			//cout << i << endl;
		}
		int total = 0;
		for(int i = 0; i < val;i++){
			total += space[i] - min;
		}
		cout << total << endl;
	}
	return 0;
}