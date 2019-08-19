#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
bool possible(string a){
	for(int i = 1; i < a.size(); i++){
		if(a[i] > a[i-1])
			return true;
	}
	return false;
}

int main(){
	while(true){
		string base;
		cin >> base;
		if(base[0] == '#')
			break;
		string copy = "c";
		copy = base;
		bool pos = possible(copy);
		if(pos){
			next_permutation(copy.begin(),copy.end());
			cout << copy << endl;
		}
		if(!pos)
			cout << "No Successor" << endl;
	}
}