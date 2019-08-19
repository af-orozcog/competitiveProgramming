/**
* I'm sorry I was an idiot
*/
#include<iostream>
#include<string>
#define ll long long

using namespace std;

int main(){
	while(true){
		ll left[] = {0,1};
		ll right[] = {1,0};
		ll start[] = {1,1};
		ll first, second;
		cin >> first >> second;
		if(first == second && first == 1)
			break;
		string answer = "";
		while(start[0] != first || start[1] != second){
			if(first * start[1] < second * start[0]){
				right[0] = start[0];
				right[1] = start[1];
				start[0] = start[0] + left[0];
				start[1] = start[1] + left[1];
				answer += "L";
			}
			else{
				left[0] = start[0];
				left[1] = start[1];
				start[0] = start[0] + right[0];
				start[1] = start[1] + right[1];
				answer += "R";
			}
		}
		cout << answer << endl;
	}
	return 0;
}