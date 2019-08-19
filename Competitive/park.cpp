#include<iostream>
using namespace std;

int main(){
	int tests;
	cin >> tests;
	while(tests--){
		int shops;
		cin >> shops;
		int min = 100;
		int max = -1;
		while(shops--){
			int val;
			cin >> val;
			if(val < min)
				min = val;
			if(val > max)
				max = val;
		}
		int place = ((max - min)/2) + min;
		int distance = (place - min) * 2;
		distance += (max - place) * 2;
		cout << distance << endl;
	}
	return 0;
}