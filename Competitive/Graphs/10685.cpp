/**
* I'm a loser
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;
typedef vector<int> vi;

vi numbers(5001);
vi ranks(5001);


void sett(int m){
	for(int i = 0; i < m; i++){
		numbers[i] = i;
		ranks[i] = 1;
	}
}

int search(int m){
	return (numbers[m] == m) ? m : (numbers[m] = search(numbers[m]));
}

bool connected(int m, int n){
	return search(m) == search(n);
}

void connect(int m, int n){
	if(!connected(m,n)){
		int x = search(m), y = search(n);
		if(ranks[x] > ranks[y]){
			numbers[y] = x;
		}
		else{
			numbers[x] = y;
			if(ranks[y] == ranks[x]) ranks[y]++;
		}
	}
}
int bigConnected(int big){
	sort(numbers.begin(),numbers.begin()+big);
	int val = numbers[0];
	int manVal = 1;
	int otVal = numbers[0];
	int otManVal = 1;
	for(int i = 1; i < big;i++){
		if(numbers[i] == otVal){
			otManVal++;
		}
		else{
			otVal = numbers[i];
			otManVal = 1;
		}
		if(otManVal > manVal){
			val = otVal;
			manVal = otManVal;
		}
	}
	return manVal;
}


int main(){
	int ani,nec;
	while(true){
		map<string,int> trans;
		int counter = 0;
		cin >> ani >> nec;
		if(ani == 0 && nec == 0){
			return 0;
		}
		sett(ani);
		while(ani--){
			string name;
			cin >> name;
			trans[name] = counter++;
		}
		while(nec--){
			string one,two;
			cin >> one >> two;
			connect(trans[one], trans[two]);
		}
		for(int i = 0; i< counter;i++){
			search(i);
		}
		cout << bigConnected(counter) << endl;
	}
	return 0;
}