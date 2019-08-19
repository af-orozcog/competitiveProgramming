#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int cas;
	cin >> cas;
	while(cas--){
		int val;
		cin >> val;
		if(val == 1)
			printf("1\n");
		else if(val == 2)
			printf("2\n");
		else if(val == 3)
			printf("4\n");
		else{
			val = val - 3;
			int toPrint = 4 + 3*val;
			printf("%d\n",toPrint);
		}
	}
	return 0;
}