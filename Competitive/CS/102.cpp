/**
* I'm an idiot
*/
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int a1,a2,a3,a4,a5,a6,a7,a8,a9;
	while(cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >>a9){
		char let[] = {'B','C','G'};
		int min = 2147483647;
		string ans = "";
		do{
			int val = 0;
			if(let[0] == 'B'){
				val += a4 + a7;
				if(let[1] == 'C')
					val += a3 + a9;
				if(let[1] == 'G')
					val += a2 + a8;
				if(let[2] == 'G')
					val += a5 + a2;
				if(let[2] == 'C')
					val += a3 + a6;
			}

			if(let[0] == 'C'){
				val += a6 + a9;
				if(let[1] == 'G')
					val += a2 + a8;
				if(let[1] == 'B')
					val += a1 + a7;
				if(let[2] == 'B')
					val += a1 + a4;
				if(let[2] == 'G')
					val += a5 + a2;
			}

			if(let[0] == 'G'){
				val += a5 + a8;
				if(let[1] == 'B')
					val += a1 + a7;
				if(let[1] == 'C')
					val += a3 + a9;
				if(let[2] == 'C')
					val += a3 + a6;
				if(let[2] == 'B')
					val += a1 + a4;
			}
			if(val < min){
				min = val;
				ans = let[0];  
				ans += let[1];
				ans += let[2];
			}

		}
		while(next_permutation(let,let+3));
		cout << ans << " " << min << endl;
	}
	return 0;
}