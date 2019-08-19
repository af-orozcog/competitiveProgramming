#include<vector>
#include<iostream>

using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

vi values(100000);
vi st(400001);
vi ranges;
int left(int x){return x << 1;}
int right(int x){return (x << 1) + 1;}


void build(int po, int L, int R){
	if(L == R)
		st[po] = values[L];
	
	else{
		build(left(po), L, (L+R)/2);
		build(right(po), (L+R)/ 2 + 1,R);
		int posi1 = st[left(po)], posi2 = st[right(po)];
		if(posi1 > posi2)
			st[po] = posi1;
		else
			st[po] = posi2;
	}
}
int FMQ(int po,int L, int R, int i, int j){
	if(i > R || j < L) return -1;
	if(L >= i && L <= j) return st[po];

	int posi1 = FMQ(left(po), L,(L+R)/2, i, j);
	int posi2 = FMQ(right(po), (L+R) / 2 + 1, R, i,j);

	if(posi1 == -1) return posi2;
	if(posi2 == -1) return posi1;
	if(posi1 > posi2) return posi1;
	return posi2;
}

void sett(int fo,int to, int val){
	for(int i = fo; i <= to;i++){
		values[i] = val;
	}
}
int main(){
	while(true){
		int ele,que;
		cin >> ele;
		if(ele == 0){
			break;
		}
		cin >> que;
		int va;
		cin >> va;
		int num = 1;
		values[0] = num;
		int from = 0;
		for(int i = 1; i < ele;i++){
			int val;
			cin >> val;
			if(val == va)
				num++;
			else{
				sett(from,i-1,num);
				ranges
				va = val;
				num = 1;
				from = i;
			}
		}
		sett(from,ele-1,num);
		build(1,0,ele-1);
		for(int i = 0; i < que;i++){
			int val1,val2;
			cin >> val1 >> val2;
			int ans = FMQ(1,0,ele-1,val1-1,val2-1);
			cout << ans << endl;
		}
	}
	return 0;
}