/**
* Lo hago por Valentina, para ser mejor y para llegar a Moscú
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef vector<int> vi;

vector<int> numbers(1000000,0);

vector<int> ranks(1000000,0);

void sett(int num){
	for(int i = 0; i < num; ++i){
		numbers[i] = i;
		ranks[i] = 1;
	}
}
int search(int m){
    //cout << "numbers[m] : "<< numbers[m] << " m es" << m << endl;
	return (numbers[m] == m) ? m : (numbers[m] = search(numbers[m]));
}
bool connected(int n, int m){
	return search(n) == search(m);
}
void connect(int n, int m){
	if(!connected(n,m)){
		int x = search(n);
		int y = search(m);
		//cout << "lil: " << numbers[x] << endl;
		//cout << "x es: " << x << " y es: "<< y << " n es " << n<<endl; 
		if(ranks[x] > ranks[y])
			numbers[y] = x;
		else{
			numbers[x] = y;
			if(ranks[x] == ranks[y]) ranks[y]++;
		}
	}
}

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		string lin;
		int suc,unsuc;
		suc = unsuc = 0;
		int com;
		cin >> com;
		sett(com);
		cin.ignore();
		while(true){
			getline(cin,lin);
			if(lin.size() == 0)
				break;
			if(lin[0] == 'c'){
				int i = 2;
				string val1 = "";
				while(lin[i] != ' '){
					val1 += lin[i++];
				}
				string val2 = "";
				++i;
				while(lin[i] != ' ' && lin[i] != '\0'){
					val2 += lin[i++];
				}
				int vall1,vall2;
				vall1 = stoi(val1);
				vall2 = stoi(val2);
				connect(vall1-1,vall2-1);
			}
			else{
				int i = 2;
				string val1 = "";
				while(lin[i] != ' '){
					val1 += lin[i++];
				}
				string val2 = "";
				++i;
				while(lin[i] != ' ' && lin[i] != '\0'){
					val2 += lin[i++];
				}
				int vall1,vall2;
				vall1 = stoi(val1);
				vall2 = stoi(val2);
				if(connected(vall1 - 1, vall2 -1))
					++suc;
				else
					++unsuc;
			}
		}
		cout << suc << "," << unsuc << endl;
		if(cas != 0)
			cout << endl;
	}
	return 0;
}