#include<iostream>
#include<vector>
#define ll long long

using namespace std;

class SegTree{
	private:
 
	vector<ll> lo,hi,delta,mini;
 
	void prop(int i){
		delta[i<<1] += delta[i];
		delta[(i<<1)+1] += delta[i];
		delta[i] = 0; 
	}
 
	void update(int i){
		mini[i] = min(mini[i<<1] +delta[i<<1],mini[(i<<1)+1] + delta[(i<<1)+1]); 
	}	
 
	void increment(int i, int a,int b, ll val){
		if(a > hi[i] || b < lo[i])
			return;
		if(a <= lo[i] && b >= hi[i]){
			delta[i] += val;
			return;
		}
 
		prop(i);
		increment(i<<1,a,b,val);
		increment((i<<1)+1,a,b,val);
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
 
	ll query(int i, int a, int b){
		if(a > hi[i] || b < lo[i])
			return 1000000000;
		if(a <= lo[i] && b >= hi[i])
			return mini[i] +delta[i];
 
		prop(i);
		ll le = query(i<<1,a,b);
		ll ri = query((i<<1)+1,a,b);
 
		update(i);
		return min(le,ri);
	}
	public:
	SegTree(int n){
		lo.assign((n<<2)+1,0);
		hi.assign((n<<2)+1,0);
		delta.assign((n<<2)+1,0);
		mini.assign((n<<2)+1,0);
 
		init(1,0,n-1);
	}
 
	void increment(int a,int b, ll val){
		increment(1,a,b,val);
	}
 
	ll query(int a, int b){
		return query(1,a,b);
	}
};

vector<int> depth


int main(){
	
}