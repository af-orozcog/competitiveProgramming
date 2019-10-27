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

vector<vector<char>> rotRight(vector<vector<char>> &matrix, map<char,char> &trans){
	vector<vector<char>> ans(matrix.size(), vector<char>(matrix.size()));
	for(int i = 0; i < matrix.size();++i){
		for(int j = 0; j < matrix.size();++j){
			ans[j][matrix.size()-1-i] = trans[matrix[i][j]];
		}	
	}
	return ans;
}

vector<vector<char>> rotLeft(vector<vector<char>> &matrix, map<char,char> &trans){
	vector<vector<char>> ans(matrix.size(), vector<char>(matrix.size()));
	for(int i = 0; i < matrix.size();++i){
		for(int j = 0; j < matrix.size();++j){
			ans[matrix.size()-1-j][i] = trans[matrix[i][j]];
		}	
	}
	return ans;
}

int main(){
	int n;
	string rot;
	cin >> n >> rot;
	deque<char> finalMoves;
	for(int i = 0; i < rot.size();++i){
		if(finalMoves.size() == 0)
			finalMoves.push_back(rot[i]);
		else if(rot[i] != finalMoves.back())
			finalMoves.pop_back();
		else
			finalMoves.push_back(rot[i]);
	}
	map<char,char> trR,trL;
	trR['.'] = '.';trR['>'] = 'v';trR['^'] = '>';trR['v'] = '<';trR['<'] = '^';
	trL['.'] = '.';trL['v'] ='>';trL['>'] = '^';trL['<'] = 'v';trL['^'] = '<';
	vector<vector<char>> matrix(n, vector<char>(n));
	for(int i = 0; i < n;++i){
		for(int j = 0; j < n;++j)
			cin >> matrix[i][j];
	}
	int siz = finalMoves.size();
	siz = siz % 4;
	char move = finalMoves.front();
	for(int i = 0; i < siz;++i){
		if(move == 'R')
			matrix = rotRight(matrix,trR);
		else
			matrix = rotLeft(matrix,trL);
	}
	for(int k = 0; k < matrix.size();++k){
		for(int j = 0; j < matrix.size();++j)
			cout << matrix[k][j];
		cout << endl;
	}
	return 0;
}