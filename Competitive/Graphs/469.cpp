/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

bool map[99][99];

int diX[] = {0,0,1,-1,1,1,-1,-1};
int diY[] = {1,-1,0,0,-1,1,-1,1};

int CC(int x,int y){
	if(x < 0 || x >= 99 || y < 0 || y >= 99)
		return 0;
	if(!map[x][y])
		return 0;
	map[x][y] = false;
	int ans = 1;
	for(int i = 0; i < 8;++i){
		ans += CC(x+diX[i],y+diY[i]);
	}
	return ans;
}

int main(){
	int que;
	cin >> que;
	//cin.ignore();
	string qe;
	getline(cin,qe);
	bool first = true;
	while(que--){
		if(!first)
			cout << endl;
		memset(map,false,sizeof(map));
		string l;
		int N = 0;
		while(getline(cin,l)){
			if(l.size() == 0){
			//	cout <<"here?"<<endl;
				continue;
			}
			if(l[0] != 'L' && l[0] != 'W'){
				break;
			}
			for(int i = 0; i < l.size();++i){
				map[N][i] = (l[i] == 'W'?true:false);
				//cout << "N es " << N << endl;
			}
			++N;
			//cout << "nunca"<<endl;
		}
		//cout << "pasa aqui?" << endl;
		int num1 = -1,num2=-1;
		//cout << " l es " << l <<endl;
		string a = "";
		for(int i = 0; i < l.size();++i){
			if(l[i] != ' '){
				a += l[i];
			}
			else{
				num1 = stoi(a);
				a = "";
			}
		//	cout <<" a es "<< a << endl;
		}
		bool co[99][99];
		memcpy(co,map,sizeof(map));
		num2 = stoi(a);
		cout << CC(num1-1,num2-1) << endl;
		while(getline(cin,l)){
			memcpy(map,co,sizeof(co));
			if(l.size() == 0)
				break;
			num1 = -1;num2= -1;
			a = "";
			for(int i = 0; i < l.size();++i){
				if(l[i] != ' '){
					a += l[i];
				}
				else{
					num1 = stoi(a);
					a = "";
				}
			}
			num2 = stoi(a);
			cout << CC(num1-1,num2-1) << endl;
		}
		first = false;
	}
	return 0;
}