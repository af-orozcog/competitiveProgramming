#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vi numbers(27,0);
vi ranks(27,0);
map<char,int> translator;
char letters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void sett(int m){
	for(int i = 0; i < m; i++){
		numbers[i] = i;
		ranks[i] = 1;
		translator[letters[i]] = i;
	}
}

int search(int m){
	return (numbers[m] == m) ? m : (numbers[m] = search(numbers[m]));
}

bool connected(int m, int n){
	return search(m) == search(n);
}

void connect(int m, int n){
    cout << m <<" " <<  n << endl;
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

bool areAllAwake(vector<set<int>> toSee, int compare){
	for(int i = 0; i < toSee.size();i++){
		if(toSee[i].size() != 0 && !connected(i,compare))
			return false;
	}
	return true;
}

void sett2(vector<set<int>> &vertices,int m, int on){
	for(int i = 0; i < m; i++){
		if(!connected(i,on)){
			for(int j = 0; j < m;j++){
				if(i != j && !connected(j,on))
					vertices[i].insert(j);
			}
		}	
	}
}
int main(){
	int slep;
	while(cin >> slep){
		int counter = 0;
		int con;
		cin >> con;
		vector<set<int>> vertices(26);
		sett(26);
		string awa;
		cin >> awa;
		if(translator.count(awa[0]) == 0){
			translator[awa[0]] = slep++;
		}
		if(translator.count(awa[1]) == 0){
			translator[awa[1]] = slep++;
		}
		if(translator.count(awa[2]) == 0){
			translator[awa[2]] = slep++;
		}
		connect(translator[awa[0]],translator[awa[1]]);
		connect(translator[awa[1]],translator[awa[2]]);
		int on = search(translator[awa[0]]);
		sett2(vertices,slep,on);
		//cout << "on es: " << on << endl;
		for(int i = 0; i < con;i++){
			string val;
			cin >> val;
			if(translator.count(val[0]) > 0){
				if(translator.count(val[1]) > 0){
					vertices[translator[val[0]]].insert(translator[val[1]]);
				}
				else{
					translator[val[1]] = counter++;
					vertices[translator[val[0]]].insert(translator[val[1]]);
				}
				vertices[translator[val[1]]].insert(translator[val[0]]);
			}

			else{
				translator[val[0]] = counter++;
				if(translator.count(val[1]) > 0){
					vertices[translator[val[0]]].insert(translator[val[1]]);
				}
				else{
					translator[val[1]] = counter++;
					vertices[translator[val[0]]].insert(translator[val[1]]);
				}
				vertices[translator[val[1]]].insert(translator[val[0]]);
			}
		}
		int years = 0;
		bool posi = true;
		while(!areAllAwake(vertices,on)){
			years++;
			vi toMark;
			int ne = 0;
			for(int i = 0; i < slep; i++){
				if(!connected(i,on)){
					int cou = 0;
					//cout << "i es: " << i << "el valor de i es: " << search(i) << endl;
					for(int elem: vertices[i]){
					    //cout << "elemento : " << elem << endl; 
						if(connected(elem,on)){
							cou++;
							//cout << "elemento sumado: " << elem << endl; 
						}
						if(cou == 3){
						    cout << "entro aqui " << endl;
							toMark.push_back(i);
							ne++;
							break;
						}
					}
				}
			}
			if(ne == 0){
				posi = false;
				break;
			}
			for(int e = 0; e < toMark.size();e++){
				connect(toMark[e],on);
			}
		}
		if(posi)
			cout << "WAKE UP IN, " << years << ", YEARS" << endl;
		else
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
  	}
  	return 0;
}