#include<iostream>
#include<string>

using namespace std;

int main(){
	string read;
	cin >> read;
	int numA = 0;
	for(int i = 0; i < read.size(); i++){
		if(read[i] == 'a')
			numA++;
	}
	int siz = read.size();
	if(numA > siz/2){
		cout << siz << endl;	
	}
	else{
		siz = (numA*2) - 2;
		cout << siz+1 << endl; 
	}
	return 0;
}