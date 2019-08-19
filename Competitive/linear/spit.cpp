#include<iostream>

using namespace std;

int main(){
	while(true){
		unsigned int num;
		cin >> num;
		if(num == 0)
			break;
		unsigned int copy = num;
		unsigned int a = 0;
		unsigned int b = 0;
		int multi = 1;
		int last = 1;
		for(int i = 0; i < 32; i++){
			if(copy & 1){
				if(last){
					a = a | multi;
					last = 0;
				}
				else{
					b = b | multi;
					last = 1;
				}
			}
			copy = copy >> 1;
			multi = multi << 1;
		}
		cout << a << " " << b << endl;
	}
	return 0;
}