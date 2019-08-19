#include<iostream>
#include<string>

using namespace std; 

int main(){
	string answer = "";
	for(int i = 1; i < 10001;i++){
		answer += to_string(i);
	}
	int que;
	cin >> que;
	cout << answer[que-1] << endl;
	return 0;
}