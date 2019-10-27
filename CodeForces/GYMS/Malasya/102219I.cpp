/**
* I only hope everything will be back to normal
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;

int main(){
	string line1,line2,line3;
	cin >> line1 >> line2 >> line3;
	vector<string> poss = {line1,line2,line3};
	int pos = -1;
	int lin;
	for(int i = 0; i < line1.size() && pos == -1;++i){
		if(line1[i] == '='){
			pos = i;lin = 0;
		} 
		if(line2[i] == '='){
			pos = i;lin = 1;
		}
		if(line3[i] == '='){
			pos = i;lin = 2;
		}
	}
	char obs = '.';
	for(int i = pos+1; i < line1.size() && obs == '.';++i){
		if(poss[lin][i] != '.')
			obs = poss[lin][i];
	}
	if(obs == '.')
		puts("You shall pass!!!");
	else
		printf("%c\n",obs);
	return 0;
}