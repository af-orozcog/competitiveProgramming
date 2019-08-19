/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<string>

using namespace std;

int main(){
	int siz;
	cin >> siz;
	string read;
	cin >> read;
	int dele = 0;
	for(int i = 0; i < read.size();++i){
		if((i+1) & 1){
			if(i+1 < read.size() && read[i+1] == read[i]){
				read.erase(read.begin() + i + 1);
				--i;
				++dele;
			}
		}
	}
	if(read.size() & 1){
		read.erase(read.begin() + read.size() -1);
		++dele;
	}
	cout << dele<< endl;
	cout << read << endl;
}