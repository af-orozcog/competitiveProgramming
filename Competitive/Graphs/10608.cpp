/**
* Lo hago por Valentina, para ser mejor y para llegar a Moscú
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> vi;

vector<int> numbers(1000000,0);

vector<int> ranks(1000000,0);

void sett(int m){
	for(int i = 0; i < m;i++){
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
		int x = search(m),y = search(n);
		if(ranks[x] > ranks[y]){
			numbers[y] = x;
		}
		else{
			numbers[x] = y;
			if(ranks[x] == ranks[y]) ranks[y]++;
		}
	}
}

int maximum(int siz){
	sort(numbers.begin(),numbers.begin()+(siz-1));
	int val = numbers[0];
	int man = 1;
	int tempVal = numbers[0];
	int tempMan = 1;
	for(int i = 1; i < siz;i++){
		if(numbers[i] == tempVal){
			tempMan++;
		}
		else if(numbers[i] != tempVal){
			tempVal = numbers[i];
			tempMan = 1;
		}
		if(tempMan > man){
			val = tempVal;
			man = tempMan;
		}
	}
	return man;
}

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		int pep,pa;
		cin >> pep >> pa;
		sett(pep);
		while(pa--){
			int x,y;
			cin >> x >> y;
			connect(x-1,y-1);
		}
		for(int i = 0; i < pep; i++){
			search(i);
		}
		cout << maximum(pep) << endl;
	}
	return 0;
}