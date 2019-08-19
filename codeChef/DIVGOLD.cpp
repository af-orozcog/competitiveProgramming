/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
void exchange(int x, int y){
	char temp = toRead[x];
	toRead[x] = toRead[y];
	toRead[y] = temp;
}

string toRead;
int main(){
	int cas;
	cin >> cas;
	while(cas--){
		int val;
		cin >> val;
		cin >> toRead;
		string copy = toRead;
		string copy2 = copy;
		sort(copy.begin(),copy.end());
		cout << "ordered: "<< copy << endl;
	}
	return 0;
}