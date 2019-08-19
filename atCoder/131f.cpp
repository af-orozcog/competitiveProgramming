/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<map>

using namespace std;

int main(){
	map<int,bool> disA;
	map<int,bool> disB;
	int many;
	cin >> many;
	int co = many;
	while(co--){
		int val1, val2;
		cin >> val1 >> val2;
		disA[val1] = true;
		disB[val2] = true;
	}
	if(many < 3){
		cout << 0 << endl;
	}
	else{
		int toCheck = disA.size() * disB.size();
		cout << toCheck - many << endl;
	}
	return 0;
}