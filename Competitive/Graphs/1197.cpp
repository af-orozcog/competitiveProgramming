/**
* Lo hago por Valentina, para ser mejor y para llegar a Moscú
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

typedef vector<int> vi;

vi numbers (30000,0);
vi ranks (30000,1);

void sett(int m){
	for(int i = 0; i < m; ++i){
		numbers[i] = i;
		ranks[i] = 1;
	}
}

int search(int m){
	return (numbers[m] == m) ? m : (numbers[m] = search(numbers[m]));
}

bool connected(int n, int m){
	return search(m) == search(n);
}

void connect(int n, int m){
	if(!connected(n,m)){
		int x = search(n),y = search(m);
		if(ranks[x] > ranks[y])
			numbers[y] = x;
		else{
			numbers[x] = y;
			if(ranks[x] == ranks[y]) ranks[y]++;
		}
	}
}


int main(){
	int stud,gro;
	while(true){
		cin >> stud >> gro;
		if(stud == gro && gro == 0)
			return 0;
		if(gro == 0){
			cout << 1 << endl;
			continue;
		}
		sett(stud);
		map<int,bool> unique;
		unique[0] = true;
		for(int i = 0; i < gro; ++i){
			int val;
			cin >> val;
			int first;
			cin >> first;
			unique[first] = true;
			for(int j = 0; j < val - 1; ++j){
				int vals;
				cin >> vals;
				connect(vals,first);
				unique[vals] = true;
			}
		}
		int counter = 0;
		for(auto const &x : unique){
			if(connected(x.first,0)){
				counter++;
				//cout << "x :"<< x.first << endl;
			}
		}
		cout << counter << endl;
	}
	return 0;
}