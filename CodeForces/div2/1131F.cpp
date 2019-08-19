#include<iostream>
#include<vector>

using namespace std;

int UF[150000];
int rk[150000];

void sett(int n){
	for(int i = 0; i < n;++i){
		UF[i] = i;
		rk[i] = 1;
	}
}

int search(int x){
	return (UF[x] == x) ? x: (UF[x] = search(UF[x])); 
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

int main(){
	int n;
	scanf(" %d",&n);
	sett(n);
	vector<vector<int>> nums(n);
	for(int i = 0; i < n;++i){
		nums[i].push_back(i);
	}
	for(int i = 0; i < n-1;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		--a;--b;
		int dadA = search(a),dadB = search(b);
		//cout << "lel" << endl;
		connect(a,b);
		//cout << "lil" << endl;
		int dadAn = search(a);
		int to;
		int from;
		if(dadAn == dadA){
			to = dadA;
			from = dadB;
		}
		else{
			to = dadB;
			from = dadA;
		}
		//cout << from << endl;
		//cout << to << endl;
		for(int i = 0; i < nums[from].size();++i)
			nums[to].push_back(nums[from][i]);
	}
	int dad = search(0);
	for(int i = 0; i < n;++i){
		if(i == 0)
			printf("%d",nums[dad][i]+1);
		else
			printf(" %d",nums[dad][i]+1);
	}
	puts("");
	return 0;
}