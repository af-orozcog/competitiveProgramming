#include<iostream>
using namespace std;

int main()
{
	int tests; 
	cin >> tests;
	while(tests--){
		int val1,val2;
		cin >> val1 >> val2;
		if(val1%3 >= 1)
			val1 = val1 -(val1%3);
		if(val2%3 >= 1)
			val2 = val2 -(val2%3);
		cout <<  (val1*val2)/9 << endl;
	}
}