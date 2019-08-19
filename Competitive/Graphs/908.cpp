#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int UF[1000000];
int rk[1000000];
void UFset(int n){
	for(int i = 0; i < n;++i){
		UF[i] = i;
		rk[i] = 1;
	}
}
int search(int x){
	return UF[x] == x ? x:(UF[x] = search(UF[x]));
}

bool connected(int x, int y){
	return search(x) == search(y);
}

void connect(int x, int y){
	int dadX = search(x),dadY = search(y);
	if(dadX != dadY){
		if(rk[dadX] > rk[dadY]){
			UF[dadY] = dadX;
		}
		else{
			UF[dadX] = dadY;
			if(rk[dadY] == rk[dadX]) ++rk[dadY];
		}
	}
}

int solve(vector<pair<int,pair<int,int>>> &edge){
	int ans = 0;
	sort(edge.begin(),edge.end());
	for(int i = 0; i < (int)edge.size();++i){
		int a = edge[i].second.first, b = edge[i].second.second;
		if(!connected(a,b)){
			connect(a,b);
			ans += edge[i].first;
		}
	}
	return ans;
}


int main(){
	int N;
	short first = 0;
	while(cin >> N){
		if(first)
			cout << endl;
		UFset(N);
		int ans1 = 0;
		vector<pair<int,pair<int,int>>> edge;
		for(int i = 0; i < N-1;++i){
			int a,b,c;
			cin >> a >> b >> c;
			ans1 += c;
		}
		cout << ans1 << endl;
		int k;
		cin >> k;
		while(k--){
			int a,b,c;
			cin >> a >> b >> c;
			--a;--b;
			edge.push_back(make_pair(c,make_pair(a,b)));
		}
		int M;
		cin >> M;
		while(M--){
			int a,b,c;
			cin >> a >> b >> c;
			--a;--b;
			edge.push_back(make_pair(c,make_pair(a,b)));
		}
		//cout << "exit?" << endl;
		cout << solve(edge) << endl;
		first = 1;
	}
	return 0;
}