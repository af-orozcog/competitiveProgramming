#include<iostream>

using namespace std;

int main(){
	int a = 0,b = 0,c = 0;
	for(int i = 9;  i < 100;++i){
		if(i % 3 == 0)
			++a;
		if( i % 3 == 1)
			++b;
		if(i % 3 == 2)
			++c;
	}
	cout << a <<" " <<b << " " << c << endl;
}