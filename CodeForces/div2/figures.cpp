/**
*for the team and валентина в
*/

#include<iostream>
#define ll long long
using namespace std;

int main(){
	ll answer = 0;
	int infinite = 0;
	int figures;
	cin >> figures;
	int last1 = -1;
	cin >> last1;
	int last2 = -1;
	cin >> last2;
	if(last1 == 1 && last2 == 2){
			answer+=3;
	}
	else if(last1 == 2 && last2 == 1){
		answer+=3;
	}
	else if(last1 == 1 && last2 == 3){
		answer+= 4;
	}
	else if(last1 == 3 && last2 == 1){
		answer += 4;
	}
	else if(last1 == 2 && last2 == 3){
		infinite = 1;
	}
	else if(last1 == 3 && last2 == 2){
		infinite = 1;
	}
	for(int i = 2; i < figures; i++){
		int fig;
		cin >> fig;
		if(last2 == 1 && fig == 2){
			answer+=3;
		}
		else if(last2 == 2 && fig == 1){
			answer+=3;
		}
		else if(last2 == 1 && fig == 3){
			answer+= 4;
		}
		else if(last2 == 3 && fig == 1){
			answer += 4;
		}
		else if(last2 == 2 && fig == 3){
			infinite = 1;
		}
		else if(last2 == 3 && fig == 2){
			infinite = 1;
		}
		if(last1 == 3 && last2 == 1 && fig == 2)
			answer--; 
		last1 = last2;
		last2 = fig;
	}
	if(infinite){
		cout << "Infinite" << endl;
	}
	else
		cout << "Finite" << endl << answer << endl;
	return 0; 
}