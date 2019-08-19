/**
* I'm an idiot
*/
#include<iostream>

using namespace std;

int main(){
	bool first = true;
	while(true){
		int val;
		cin >> val;
		if(val == 0)
			break;
		if(!first)
			cout << endl;
		bool paso = false;
		for(int i = 1234; i <= 98765/val; i++){
			int ab = i * val;
			int counter = (i < 10000);
			int temp = ab; while(temp){counter |= 1 <<(temp%10);temp /= 10;}
			temp = i; while(temp){counter |= 1 << (temp%10);temp /= 10;}
			if(counter == (1<< 10) -1){
				cout << ab << " / ";
				if(i < 10000)
					cout << 0 << i;
				else
					cout << i;
				cout << " = " << val << endl;
				paso = true;
			}
		}
		if(!paso){
			cout << "There are no solutions for " << val << "." << endl;
		}
		first = false;
	}
	return 0;
}