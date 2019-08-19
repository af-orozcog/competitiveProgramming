#include<iostream>
#include<bitset>
#include<map>

using namespace std;

int main(){
	bitset<200000> bi;
	int n,m;
	cin >> n >> m;
	map<int,bool> w;
	bool posi = true;
	for(int i = 0; i < m; ++i){
		int a,b;
		cin >> a >> b;
		--a;--b;
		if(w.count(a) == 0 && w.count(b) == 0){
			w[a] = true;
			w[b] = false;
			bi.set(i,1);
		}
		else if(w.count(a) && w.count(b)){
			if(w[a] == w[b]){
				posi = false;
				break;
			}
			if(w[a])
				bi.set(i,1);
			else
				bi.set(i,0);
		}
		else if(w.count(a)){
			if(w[a]){
				bi.set(i,1);
				w[b] = false;
			}
			else{
				bi.set(i,0);
				w[b] = true;
			}
		}
		else{
			if(w[b]){
				bi.set(i,0);
				w[a] = false;
			}
			else{
				bi.set(i,1);
				w[a] = true;
			}
		}
	}
	if(!posi)
		puts("NO");
	else{
		puts("YES");
		for(int i = 0; i < m;++i){
			cout << bi[i];
		}
		cout << endl;
	}
	return 0;
}