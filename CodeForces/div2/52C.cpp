#include<iostream>
#include<vector>
#define min(x,y)(x < y? x:y)
#include<string>
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


vector<int> bySpace(string &line){
	string temp = "";
	vector<int> ans;
	for(int i = 0; i < line.size();++i){
		if(line[i] == ' '){
			ans.push_back(stoi(temp));
			temp = "";
		}
		else
			temp += line[i];
	}
	ans.push_back(stoi(temp));
	return ans;
}

int main(){
	int n;
	scanf(" %d",&n);
	SegTree myTree(n);
	for(int i = 0; i < n;++i){
		int val;
		scanf(" %d",&val);
		myTree.increment(i,i,val);
	}
	int q;
	cin >> q;
	cin.ignore();
	while(q--){
		string line;
		getline(cin,line);
		vector<int> para = bySpace(line);
		if(para.size() == 3){
			int l = para[0],r = para[1],v = para[2];
			if(r < l){
				int neR = n-1,neL = 0;
				myTree.increment(l,neR,(ll)v);
				myTree.increment(neL,r,(ll)v);
			}
			else
				myTree.increment(l,r,(ll)v);
		}
		else{
			int l = para[0],r = para[1];
			if(r < l){
				int neR = n-1,neL = 0;
				ll one = myTree.query(l,neR);
				ll two = myTree.query(neL,r);
				cout << min(one,two) << endl;
			}
			else
				cout << myTree.query(l,r) <<endl;
		}
	}
	return 0;
}