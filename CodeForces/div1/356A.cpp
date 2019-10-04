/**
* Hope this gonna be my first div1 solution
*/
#include<iostream>
#include<vector>
#define max(x,y)(x > y?x:y)

using namespace std;

class SegTree{
	private:
		vector<int> lo,hi,delta,marked;
		void prop(int i){
		    if(!marked[i<<1])
			    delta[i<<1] += delta[i];
			if(!marked[(i<<1)+1])
			    delta[(i<<1)+1] += delta[i];
			delta[i] = 0;
		}
		void increment(int i, int a, int b, int val){
			if(lo[i] > b  || hi[i] < a)
				return;
			if(marked[i])
				return;
			if(lo[i] >= a && hi[i] <= b){
				marked[i] = 1;
				delta[i] += val;
				return;
			}

			increment(i << 1,a,b,val);
			increment((i<<1)+1,a,b,val);
		} 
		int query(int i, int a, int b){
			if(lo[i] > b || a > hi[i])
				return -1;
			if(lo[i] >= a && hi[i] <= b)
				return delta[i];
			prop(i);
			int l = query(i<<1,a,b);
			int r = query((i<<1)+1,a,b);
			return max(l,r);
		}
		void init(int i,int a,int b){
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
			lo.assign((n<<2)+1,0);
			hi.assign((n<<2)+1,0);
			delta.assign((n<<2)+1,0);
			marked.assign((n<<2)+1,0);
			init(1,0,n-1);
		}
		void increment(int a,int b, int val){
			increment(1,a,b,val);
		}
		int query(int a,int b){
			return query(1,a,b);
		}
};

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	SegTree myTree(n);
	while(m--){
		int l,r,v;
		scanf(" %d %d %d",&l,&r,&v);
		--l;--r;--v;
		int neR1 = v-1;
		int neL1 = v+1;
		if(neR1 >= l)
			myTree.increment(l,neR1,v+1);
		if(neL1 <= r)
			myTree.increment(neL1,r,v+1);
 	}
 	for(int i = 0; i < n;++i)
 		printf("%d ",myTree.query(i,i));
 	puts("");
 	return 0;
}