/**
* Lo hago por Valentina, para ser mejor y para llegar a Moscú
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef vector<int> vi;

vi numbers(50001);
vi ranks(50001);

void sett(int m){
	for(int i = 0; i < m;i++){
		numbers[i] = i;
		ranks[i] = i;
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

int different(int m){
	map<int,bool> vals;
	for(int i = 0; i < m; i++){
		vals[search(i)] = true;
	}
	return vals.size();
}
int main(){
	int stud,par;
	int i = 0;
	while(true){
		++i;
		cin >> stud >> par;
		sett(stud);
		if(stud == 0)
			break;
		while(par--){
			int a,b;
			cin >> a >> b;
			connect(a-1,b-1);
		}
		cout << "Case " << i <<": " << different(stud) << endl; 
	}
	return 0;
}