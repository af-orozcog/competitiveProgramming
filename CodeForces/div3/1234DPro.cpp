/**
* This idea is beyond the limits of coolness,
* Thanks to Camilo Bages
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class SegTree{
	private:
	vector<int> hi,lo,dif;

	void update(int i){
		dif[i] = dif[i*2] | dif[i*2+1];
	}
	void change(int i, int a, int b, int er, int in){
		if(b < lo[i] || a > hi[i])
			return;
		if(a <=lo[i]  && hi[i] <= b){
			dif[i] = dif[i] ^ er;
			dif[i] = dif[i] | in;
			return;
		}
		change(i*2,a,b,er,in);
		change(i*2+1,a,b,er,in);
		update(i);
	}

	void init(int i, int a,int b){
		lo[i] = a;
		hi[i] = b;
		if(a == b)
			return;
		int m = (a+b)>>1;
		init(i<<1,a,m);
		init((i<<1)+1,m+1,b);
	}

	public:

	SegTree(int n){
		hi.assign((n*4+1),0);
		lo.assign((n*4+1),0);
		dif.assign((n*4+1),0);

		init(1,0,n-1);
	}

	int query(int i, int a, int b){
		if(b < lo[i] || a > hi[i])
			return 0;
		if(a <= lo[i] && b >= hi[i])
			return dif[i];

		int le = query(i*2,a,b);
		int ri = query(i*2+1,a,b);
		update(i);
		return (le | ri); 
	}

	void change(int a,int b, int er, int in){
		change(1,a,b,er,in);
	}
};


int toNum(char val){
	int t = val -'a';
	return (1<<t);
}

int main(){
	string red;
	cin >> red;
	SegTree myTree(red.size());
	for(int i = 0; i < red.size();++i)
		myTree.change(i,i,0,toNum(red[i]));
	int q;
	scanf(" %d",&q);
	while(q--){
		int t;
		scanf(" %d",&t);
		if(t == 1){
			int p; char ne;
			scanf(" %d %c",&p,&ne);
			--p;
			myTree.change(p,p,toNum(red[p]),toNum(ne));
			red[p] = ne;
		}
		else{
			int a,b;
			scanf(" %d %d",&a,&b);
			--a;--b;
			int check = myTree.query(1,a,b);
			int ans = 0;
			while(check){
				if(check & 1)
					++ans;
				check = check >> 1;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}